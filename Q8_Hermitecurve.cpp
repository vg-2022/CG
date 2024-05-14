#include <conio.h>
#include <graphics.h>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


struct point
{
  int x, y;
};

void hermite(point p1, point p4, double r1, double r4)
{
  float x, y, t;
  for (t = 0.0; t <= 1.0; t += 0.00005)
  {
    x = (2 * pow(t, 3) - 3 * pow(t, 2) + 1) * p1.x +
        (-2 * pow(t, 3) + 3 * pow(t, 2)) * p4.x +
        (pow(t, 3) - 2 * pow(t, 2) + t) * r1 +
        (pow(t, 3) - pow(t, 2)) * r4;
    y = (2 * pow(t, 3) - 3 * pow(t, 2) + 1) * p1.y +
        (-2 * pow(t, 3) + 3 * pow(t, 2)) * p4.y +
        (pow(t, 3) - 2 * pow(t, 2) + 1) * r1 +
        (pow(t, 3) - pow(t, 2)) * r4;
    putpixel(x, y, WHITE);
  }

  circle(p1.x, p1.y, 3);
  circle(p4.x, p4.y, 3);
}

int main()
{
  point p1, p4;
  double r1, r4;

  int gd = DETECT, gm;
  initgraph(&gd, &gm, "..\\BGI");

  cout << "Enter Point 1 (x, y): ";
  cin >> p1.x >> p1.y;
  cout << "Enter Point 2 (x, y): ";
  cin >> p4.x >> p4.y;
  cout << "Enter Tangent at Point 1: ";
  cin >> r1;
  cout << "Enter Tangent at Point 4: ";
  cin >> r4;

  hermite(p1, p4, r1, r4);

  getch();
  closegraph();
}

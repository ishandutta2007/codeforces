#include <cstdio>
#include <algorithm>

using namespace std;

const double INF = 1000005.0;

double Ccw(double x1, double y1, double x2, double y2, double x3, double y3)
{
  return x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
}

int main()
{
  int pocx, pocy, krajx, krajy;
  int rje=0;
  int n;

  scanf("%d%d%d%d", &pocx, &pocy, &krajx, &krajy);

  scanf("%d", &n);
  
  for (int i=0; i<n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); c *= -1;
    double x1, y1, x2, y2;
    if (!a) {
      x1 = -INF;
      x2 = INF;
      y1 = y2 = (double) c / b;
    }
    else if (!b) {
      y1 = -INF;
      y2 = INF;
      x1 = x2 = (double) c / a;
    }
    else {
      x1 = -INF;
      x2 = INF;
      y1 = (c - (double) x1 * a) / b;
      y2 = (c - (double) x2 * a) / b;
    }

    double c1, c2;
    
    c1 = Ccw(x1, y1, x2, y2, (double) pocx, (double) pocy);
    c2 = Ccw(x1, y1, x2, y2, (double) krajx, (double) krajy);

    if ((c1 < 0 && c2 > 0) || (c1 > 0 && c2 < 0))
      rje++;
  }

  printf("%d\n", rje);

  return 0;
}
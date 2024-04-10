#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;

double r, v, w;
double s;

int Moze(double t)
{
  double pozdol = v * t;
  double alfa2 = PI + w * t / 2;
  double alfa1 = 2 * PI - alfa2;

  return pozdol + 2 * r * abs(sin(alfa1)) > s;
}

int main()
{
  int q;

  scanf("%d%lf%lf", &q, &r, &v);
  w = v / r;

  for (; q; q--) {
    int poc, kraj;
    scanf("%d%d", &poc, &kraj);
    s = kraj - poc;

    double lo = 0, hi = 1e10;

    for (int i=0; i<100; i++) {
      double mid = (lo + hi) / 2;
      if (Moze(mid))
        hi = mid;
      else
        lo = mid;
    }
    
    printf("%.10lf\n", lo);
  }

  return 0;
}
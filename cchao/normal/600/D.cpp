#include <bits/stdc++.h>
using namespace std;
double intersectionArea(long double r1, long double r2, long double d) {
  if (r1 < r2) swap(r1, r2);
  if (d >= r1 + r2) return 0;
  if (d <= r1 - r2) return acos(-1) * r2 * r2;
  else {
    long double a1 = acos((r1*r1-r2*r2+d*d)/(2*d*r1));
    long double a2 = acos((r2*r2-r1*r1+d*d)/(2*d*r2));
    double ret = 0;
    ret += r2*r2*a2-0.5*r2*r2*sin(2*a2);
    ret += r1*r1*a1-0.5*r1*r1*sin(2*a1);
    return ret;
  }
}
int main() {
  int x1, y1, r1, x2, y2, r2;
  scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
  printf("%.12f\n", intersectionArea(r1, r2, hypotl(x1 - x2, y1 - y2)));
  return 0;
}
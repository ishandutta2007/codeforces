#include <bits/stdc++.h>
using namespace std;

int main() {
  double a, b;
  scanf("%lf%lf", &a, &b);
  int n;
  scanf("%d", &n);
  double ans;
  for (int i = 0; i < n; ++i) {
    double x, y, v;
    scanf("%lf%lf%lf", &x, &y, &v);
    double t = hypot(x - a, y - b) / v;
    if (t < ans || i == 0) ans = t;
  }
  printf("%.12f\n", ans);
  return 0;
}
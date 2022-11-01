#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  double h;
  cin >> n >> h;
  for (int i = 1; i < n; i++) {
    double ans = h * sqrt((double)i/n);
    printf("%.12lf\n", ans);
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  double l, v1, v2;
  cin >> n >> l >> v1 >> v2 >> k;
  int blocks = (n + k - 1) / k;
  double t = l / (v1 * blocks + (v2 - v1) / 2);
  double each = (v1 + v2) / 2 * t;
  cout << fixed << setprecision(12);
  cout << (l - each) / v1 + each / v2 << endl;
  return 0;
}
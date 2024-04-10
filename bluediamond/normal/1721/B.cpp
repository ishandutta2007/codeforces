#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n, m, x, y, d;
    cin >> n >> m >> x >> y >> d;
    cout << (((x - 1 > d && m - y > d) || (y - 1 > d && n - x > d)) ? (n + m - 2) : -1) << "\n";
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, n;

bool valid(int x) {
  return 1 <= x && x <= 2 * n;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {

    cin >> a >> b >> c;
    n = abs(a - b);
    if (c <= n) {
      d = c + n;
    } else {
      d = c - n;
    }
    if (valid(a) && valid(b) && valid(c) && valid(d)) {
      cout << d << "\n";
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}
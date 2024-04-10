#include <bits/stdc++.h>

using namespace std;

bool ok(int x, int l, int r, int a, int b) {
  if (a + b > 0 && l == x && x == r) {
    return 0;
  } else {
    return (l <= x - a + b && x - a + b <= r);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int x, y, r1, c1, r2, c2, a, b, c, d;
    cin >> a >> b >> c >> d >> x >> y >> r1 >> c1 >> r2 >> c2;
    if (ok(x, r1, r2, a, b) && ok(y, c1, c2, c, d)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

}
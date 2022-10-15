#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    ll x, y, m1, m2, c1, c2;
    cin >> x >> y >> m1 >> m2 >> c1 >> c2;
    if (c1 > c2) {
      swap(c1, c2);
      swap(m1, m2);
    }
    ll sol = 0;
    for (ll f = 0; f * c1 <= x && f <= m1; f++) {
      ll rem = x - f * c1;
      ll t = min(m2, rem / c2), t1 = t;
      ll cur = t + f;
      t = min(m1 - f, y / c1);
      cur += t;
      rem = y - t * c1;
      cur += min(m2 - t1, rem / c2);
      sol = max(sol, cur);
    }
    cout << sol << "\n";
  }
  return 0;
}
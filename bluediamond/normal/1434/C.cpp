#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, c, d;

ll eval(ll t) {
  return (t * d * b - a) * (t + 1) - t * (t + 1) / 2 * d * b;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d;
    if (b * c - a < 0) {
      cout << "-1\n";
      continue;
    }
    ll l = 0, r = c / d - 1, sol = min(eval(l), eval(r));
    while (l <= r) {
      ll m = (l + r) / 2;
      sol = min(sol, eval(m));
      sol = min(sol, eval(m + 1));
      if (eval(m) < eval(m + 1)) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    cout << -sol << "\n";
  }
}
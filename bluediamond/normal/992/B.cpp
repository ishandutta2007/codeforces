#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
typedef long double ld;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}


signed realMain() {
  int l, r, d, p;
  cin >> l >> r >> d >> p;
  if (p % d) {
    cout << "0\n";
    return 0;
  }
  p /= d;
  vector<pair<int, int>> potential;
  for (int x = 1; x * x <= p; x++) {
    if (p % x == 0) {
      potential.push_back({x, p / x});
      if (x * x != p) {
        potential.push_back({p / x, x});
      }
    }
  }
  int ret = 0;
  for (auto &it : potential) {
    if (l <= d * it.first && d * it.first <= r && l <= d * it.second && d * it.second <= r && __gcd(it.first, it.second) == 1) {
      ret++;
    }
  }
  cout << ret << "\n";
  return 0;
}
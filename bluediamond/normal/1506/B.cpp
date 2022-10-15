#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

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
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> p;
    for (int i = 0; i < n; i++) {
      if (s[i] == '*') p.push_back(i);
    }
    int sz = (int) p.size();
    vector<int> take(sz, 0);
    take[0] = take[sz - 1] = 1;
    int l = 0;
    while (p[sz - 1] - p[l] > k) {
      int r = l;
      while (p[r + 1] <= p[l] + k) {
        r++;
        assert(r < sz);
      }
      take[r] = 1;
      l = r;
    }
    int ret = 0;
    for (auto &x : take) {
      ret += x;
    }
    cout << ret << "\n";
  }
  return 0;
}
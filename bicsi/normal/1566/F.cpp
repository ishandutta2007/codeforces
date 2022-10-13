#include <bits/stdc++.h>
#define int long long 
 
using namespace std;
const int INF = 2e18;
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
 
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    sort(a.begin(), a.end());
    vector<pair<int, int>> b;
    for (int i = 0; i < m; ++i) {
      int l, r; cin >> l >> r;
      b.emplace_back(l, -r);
    }
    sort(b.begin(), b.end());
    vector<pair<int, int>> stk;
    for (auto [l, r] : b) {
      r = -r;
      auto it = lower_bound(a.begin(), a.end(), l);
      if (it != a.end() && *it <= r) continue;
      while (stk.size() && stk.back().second >= r)
        stk.pop_back();
      stk.emplace_back(l, r);
    }
    b = stk; m = b.size();
    
    vector<array<int, 2>> dp(n + 2, {INF, INF});
    dp[0] = {0, 0};
    int ptr = 0;
    for (int i = 0; i <= n; ++i) {
      int nptr = ptr;
      while (nptr < m && b[nptr].second < (i < n ? a[i] : 2e9))
        ++nptr;
 
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          for (int mid = ptr; mid <= nptr; ++mid) {
            if (i == 0 && mid != ptr) continue;
            if (i == n && mid != nptr) continue;
            int cl = (2 - j) * (mid == ptr ? 0 : b[mid - 1].first - a[i - 1]);
            int cr = (1 + k) * (mid == nptr ? 0 : a[i] - b[mid].second);
            dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + cl + cr);
          }
        }
      }
 
      ptr = nptr;
    }
    cout << min(dp[n + 1][0], dp[n + 1][1]) << '\n';
  }
  return 0;
}
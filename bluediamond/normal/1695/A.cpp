#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE



  int t;
  cin >> t;
  while (t--) {
    int n, m, mx = -((int) 1e9 + 7), r, c;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for (auto &v : a) {
      for (auto &x : v) {
        cin >> x;
        mx = max(mx, x);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == mx) {
          r = i;
          c = j;
        }
      }
    }
    cout << max(r + 1, n - r) * max(c + 1, m - c) << "\n";
  }
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main() {
 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  ///freopen ("___input___.txt", "r", stdin);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n, m, sum = 0;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      assert((int) s.size() == m);
      for (int j = 0; j < m; j++) {
        char ch = s[j];
        assert(ch == '0' || ch == '1');
        a[i][j] = ch - '0';
        sum += a[i][j];
      }
    }
    int mn = (int) 1e9 + 7;
    for (int i = 0; i + 1 < n; i++) {
      for (int j = 0; j + 1 < m; j++) {
        int t1 = a[i][j];
        int t2 = a[i][j + 1];
        int t3 = a[i + 1][j];
        int t4 = a[i + 1][j + 1];
        mn = min(mn, t1 + t2 + t3 + t4 - max({t1, t2, t3, t4}));
      }
    }
    cout << sum - max(0, mn - 1) << "\n";
  }

  return 0;
}
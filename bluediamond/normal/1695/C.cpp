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

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  bitset<2000 + 7> ok[1000 * 1000 + 7];

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m)), id(n, vector<int> (m));
    for (int i = 0; i < n * m; i++) {
      ok[i] = 0;
    }
    for (auto &v : a) {
      for (auto &x : v) {
        cin >> x;
        assert(x == -1 || x == + 1);
      }
    }
    ok[0][1000 + a[0][0]] = 1;
    int crid = 0;
    for (auto &v : id) {
      for (auto &x : v) {
        x = crid++;
      }
    }
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        if (a[r][c] == -1) {
          if (r - 1 >= 0) ok[id[r][c]] |= (ok[id[r - 1][c]] >> 1);
          if (c - 1 >= 0) ok[id[r][c]] |= (ok[id[r][c - 1]] >> 1);
        } else {
          assert(a[r][c] == +1);
          if (r - 1 >= 0) ok[id[r][c]] |= (ok[id[r - 1][c]] << 1);
          if (c - 1 >= 0) ok[id[r][c]] |= (ok[id[r][c - 1]] << 1);
        }
      }
    }
    if (ok[n * m - 1][1000] == 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
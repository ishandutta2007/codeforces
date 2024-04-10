#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;
    bool ok = 0;
    for (int ur = 0; ur <= 1; ur++) {
      for (int rd = 0; rd <= 1; rd++) {
        for (int dl = 0; dl <= 1; dl++) {
          for (int lu = 0; lu <= 1; lu++) {
            int uu = u - ur - lu;
            int rr = r - ur - rd;
            int dd = d - rd - dl;
            int ll = l - dl - lu;
            bool now = 1;
            now &= (0 <= uu && uu <= n - 2);
            now &= (0 <= rr && rr <= n - 2);
            now &= (0 <= dd && dd <= n - 2);
            now &= (0 <= ll && ll <= n - 2);
            ok |= now;
          }
        }
      }
    }
    cout << (ok ? "YES" : "NO") << "\n";
  }
}
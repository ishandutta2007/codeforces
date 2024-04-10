#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, u, v, last, ret;
    cin >> n >> u >> v >> last;
    ret = v + min(u, v);
    for (int i = 2; i <= n; i++) {
      int now;
      cin >> now;
      if (abs(last - now) > 1) {
        ret = min(ret, 0);
      }
      if (abs(last - now) == 1) {
        ret = min(ret, u);
        ret = min(ret, v);
      }
      last = now;
    }
    cout << ret << "\n";
  }
}
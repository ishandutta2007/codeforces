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
    string a, b;
    cin >> a >> b;
    int n = (int) a.size(), m = (int) b.size();
    int ret = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int l = 1; i + l - 1 < n && j + l - 1 < m; l++) {
          if (a[i + l - 1] != b[j + l - 1]) break;
          ret = max(ret, 2 * l);
        }
      }
    }

    cout << n + m - ret << "\n";
  }
  return 0;
}
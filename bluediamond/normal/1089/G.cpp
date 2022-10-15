#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
///typedef long double ld;
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

int k, a[7];

signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    int total = 0;
    cin >> k;
    for (int i = 0; i < 7; i++) {
      cin >> a[i];
      total += a[i];
    }
    int ret = (int) 1e18;
    for (int s = 0; s < 7; s++) {
      int need = k, cost = 0;
      for (int i = s; i < 7; i++) {
        if (need == 0) {
          break;
        }
        need -= a[i];
        cost++;
      }
      if (need >= total + 1) {
        int k = (need - 1) / total;
        need -= total * k;
        cost += 7 * k;
      }
      for (int i = 0; i < 7; i++) {
        if (need == 0) {
          break;
        }
        need -= a[i];
        cost++;
      }
      ret = min(ret, cost);
    }
    cout << ret << "\n";
  }
  return 0;
}
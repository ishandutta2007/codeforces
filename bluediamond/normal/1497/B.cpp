#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;

int realMain();

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

const int N = (int) 1e5 + 7;
int n, m, cnt[N];

signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      cnt[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      cnt[x % m]++;
    }
    /**for (int i = 0; i < m; i++) {
      cout << i << " : " << cnt[i] << "\n";
    }**/
    int ret = 0;
    ret += (cnt[0] > 0);
    if (m % 2 == 0) {
      ret += (cnt[m / 2] > 0);
    }
  ///  cout << " = " << ret << "\n";
    for (int i = 1; i < m - i; i++) {
      int c1 = cnt[i], c2 = cnt[m - i];
      if (c1 == 0 && c2 == 0) {
        continue;
      }
      if (c1 < c2) {
        swap(c1, c2);
      }
      int init = ret;
    ///  cout << " : " << c1 << " and " << c2 << " : ";
      /// c1 >= c2
      if (c2 == c1 || c2 == c1 - 1) {
        ret++;
      } else {
        ret++;
        ret += c1 - 1 - c2;
      }
    ///  cout << ret - init << "\n";
    }
    cout << ret << "\n";
  }
}
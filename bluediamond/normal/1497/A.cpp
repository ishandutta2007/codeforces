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

int f[107];

signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i <= 100; i++) {
      f[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      f[x]++;
    }
    for (int i = 0; i <= 100; i++) {
      if (f[i]) {
        cout << i << " ";
        f[i]--;
      }
    }
    for (int i = 0; i <= 100; i++) {
      while (f[i]) {
        cout << i << " ";
        f[i]--;
      }
    }
    cout << "\n";
  }
}
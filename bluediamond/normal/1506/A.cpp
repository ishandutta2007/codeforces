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
    int n, m, x;
    cin >> n >> m >> x;
    x--;
    int c = x / n, r = x % n;
   // cout << r << " " << c << "\n";
    cout << r * m + c + 1 << "\n";
  }
  return 0;
}
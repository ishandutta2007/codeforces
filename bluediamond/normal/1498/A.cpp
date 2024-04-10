#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
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

bool ok(int x) {
  int y = x, s = 0;
  while (x) {
    int c = x % 10;
    s += c;
    x /= 10;
  }

  return __gcd(s, y) > 1;
}

signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    while (!ok(n)) n++;
    cout << n << "\n";
  }

  return 0;
}
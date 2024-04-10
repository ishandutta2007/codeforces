#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
///#define int ll
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

const int N = (int) 2e5 + 7;
int n, eq[N], a[N], b[N];
string s;
bool okay = 1;

void baddy(bool k) {
  okay &= k;
}

void rec() {
  okay = 1;
  if (!eq[1] || !eq[n]) {
    cout << "NO\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = b[i] = 0;
  }
  int sa = 0, sb = 0;
  for (int i = 1; i < n; i++) {
    if (eq[i]) {
      bool close = (sa >= 1 && sb >= 1);
      if (close && max(sa, sb) == 1 && !eq[i + 1]) {
        close = 0;
      }
      if (close) {
        a[i] = b[i] = -1;
      } else {
        a[i] = b[i] = +1;
      }
    } else {
      if (sa < sb) {
        a[i] = +1;
        b[i] = -1;
      } else {
        a[i] = -1;
        b[i] = +1;
      }
    }
    sa += a[i];
    sb += b[i];
  }
  a[n] = b[n] = -1;
  sa = 0, sb = 0;
  for (int i = 1; i <= n; i++) {
    baddy(abs(a[i]) == 1);
    baddy(abs(b[i]) == 1);
    sa += a[i];
    sb += b[i];
    baddy(sa >= 0);
    baddy(sb >= 0);
  }
  baddy(sa == 0 && sb == 0);
  if (!okay) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) cout << "("; else cout << ")";
  }
  cout << "\n";
  for (int i = 1; i <= n; i++) {
    if (b[i] == 1) cout << "("; else cout << ")";
  }
  cout << "\n";
}

signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
      eq[i] = s[i - 1] - '0';
    }
    rec();
  }
  return 0;
}
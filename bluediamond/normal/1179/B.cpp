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

int n, m;

signed realMain() {
  cin >> n >> m;
  for (int r = 1; r < n + 1 - r; r++) {
    for (int c = 1; c <= m; c++) {
      cout << r << " " << c << "\n";
      cout << n + 1 - r << " " << m + 1 - c << "\n";
    }
  }
  if (n % 2 == 1) {
    int r = (n + 1) / 2;
    for (int c = 1; c < m + 1 - c; c++) {
      cout << r << " " << c << "\n";
      cout << r << " " << m + 1 - c << "\n";
    }
    if (m % 2 == 1) {
      cout << r << " " << (m + 1) / 2 << "\n";
    }
  }
}
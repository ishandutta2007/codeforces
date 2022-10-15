#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroint-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
#define int ll
signed realMain();


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = 100 + 7;
int mn[N][N], mx[N][N];

signed realMain() {
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      if (i == 1 && j == 1) mn[i][j] = mx[i][j] = 0;
      else mn[i][j] = (int) 1e18, mx[i][j] = -(int) 1e18;
    }
  }
  for (int x = 1; x <= 100; x++) {
    for (int y = 1; y <= 100; y++) {
      mn[x][y + 1] = min(mn[x][y + 1], mn[x][y] + x);
      mn[x + 1][y] = min(mn[x + 1][y], mn[x][y] + y);

      mx[x][y + 1] = max(mx[x][y + 1], mx[x][y] + x);
      mx[x + 1][y] = max(mx[x + 1][y], mx[x][y] + y);
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (mn[n][m] <= k && k <= mx[n][m]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
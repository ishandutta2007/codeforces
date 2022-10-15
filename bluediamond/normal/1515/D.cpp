#include <bits/stdc++.h>
///#pragma GCC target("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")


/**
#pragma GCC opimize("O3")
#pragma GCC opimization ("unroll-loops")

**/
using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
///#define int ll
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

const int N = (int) 2e5 + 7;
int n, l, r, cost, bad;
int f[N][2], c[2];

signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    cost = 0;
    bad = 0;
    cin >> n >> l >> r;
    c[0] = c[1] = 0;
    for (int i = 1; i <= n; i++) {
      f[i][0] = f[i][1] = 0;
    }
    for (int i = 1; i <= n; i++) {
      int col, type = (i <= l);
      cin >> col;
      if (f[col][type ^ 1]) {
        f[col][type ^ 1]--;
      } else {
        f[col][type]++;
      }
    }

    for (int i = 1; i <= n; i++) {
      c[0] += f[i][0];
      c[1] += f[i][1];
    }
    cost += min(c[0], c[1]);
    for (int j = 0; j <= 1; j++) {
      int rem = min(c[0], c[1]);
      for (int i = 1; i <= n; i++) {
        if (f[i][j] % 2 == 1 && rem >= 1) {
          f[i][j]--;
          rem--;
        }
      }
      for (int i = 1; i <= n; i++) {
        int take = min(rem, f[i][j]);
        f[i][j] -= take;
        rem -= take;
      }
      for (int i = 1; i <= n; i++) {
        cost += f[i][j] / 2;
        bad += f[i][j] % 2;
      }

    }
    cout << cost + bad << "\n";
  ///  return 0;
  }
  return 0;
}
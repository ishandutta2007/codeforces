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

time_t bg, nd;

/**
bool eprim(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}**/

signed main() {
  bg = clock();
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

void upd(int &a, int b) {
  a = min(a, b);
}

const int F = 16000;
const int N = 6;
const int INF = (int) 1e9;
int n, m, a[N], b[N], c[N][N], pw[10], dp[5][F], sum;

signed realMain() {
  pw[0] = 1;
  for (int i = 1; i < 10; i++) {
    pw[i] = 5 * pw[i - 1];
  }
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c[i][j];
    }
  }
  for (int i = 0; i <= 4; i++) {
    for (int j = 0; j < F; j++) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int cur = 0; cur < b[i]; cur++) {
        for (int mask = 0; mask < F; mask++) {
          if (dp[cur][mask] == INF) {
            continue;
          }
          int relax = dp[cur][mask] + c[j][i];
          for (int push = 1; cur + push <= b[i]; push++) {
            int deja_in_j = (mask / pw[j]) % 5;
            if (deja_in_j + push > a[j]) {
              break;
            }
            upd(dp[cur + push][mask + pw[j] * push], relax);
          }
        }
      }
    }
    for (int cur = 1; cur <= b[i]; cur++) {
      for (int mask = 0; mask < F; mask++) {
        dp[0][mask] = min(dp[0][mask], dp[cur][mask]);
        dp[cur][mask] = INF;
      }
    }
    for (int mask = 0; mask < F; mask++) {
      if (dp[0][mask] == INF) {
        continue;
      }
    }
  }

  int best = INF;
  for (int mask = 0; mask < F; mask++) {
    if (dp[0][mask] >= best) {
      continue;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += (mask / pw[i]) % 5;
    }
    ///cout << " = " << mask << " : " << cnt << "\n";
    if (cnt >= sum) {
      best = dp[0][mask];
    }
  }
  if (best == INF) {
    best = -1;
  }
  cout << best << "\n";
  return 0;
}
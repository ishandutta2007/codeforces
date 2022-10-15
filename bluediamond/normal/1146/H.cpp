#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
//#define int ll
signed realMain();

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
}
**/

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

const int N = 300 + 7;
const int K = 7;
int n, x[N], y[N];
ll dp[N][N][K];
vector<pair<ld, int>> lns;

signed realMain() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    dp[i][i][0] = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      lns.push_back({atan2(y[j] - y[i], x[j] - x[i]), i * n + j});
    }
  }
  sort(lns.begin(), lns.end());
  for (auto &it : lns) {
    int i = it.second % n, j = it.second / n;
    for (int go = 0; go < n; go++) {
      for (int k = 0; k <= 4; k++) {
        dp[go][j][k + 1] += dp[go][i][k];
      }
    }
  }
  ll wanda = 0;
  for (int i = 0; i < n; i++) {
    wanda += dp[i][i][5];
  }
  cout << wanda << "\n";
  return 0;
}
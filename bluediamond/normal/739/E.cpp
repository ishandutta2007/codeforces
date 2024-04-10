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
//typedef long long ll;
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

struct data {
  ld best;
  int use;
};

data best(data a, data b) {
  if (a.best == b.best) {
    if (a.use < b.use) {
      return a;
    } else {
      return b;
    }
  }
  if (a.best > b.best) {
    return a;
  } else {
    return b;
  }
}

const int N = 2000 + 7;
int n, a, b;
ld p[N], q[N], both[N];
data dp[N];

data get(ld coef) {
  dp[0] = {0, 0};
  for (int i = 1; i <= n; i++) {
    dp[i] = {-1e18, 0};
  }
  for (int pos = 1; pos <= n; pos++) {
    for (int j = 1; j <= n; j++) {
      dp[j] = best(dp[j], dp[j - 1]);
    }
    for (int j = n; j >= 0; j--) {
      dp[j + 1] = best(dp[j + 1], {dp[j].best + p[pos], dp[j].use});
      dp[j + 1] = best(dp[j + 1], {dp[j].best + both[pos] + coef, dp[j].use + 1});
      dp[j] = best(dp[j], {dp[j].best + q[pos] + coef, dp[j].use + 1});
    }
  }
  return dp[a];
}

signed realMain() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> q[i];
    both[i] = 1 - (1 - p[i]) * (1 - q[i]);
  }
  ld l = -1e9, r = 1e9;
  for (int step = 1; step <= 100; step++) {
    ld m = (l + r) / 2;
    auto it = get(m);
    if (it.use <= b) {
      l = m;
    } else {
      r = m;
    }
  }
  auto it = get(l);
  cout << fixed << setprecision(6) << it.best - b * l << "\n";
  return 0;
}
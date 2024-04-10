#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

mt19937 rng_home(0);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else{
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
}

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

const int N = 50 + 1;
int n, lim, m, ff[N], ss[N], over[N], pay[N], jmen[N], dp[N][N][N];

signed realMain() {
  cin >> n >> lim >> m;
  for (int i = 1; i <= m; i++) {
    cin >> ff[i] >> ss[i] >> over[i] >> pay[i];
  }
  for (int l = n; l >= 1; l--) {
    for (int r = l; r <= n; r++) {
      for (int h = 1; h <= lim; h++) {
        dp[l][r][h] = dp[l][r][h - 1];
        for (int j = 1; j <= n; j++) {
          jmen[j] = 0;
        }
        for (int j = 1; j <= m; j++) {
          if (l <= ff[j] && ss[j] <= r && h > over[j]) {
            jmen[ff[j]] += pay[j];
            jmen[ss[j] + 1] -= pay[j];
          }
        }
        for (int j = 1; j <= n; j++) {
          jmen[j] += jmen[j - 1];
        }
        for (int p = l; p <= r; p++) {
          dp[l][r][h] = max(dp[l][r][h], dp[l][p - 1][h] + dp[p + 1][r][h] + h * h - jmen[p]);
        }
      }
    }
  }
  cout << dp[1][n][lim] << "\n";
  return 0;
}
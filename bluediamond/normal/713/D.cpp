#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

/**
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
}**/

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

int max(int a, int b, int c, int d) {
  return max(max(a, b), max(c, d));
}

const int N = 1000 + 7;
const int K = 10;
int n, m, t[K][K][N][N], lg[N], a[N][N], dp[N][N];

int get(int r1, int c1, int r2, int c2) {
  int k1 = lg[r2 - r1 + 1], k2 = lg[c2 - c1 + 1];
  return max(t[k1][k2][r1][c1], t[k1][k2][r1][c2 - (1 << k2) + 1], t[k1][k2][r2 - (1 << k1) + 1][c1], t[k1][k2][r2 - (1 << k1) + 1][c2 - (1 << k2) + 1]);
}

signed realMain() {
  for (int i = 2; i < N; i++) lg[i] = 1 + lg[i / 2];
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      if (a[i][j]) {
        dp[i][j] = 1 + min(dp[i + 1][j + 1], min(dp[i + 1][j], dp[i][j + 1]));
        t[0][0][i][j] = dp[i][j];
      }
      for (int k2 = 1; j + (1 << k2) - 1 <= m; k2++) {
        t[0][k2][i][j] = max(t[0][k2 - 1][i][j], t[0][k2 - 1][i][j + (1 << (k2 - 1))]);
      }
      for (int k1 = 1; i + (1 << k1) - 1 <= n; k1++) {
        for (int k2 = 0; j + (1 << k2) - 1 <= m; k2++) {
          t[k1][k2][i][j] = max(t[k1 - 1][k2][i][j], t[k1 - 1][k2][i + (1 << (k1 - 1))][j]);
        }
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int r1, c1, r2, c2, ret = 0;
    cin >> r1 >> c1 >> r2 >> c2;
    int l = 1, r = min(r2 - r1 + 1, c2 - c1 + 1);
    while (l <= r) {
      int m = (l + r) / 2;
      int val = get(r1, c1, r2 - m + 1, c2 - m + 1);
      if (val >= m) {
        ret = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    cout << ret << "\n";
  }
  return 0;
}
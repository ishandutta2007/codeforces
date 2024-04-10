#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;

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

const int N = 3000 + 7;
const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int n, m, a[N][N], dp[N][N];

int ways(int r1, int c1, int r2, int c2) {
  if (a[r1][c1] || a[r2][c2]) return 0;
  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) dp[i][j] = 0;
  dp[r1][c1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) continue;
      dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
      dp[i][j + 1] = add(dp[i][j + 1], dp[i][j]);
    }
  }
  return dp[r2][c2];
}


signed realMain() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) {
      a[i][j] = (s[j - 1] == '#');
    }
  }
  int estimation = mul(ways(1, 2, n - 1, m), ways(2, 1, n, m - 1));
  int bad = mul(ways(1, 2, n, m - 1), ways(2, 1, n - 1, m));
  cout << add(estimation, -bad) << "\n";
  return 0;
}
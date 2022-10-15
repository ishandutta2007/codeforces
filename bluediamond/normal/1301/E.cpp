#include <bits/stdc++.h>

using namespace std;

mt19937 rng(228);

int get(char c) {
  if (c == 'R') return 0;
  if (c == 'G') return 1;
  if (c == 'Y') return 2;
  if (c == 'B') return 3;
  throw;
}

const int N = 500 + 7;
int n, m, q, a[N][N], sum[4][N][N], dp[N][N], rmq[N][N][9][9], lg[N];

int get(int x, int r1, int c1, int r2, int c2) {
  r1 = max(1, r1);
  c1 = max(1, c1);
  r2 = min(n, r2);
  c2 = min(c2, m);
  return sum[x][r2][c2] - sum[x][r2][c1 - 1] - sum[x][r1 - 1][c2] + sum[x][r1 - 1][c1 - 1];
}

bool check(int x, int r, int c, int l) {
  return get(x, r, c, r + l - 1, c + l - 1) == l * l;
}

int smart(int r1, int c1, int r2, int c2) {
  if (r2 < r1 || c2 < c1) {
    return 0;
  }
  int k1 = lg[r2 - r1 + 1];
  int k2 = lg[c2 - c1 + 1];
  int a = rmq[r1][c1][k1][k2];
  int b = rmq[r2 - (1 << k1) + 1][c1][k1][k2];
  int c = rmq[r1][c2 - (1 << k2) + 1][k1][k2];
  int d = rmq[r2 - (1 << k1) + 1][c2 - (1 << k2) + 1][k1][k2];
  return max(max(a, b), max(c, d));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) {
      a[i][j] = get(s[j - 1]);
      sum[a[i][j]][i][j] = 1;
    }
  }
  for (int k = 0; k < 4; k++) {
    for (int i = 1; i <= n; i++) {
      int curs = 0;
      for (int j = 1; j <= m; j++) {
        curs += sum[k][i][j];
        sum[k][i][j] = curs + sum[k][i - 1][j];
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      int l = dp[i + 1][j + 1] + 1;
      dp[i][j] = (check(0, i, j, l) && check(1, i, j + l, l) && check(2, i + l, j, l) && check(3, i + l, j + l, l)) * l;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (dp[i][j]) {
        int l = dp[i][j];
        rmq[i + l - 1][j + l - 1][0][0] = max(rmq[i + l - 1][j + l - 1][0][0], l);
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      for (int k = 1; j + (1 << k) - 1 <= m; k++) {
        rmq[i][j][0][k] = max(rmq[i][j][0][k - 1], rmq[i][j + (1 << (k - 1))][0][k - 1]);
      }
      for (int k1 = 1; i + (1 << k1) - 1 <= n; k1++) {
        for (int k2 = 0; j + (1 << k2) - 1 <= m; k2++) {
          rmq[i][j][k1][k2] = max(rmq[i][j][k1 - 1][k2], rmq[i + (1 << (k1 - 1))][j][k1 - 1][k2]);
        }
      }
    }
  }
  for (int i = 2; i < N; i++) {
    lg[i] = 1 + lg[i / 2];
  }

  while (q--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int lo = 1, hi = N - 1, ans = 0;
    while (lo <= hi) {
      int l = (lo + hi) / 2;
      if (smart(r1 + l - 1, c1 + l - 1, r2 - l, c2 - l) >= l) {
        ans = l;
        lo = l + 1;
      } else {
        hi = l - 1;
      }
    }
    cout << ans * ans * 4 << "\n";
  }
}
#include <bits/stdc++.h>

using namespace std;


const int N = 500 + 7;
const int K = 10 + 7;
const int INF = (int) 1e9;
int n, m, kk, samerw[N][N], samecl[N][N], dp[N][N][K];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int cost(int i1, int j1, int i2, int j2) {
  int dist = abs(i1 - i2) + abs(j1 - j2);
  if (i1 == i2) {
    return samerw[i1][min(j1, j2)];
  } else {
    return samecl[min(i1, i2)][j1];
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> kk;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < m; j++) {
      cin >> samerw[i][j];
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> samecl[i][j];
    }
  }
  if (kk & 1) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << "-1 ";
      }
      cout << "\n";
    }
    return 0;
  }
  kk /= 2;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 1; k <= kk; k++) {
        dp[i][j][k] = INF;
      }
    }
  }
  for (int k = 1; k <= kk; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        for (int s = 0; s < 4; s++) {
          int r = i + dr[s], c = j + dc[s];
          if (1 <= r && 1 <= c && r <= n && c <= m) {
            dp[i][j][k] = min(dp[i][j][k], dp[r][c][k - 1] + cost(i, j, r, c));
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << 2 * dp[i][j][kk] << " ";
    }
    cout << "\n";
  }
  return 0;
}
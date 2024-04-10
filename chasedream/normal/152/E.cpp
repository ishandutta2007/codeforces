#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int N = 105;
const int inf = 1e9;

int a[N][N], dp[N][N][1 << 7], f[N][N][1 << 7][3];
int n, m, K;
bool put[N][N];

void dfs(int x, int y, int mask) {
  put[x][y] = 1;
  if (f[x][y][mask][0] == 0) {
    dfs(f[x][y][mask][1], f[x][y][mask][2], mask);
  }
  else if (f[x][y][mask][0] == 1) {
    dfs(x, y, f[x][y][mask][1]);
    dfs(x, y, f[x][y][mask][2]);
  }
}

int main() { 
  scanf("%d%d%d", &n, &m, &K);
  for (register int i = 0; i < n; i++) {
    for (register int j = 0; j < m; j++) {
      for (register int k = 0; k < 1 << K; k++) {
        dp[i][j][k] = inf;
      }
    }
  }  
  for (register int i = 0; i < n; i++) {
    for (register int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  
  for (register int i = 0; i < K; i++) {
    int x, y; scanf("%d%d", &x, &y);
    x--, y--;
    f[x][y][1 << i][0] = 2;
    dp[x][y][1 << i] = a[x][y];
  }
  
  for (register int mask = 0; mask < 1 << K; mask++) {
    for (register int i = 0; i < n; i++) {
      for (register int j = 0; j < m; j++) {
        for (register int sub = mask; sub > 0; sub = (sub - 1) & mask) {
          int tmps = dp[i][j][sub] + dp[i][j][mask ^ sub] - a[i][j];
          if (dp[i][j][mask] > tmps) {
            dp[i][j][mask] = tmps;
            f[i][j][mask][0] = 1;
            f[i][j][mask][1] = sub;
            f[i][j][mask][2] = mask ^ sub;
          }
        }
      }
    }
    for (register int times = 0; times <= n * m; times++) {
      for (register int i = 0; i < n; i++) {
        for (register int j = 0; j < m; j++) {
          for (register int dir = 0; dir < 4; dir++) {
            int fx = i + dx[dir], fy = j + dy[dir];
            if (fx >= 0 && fx < n && fy >= 0 && fy < m) {
              int tmps = dp[fx][fy][mask] + a[i][j];
              if (dp[i][j][mask] > tmps) {
                dp[i][j][mask] = tmps;
                f[i][j][mask][0] = 0;
                f[i][j][mask][1] = fx;
                f[i][j][mask][2] = fy;
              }
            }
          }
        }
      }
    }
  }
  
  int ans = inf;
  int ansx = 0, ansy = 0;
  for (register int i = 0; i < n; i++) {
    for (register int j = 0; j < m; j++) {
      if (ans > dp[i][j][(1 << K) - 1]) {
        ans = dp[i][j][(1 << K) - 1];
        ansx = i, ansy = j;
      }
    }
  }
  printf("%d\n", ans);
  
  dfs(ansx, ansy, (1 << K) - 1);
  for (register int i = 0; i < n; i++) {
    for (register int j = 0; j < m; j++) {
      putchar(put[i][j] ? 'X' : '.');
    }
    puts("");
  }
  return 0;
}
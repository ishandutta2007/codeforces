#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 223456

vector<int> adj[maxN];
int col[maxN], dp[maxN][2], tmp[2], M, n;

void dfs(int u, int par) {
  if (col[u] == 0 || col[u] == 1)
    dp[u][0] = 0;
  else
    dp[u][0] = (1 << 29);
  if (col[u] == 0 || col[u] == 2)
    dp[u][1] = 0;
  else
    dp[u][1] = (1 << 29);
  for (auto v : adj[u])
    if (v != par) {
      dfs(v, u);
      for (int c0 = 0; c0 <= 1; c0++)
        tmp[c0] = dp[u][c0], dp[u][c0] = (1 << 29);
      for (int c0 = 0; c0 <= 1; c0++)
        for (int c1 = 0; c1 <= 1; c1++) {
          int d = tmp[c0] + dp[v][c1] + (c0 != c1);
          if (d <= M)
            dp[u][c0] = min(dp[u][c0], max(tmp[c0], dp[v][c1] + (c0 != c1)));
        }
    }
}

bool check() {
  dfs(1, 0);
  return min(dp[1][0], dp[1][1]) <= M;
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    scanf("%d", &col[i]);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int l = -1, r = n + 1;
  while (l + 1 < r) {
    M = l + (r - l) / 2;
    if (check())
      r = M;
    else
      l = M;
  }
  printf("%d\n", (r + 1) / 2 + 1);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    solve();
  }
}
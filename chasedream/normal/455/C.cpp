#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int n, m, q;

vector <int> adj[N];
void add(int u, int v) {
  adj[u].push_back(v);
}

int f[N], dis[N];
int find(int k) {
  return f[k] == k ? k : f[k] = find(f[k]);
}
void merge(int u, int v) {
  f[find(u)] = find(v); 
}

int dp[N];
int ans;

void dfs(int u, int fa) {
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs(v, u);
    ans = max(ans, dp[u] + dp[v] + 1);
    dp[u] = max(dp[u], dp[v] + 1);
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    f[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v); add(v, u);
    merge(u, v);
  }
  for (int i = 1; i <= n; i++) {
    if (find(i) == i) {
      ans = 0; dfs(i, 0);
      dis[i] = ans;
    }
  }
  
  while (q--) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      int x; scanf("%d", &x);
      printf("%d\n", dis[find(x)]);
    }
    else {
      int x, y; scanf("%d%d", &x, &y);
      int u = find(x), v = find(y);
      if (u == v) continue; 
      dis[v] = max(max(dis[u], dis[v]), (dis[u] + 1) / 2 + (dis[v] + 1) / 2 + 1);
      f[u] = v;
    }
  }
  return 0;
}
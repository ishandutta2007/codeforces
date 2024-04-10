%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 100005;

map <pair <int, int>, int> mp;
vector <int> adj[N];
int jump[N][20], dep[N], s[N];
int ans[N];
int id[N], n;

void dfs(int u, int fa) {
  jump[u][0] = fa;
  for (int i = 1; i < 20; i++)
    jump[u][i] = jump[jump[u][i - 1]][i - 1];
  for (int i = 0; i < (int)adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == fa) continue;
    dep[v] = dep[u] + 1;
    id[v] = mp[make_pair (u, v)];
    dfs(v, u);
  }
}

void dfs2(int u, int fa) {
  for (int i = 0; i < (int)adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == fa) continue;
    dfs2(v, u);
    s[u] += s[v];
  }
}

int LCA(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 19; i >= 0; i--)
    if (dep[jump[u][i]] >= dep[v]) {
      u = jump[u][i];
    }
  if (u == v) return u;
  for (int i = 19; i >= 0; i--)
    if (jump[u][i] != jump[v][i])
      u = jump[u][i], v = jump[v][i];
  return jump[u][0];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v; scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    mp[make_pair (v, u)] = i;
    mp[make_pair (u, v)] = i;
  }
  
  dep[1] = 1;
  dfs(1, 0);
  
  int q; scanf("%d", &q);
  while (q--) {
    int u, v; scanf("%d%d", &u, &v);
    s[u]++, s[v]++, s[LCA(u, v)] -= 2;
  }
  dfs2(1, 0);
  for (int i = 2; i <= n; i++)
    ans[id[i]] = s[i];
  for (int i = 1; i < n; i++)
    printf("%d ", ans[i]);
  return putchar('\n') & 0;
}
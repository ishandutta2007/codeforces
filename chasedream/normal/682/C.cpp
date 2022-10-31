%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 100005;

struct Edge {
  int to, nxt, val;
  Edge (int to = 0, int nxt = 0, int val = 0):
    to(to), nxt(nxt), val(val) {} 
} edge[N << 1];
int head[N], tot;
void add(int u, int v, int val) {
  edge[++tot] = Edge(v, head[u], val);
  head[u] = tot;
}

int v[N], n;

int fa[N], sz[N];
void dfs(int u) {
  sz[u] = 1;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa[u]) continue;
    fa[v] = u;
    dfs(v); sz[u] += sz[v];
  }
}

int ans = 0;
void dfs2(int u, long long tot) {
  if (tot > v[u]) {
    ans += sz[u];
    return ;
  }
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to, val = edge[i].val;
    if (v == fa[u]) continue;
    dfs2(v, max(0LL, tot + val));
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
  }
  for (int i = 2; i <= n; i++) {
    int f, val; scanf("%d%d", &f, &val);
    add(f, i, val);
  }
  dfs(1);
  dfs2(1, 0);
  printf("%d\n", ans);
  return 0;
}
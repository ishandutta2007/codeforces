#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
struct Edge {
  int to, nxt;
  Edge(int to = 0, int nxt = 0): to(to), nxt(nxt) {}
} edge[N << 1];
int head[N], tot;

void add(int u, int v) {
  edge[++tot] = Edge(v, head[u]);
  head[u] = tot;
}

long long ans = 0LL;
int sz[N], cnt[2];
int n;

void dfs(int u, int f, int d) {
  cnt[d]++, sz[u] = 1;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == f) continue;
    dfs(v, u, d ^ 1);
    sz[u] += sz[v];
  }
  ans += 1LL * sz[u] * (n - sz[u]);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y; scanf("%d%d", &x, &y);
    add(x, y); add(y, x);
  }
  dfs(1, 0, 0);
  ans = ans + 1LL * cnt[0] * cnt[1];
  printf("%lld\n", ans >> 1);
  return 0;
}
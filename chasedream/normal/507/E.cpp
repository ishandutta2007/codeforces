#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
struct Edge {
  int to, nxt, val, vis;
  Edge (int to = 0, int nxt = 0, int val = 0, int vis = 0):
    to(to), nxt(nxt), val(val), vis(vis) {}
} edge[N << 1];
int head[N], tot = 1;

void add(int u, int v, int w) {
  edge[++tot] = Edge(v, head[u], w, 0);
  head[u] = tot;
}

const int inf = 1e9;

int vis[N], dis[N], num[N];
int pre[N], lst[N];
int n, m;

void bfs() {
  fill(vis + 1, vis + n + 1, 0);
  fill(dis + 1, dis + n + 1, inf);
  queue <int> q;
  q.push(1); vis[1] = 1, dis[1] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (register int i = head[u]; i; i = edge[i].nxt) {
      int v = edge[i].to;
      if (dis[v] == dis[u] + 1 && num[v] < num[u] + edge[i].val) {
        num[v] = num[u] + edge[i].val;
        pre[v] = u;
        lst[v] = i >> 1;
      }
      if (vis[v]) continue;
      dis[v] = dis[u] + 1, num[v] = num[u] + edge[i].val;
      pre[v] = u, lst[v] = i >> 1;
      vis[v] = 1, q.push(v);
    }
  }
}

struct Query {
  int x, y, z, vis;
} a[N];

int main() {
  scanf("%d%d", &n, &m);
  for (register int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    add(u, v, w); add(v, u, w);
    a[i] = {u, v, w, 0};
  } 
  pre[1] = 0, bfs();
  for (register int i = n; i > 0; i = pre[i]) {
    a[lst[i]].vis = 1;
  }
  int ans = 0;
  for (register int i = 1; i <= m; i++) {
    if (a[i].vis && !a[i].z) ans++;
    if (!a[i].vis && a[i].z) ans++;
  }
  printf("%d\n", ans);
  for (register int i = 1; i <= m; i++) {
    if (a[i].vis && !a[i].z)
      printf("%d %d 1\n", a[i].x, a[i].y);
    if (!a[i].vis && a[i].z)
      printf("%d %d 0\n", a[i].x, a[i].y);
  }
  return 0;
}
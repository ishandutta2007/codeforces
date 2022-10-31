#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000005;
struct Edge {
  int to, nxt;
} edge[maxn << 1];
int head[maxn], tot;

void add(int u, int v) {
  edge[++tot] = (Edge){v, head[u]};
  head[u] = tot;
}

int u, v;

void dfs(int u, int fa) {
  int son = 0;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa) continue;
    dfs(v, u); son++;
  }
  if (fa == -1 && son == 2) {
    puts("NO"); exit(0);
  }
  if (fa != -1 && son == 1) {
    puts("NO"); exit(0);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v; scanf("%d%d", &u, &v);
    add(u, v); add(v, u);
  }
  dfs(1, -1);
  puts("YES"); return 0; 
}
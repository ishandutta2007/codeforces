%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 2000005;
struct Edge {
  int to, nxt;
  Edge (int to = 0, int nxt = 0):
    to(to), nxt(nxt) {}
} edge[N << 1];
int head[N], tot;

void add(int u, int v) {
  edge[++tot] = Edge(v, head[u]);
  head[u] = tot;
}

bool vis[N];
int n, m;

void bfs() {
  priority_queue <int, vector <int>, greater <int> > pq;
  pq.push(1); vis[1] = 1;
  while(!pq.empty()) {
    int u = pq.top(); pq.pop();
    printf("%d ", u);
    for (int i = head[u]; i; i = edge[i].nxt) {
      int v = edge[i].to;
      if (!vis[v]) {
        vis[v] = 1;
        pq.push(v);
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v); add(v, u);
  }
  bfs();
  
}
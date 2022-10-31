/**   Author: wlzhouzhuan
 *    Created: 2019/07/26 16:42:45
 *
**/
%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 200005;
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

int col[N], co;

void dfs(int u, int fa) {
  //cerr << "in dfs " << u << ' ' << fa << '\n';
  int co2 = 0;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa) continue;
    co2++;
    if (co2 == col[u]) {
      co2++;
      if (co2 == col[fa]) co2++;
    }
    if (co2 == col[fa]) {
      co2++;
      if (co2 == col[u]) co2++;
    }
    col[v] = co2; co = max(co, co2);
    dfs(v, u);
  }
}

int n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v; scanf("%d%d", &u, &v);
    add(u, v); add(v, u);
  }
  col[1] = 1, co = 1; dfs(1, 0);
  
  printf("%d\n", co);
  for (int i = 1; i <= n; i++)
    printf("%d ", col[i]);
  putchar('\n'); return 0; 
}
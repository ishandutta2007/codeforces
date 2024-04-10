/**   Author: wlzhouzhuan
 *    Created: 2019/07/26 16:18:05
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

int f[N], son[N], dep[N];
int n, St, ans;

void dfs(int u, int fa) {
  f[u] = fa, dep[u] = dep[fa] + 1, son[u] = 1;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa) continue;
    dfs(v, u);
    son[u] = max(son[u], son[v] + 1);
  } 
}

int main() {
  scanf("%d%d", &n, &St);
  for (int i = 1; i < n; i++) {
    int x, y; scanf("%d%d", &x, &y);
    add(x, y); add(y, x);
  }
  dfs(1, 0);
  // BA 
  ans = (dep[St] - 1) << 1;
  /*
  for (int i = 1; i <= n; i++) {
    cerr << "for node: " << i << '\n';
    cerr << "son: " << son[i] << '\n';
    cerr << "fa: " << f[i] << '\n';
    cerr << "dep: " << dep[i] << '\n';
  }
  */
  int jump = St, lst = 0;
  while (jump != 1) {
    if (dep[St] - dep[jump] >= dep[jump] - 1) break;
    for (int i = head[jump]; i; i = edge[i].nxt) {
      int v = edge[i].to;
      if (v == f[jump]) continue;
      if (v == lst) continue;
      ans = max(ans, (son[v] + dep[jump] - 1) << 1);
    }
    lst = jump, jump = f[jump];
  }
  printf("%d\n", ans);
  return 0;
}
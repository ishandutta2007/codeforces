/**   Author: wlzhouzhuan
 *    Created: 2019/07/26 17:36:49
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

int ans[N], w[N], n;
vector <int> gr[N];
unordered_map <int, bool> f[N][2];

void dfs(int u, int fa, int opt, int num) {
  if (f[u][opt][num]) return ;
  f[u][opt][num] = 1;
  int val = __gcd(num, w[u]);
  ans[u] = max(ans[u], val);
  if (opt == 0) {
    ans[u] = max(ans[u], num);
  }
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa) continue;
    dfs(v, u, opt, val);
    if (opt == 0) {
      dfs(v, u, 1, num);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &w[i]);
  
  for (int i = 1; i < n; i++) {
    int u, v; scanf("%d%d", &u, &v);
    add(u, v); add(v, u);
  }
  dfs(1, 0, 0, 0);
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  putchar('\n');
  return 0;
}
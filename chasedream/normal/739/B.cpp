%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

#define int long long
const int N = 200005;
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

int jump[N][20];
int a[N], b[N], n;

int dep[N], sz[N], fa[N];
void dfs(int u) {
  sz[u] = 1; jump[u][0] = fa[u];
  for (int i = 1; i < 20; i++)
    jump[u][i] = jump[jump[u][i - 1]][i - 1];

  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to, val = edge[i].val;
    if (v == fa[u]) continue;
    b[v] = b[u] + val;
    fa[v] = u; dep[v] = dep[u] + 1;
    dfs(v); sz[u] += sz[v];
  }
}

int bl[N], pos[N], Size;
void dfs2(int u, int chain) {
  bl[u] = chain, pos[u] = ++Size;
  int k = 0;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v != fa[u] && sz[v] > sz[k])
      k = v;
  }
  if (!k) return ;
  dfs2(k, chain);
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v != fa[u] && v != k)
      dfs2(v, v);
  } 
}

#define ls (u << 1)
#define rs (u << 1 | 1)
#define sz(u) (tr[u].r - tr[u].l + 1)
struct Seg {
  int l, r;
  int sum, lzy; 
} tr[N << 2];

void pushup(int u) {
  tr[u].sum = tr[ls].sum + tr[rs].sum;
}

void pushdown(int u) {
  if (!tr[u].lzy) return ;
  tr[ls].lzy += tr[u].lzy;
  tr[ls].sum += sz(ls) * tr[u].lzy;
  tr[rs].lzy += tr[u].lzy;
  tr[rs].sum += sz(rs) * tr[u].lzy;
  tr[u].lzy = 0;
  return ;
}

void build(int u, int l, int r) {
  tr[u].l = l, tr[u].r = r;
  tr[u].sum = tr[u].lzy = 0;
  if (l == r) return ;
  int mid = (l + r) >> 1;
  build(ls, l, mid); build(rs, mid + 1, r);
}

void update(int u, int l, int r) {
  if (tr[u].l == l && tr[u].r == r) {
    tr[u].lzy++;
    tr[u].sum += sz(u);
    return ;    
  }
  pushdown(u);
  
  int mid = (tr[u].l + tr[u].r) >> 1;
  if (r <= mid) update(ls, l, r);
  else if (l > mid) update(rs, l, r);
  else {
    update(ls, l, mid);
    update(rs, mid + 1, r);
  }
  pushup(u);
}

int query(int u, int l, int r) {
  if (tr[u].l == l && tr[u].r == r) {
    return tr[u].sum;
  }
  pushdown(u);
  
  int mid = (tr[u].l + tr[u].r) >> 1;
  if (r <= mid) return query(ls, l, r);
  else if (l > mid) return query(rs, l, r);
  else return query(ls, l, mid) + query(rs, mid + 1, r);
}

void solve_chain(int x, int y) {
  while (bl[x] != bl[y]) {
    if (dep[bl[x]] < dep[bl[y]]) swap(x, y);
    update(1, pos[bl[x]], pos[x]);
    x = fa[bl[x]]; 
  }
  if (pos[x] > pos[y]) swap(x, y);
  update(1, pos[x], pos[y]);
  return ;
}

signed main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 2; i <= n; i++) {
    int v, val; scanf("%lld%lld", &v, &val);
    add(v, i, val);
  }
  
  b[0] = -1e15;
  dfs(1); dfs2(1, 1);
  build(1, 1, n);
  
  for (int i = 1; i <= n; i++) {
    int fake = i;
    for (int j = 19; j >= 0; j--) {
      if (b[fake] - b[jump[fake][j]] <= a[i]) {
        a[i] -= (b[fake] - b[jump[fake][j]]);
        fake = jump[fake][j];
      }
    }
    //printf("debug %d %d\n", fake, i);
    if (fake != i)
      solve_chain(fake, fa[i]);
  }
  
  for (int i = 1; i <= n; i++)
    printf("%lld ", query(1, pos[i], pos[i]));
  return putchar('\n') & 0;
}
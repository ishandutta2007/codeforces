#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rll RE ll
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i != -1; i = edge[i].nxt)
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second

template <typename T>
void read(T &x) {
  x = 0; char op = getchar(); int F = 1;
  while (!isdigit(op)) {
    if (op == '-') F *= -1; op = getchar();
  }
  while (isdigit(op)) {
    x = (x << 1) + (x << 3) + op - '0'; op = getchar();
  }
  x *= F;
}

template <typename T, typename ...Args>
void read(T &x, Args &...args) {
  read(x); read(args...);
}

template <typename T1, typename T2>
void ckmax(T1 &x, T2 y) {
  if (x < y) x = y;
}

template <typename T1, typename T2>
void ckmin(T1 &x, T2 y) {
  if (x > y) x = y;
}

#define int long long
const int N = 300005;

vector <int> adj[N];
int c[N], n;
int _ans[N];

#define ls tr[u].l
#define rs tr[u].r
struct Segment {
  int l, r;
  int ans, sum;
} tr[N << 4];
int rt[N << 4], cnt;

void pushup(int u) {
  if (tr[ls].sum > tr[rs].sum) {
    tr[u].sum = tr[ls].sum;
    tr[u].ans = tr[ls].ans;
  }
  else if (tr[ls].sum < tr[rs].sum) {
    tr[u].sum = tr[rs].sum;
    tr[u].ans = tr[rs].ans;
  }
  else {
    tr[u].sum = tr[ls].sum;
    tr[u].ans = tr[ls].ans + tr[rs].ans;
  }
}

void update(int &u, int l, int r, int pos, int v) {
  if (!u) u = ++cnt;
  if (l == r) {
    tr[u].sum += v;
    tr[u].ans = l;
    return ;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid) update(ls, l, mid, pos, v);
  else update(rs, mid + 1, r, pos, v);
  pushup(u);
}

int merge(int u, int v, int l, int r) {
  if (!u) return v; if (!v) return u;
  if (l == r) {
    tr[u].sum += tr[v].sum;
    tr[u].ans = l;
    return u;
  }
  int mid = (l + r) >> 1;
  tr[u].l = merge(tr[u].l, tr[v].l, l, mid);
  tr[u].r = merge(tr[u].r, tr[v].r, mid + 1, r);
  pushup(u);
  return u;
}

void dfs(int u, int F) {
  for (auto v: adj[u]) {
    if (v == F) continue;
    dfs(v, u);
    merge(rt[u], rt[v], 1, 100000);
  }
  update(rt[u], 1, 100000, c[u], 1);
  _ans[u] = tr[rt[u]].ans;
}

signed main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    read(c[i]); rt[++cnt] = i;
  }
  for (int i = 1; i < n; i++) {
    int u, v; read(u, v);
    adj[u].push_back(v);
    adj[v].push_back(u); 
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    printf("%lld ", _ans[i]);
  }
  putchar('\n');
  return 0;
}
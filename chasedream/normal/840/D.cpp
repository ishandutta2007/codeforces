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

const int N = 500005;

int a[N], b[N], c[N];
int n, m;

int rt[N << 5], sum[N << 5], ls[N << 5], rs[N << 5], cnt;

void build(int &u, int l, int r) {
  u = ++cnt;
  if (l == r) return ;
  int mid = l + r >> 1;
  build(ls[u], l, mid);
  build(rs[u], mid + 1, r);
}

void update(int &u, int v, int l, int r, int pos) {
  u = ++cnt;
  sum[u] = sum[v] + 1, ls[u] = ls[v], rs[u] = rs[v];
  if (l == r) return ;
  int mid = l + r >> 1;
  if (pos <= mid) update(ls[u], ls[v], l, mid, pos);
  else update(rs[u], rs[v], mid + 1, r, pos);
}

int query(int u, int v, int l, int r, int k) {
  if (l == r) return b[l];
  
  int num = 0;
  int x = sum[ls[u]] - sum[ls[v]], y = sum[rs[u]] - sum[rs[v]];
  int mid = l + r >> 1;
  
  if (x > k) {
    num = query(ls[u], ls[v], l, mid, k);
    if (num > 0) return num;
  }
  if (y > k) {
    num = query(rs[u], rs[v], mid + 1, r, k);
    if (num > 0) return num;
  }
  return -1;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  int len = unique(b + 1, b + n + 1) - b - 1;
  
  build(rt[0], 1, len);
  for (int i = 1; i <= n; i++) {
    int pos = lower_bound(b + 1, b + len + 1, a[i]) - b;
    update(rt[i], rt[i - 1], 1, len, pos);
  }  
  
  for (int i = 1; i <= m; i++) {
    int u, l, r;
    scanf("%d%d%d", &u, &l, &r);
    int k = (l - u + 1) / r;
    printf("%d\n", query(rt[l], rt[u - 1], 1, len, k));
  }
  return 0;
}
//
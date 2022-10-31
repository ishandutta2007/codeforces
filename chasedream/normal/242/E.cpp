%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
#define dd double
#define _i int
#define RE register
#define rep(i, l, r) for (RE int i = l; i <= r; i++)
#define req(i, l, r) for (RE int i = l; i >= r; i--)
#define range(i, l, r) rep(i, l, r - 1)
#define Be(s, t) memset(s, t, sizeof(s))
#define poly vector <int>
#define pii pair <int, int>
template <typename T> void read(T &x) { x = 0; int FF = 1; char op = getchar(); while (!isdigit(op)) { if (op == '-') FF = -1; op = getchar(); } while (isdigit(op)) { x = (x << 1) + (x << 3) + op - '0'; op = getchar(); } x *= FF; }
template <typename T> void print(T x) { if (x < 0) { putchar('-'); x = -x; } if (x < 1) return ; print(x / 10); putchar(x % 10 + '0'); }
template <typename T> void print(T x, char _tab) { print(x); putchar(_tab); }
 
const int N = 400005;

#define ls (u << 1)
#define rs (u << 1 | 1)
#define sz(u) (R[u] - L[u] + 1)
int L[N], R[N], bit[N][21], lzy[N]; 
ll sum[N];

int a[N], n, q;

void pushup(int u) {
  sum[u] = 0LL;
  for (int i = 0; i <= 20; i++) {
    bit[u][i] = bit[ls][i] + bit[rs][i];
    sum[u] += (1LL << i) * bit[u][i];
  }
}

void pushdown(int u) {
  if (!lzy[u]) return ;
  lzy[ls] ^= lzy[u], lzy[rs] ^= lzy[u];
  for (int i = 0; i <= 20; i++) {
    if (lzy[u] & (1LL << i)) {
      sum[ls] -= (1LL << i) * bit[ls][i];
      bit[ls][i] = sz(ls) - bit[ls][i];
      sum[ls] += (1LL << i) * bit[ls][i];
      sum[rs] -= (1LL << i) * bit[rs][i];
      bit[rs][i] = sz(rs) - bit[rs][i];
      sum[rs] += (1LL << i)  * bit[rs][i];
    }
  }
  lzy[u] = 0;
}

void build(int u, int l, int r) {
  L[u] = l, R[u] = r;
  if (l == r) {
    for (int i = 0; i <= 20; i++) {
      bit[u][i] = ((a[l] & (1 << i)) ? 1 : 0);
    }
    sum[u] = a[l];
    return ;
  }
  int mid = (l + r) >> 1;
  build(ls, l, mid); build(rs, mid + 1, r);
  pushup(u);
}

void update(int u, int l, int r, int val) {
  if (L[u] == l && R[u] == r) {
    for (int i = 0; i <= 20; i++) {
      if (val & (1LL << i)) {
        sum[u] -= (1LL << i) * bit[u][i];
        bit[u][i] = sz(u) - bit[u][i];
        sum[u] += (1LL << i) * bit[u][i]; 
      }
    }
    lzy[u] ^= val;
    return ;
  }
  pushdown(u);
  
  int mid = (L[u] + R[u]) >> 1;
  if (r <= mid) update(ls, l, r, val);
  else if (l > mid) update(rs, l, r, val);
  else {
    update(ls, l, mid, val);
    update(rs, mid + 1, r, val);
  }
  pushup(u);
}

ll query(int u, int l, int r) {
  if (L[u] == l && R[u] == r) {
    return sum[u];
  }
  pushdown(u);

  int mid = (L[u] + R[u]) >> 1;
  if (r <= mid) return query(ls, l, r);
  else if (l > mid) return query(rs, l, r);
  else return query(ls, l, mid) + query(rs, mid + 1, r);
}

void print() {
  for (int u = 1; u <= 10; u++) {
    printf("tr[%d] (%d, %d) (%d, %d)\n", u, L[u], R[u], sum[u], lzy[u]);
    printf("%d %d %d %d %d\n", bit[u][0], bit[u][1], bit[u][2], bit[u][3], bit[u][4]);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }

  build(1, 1, n);
  scanf("%d", &q);
  
  while (q--) {
    int opt; scanf("%d", &opt);
    if (opt == 1) { // query
      int l, r; scanf("%d%d", &l, &r);
      printf("%lld\n", query(1, l, r));
    }
    else { // update
      int l, r, x; scanf("%d%d%d", &l, &r, &x);
      update(1, l, r, x);
    }
    //print();
  }
  return 0;
}
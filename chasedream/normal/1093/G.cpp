#include <bits/stdc++.h>
using namespace std;

#define RE register
int n, k, kk;

const int N = 200002;
#define ls (u << 1)
#define rs (u << 1 | 1)
struct Seg {
  int l, r;
  int mx[17], mn[17];
} tr[N << 2];

int yy[N][5];

inline void _decode(Seg& u, int x) {
  memset(u.mx, 0, sizeof(u.mx));
  memset(u.mn, 0, sizeof(u.mn));

  for (RE int i = 0; i < kk; i++) {
    int re = i;
    u.mx[i] += yy[x][0];
    for (RE int j = 0; j < k - 1; j++) {
      if (i & (1 << j)) {
        u.mx[re] += yy[x][j + 1];
      }
      else {
        u.mx[re] -= yy[x][j + 1];
      }
    }
    u.mn[re] = u.mx[re];
  }
}

inline Seg merge(Seg l, Seg r) {
  Seg ans; ans.l = l.l, ans.r = r.r;
  for (RE int i = 0; i < kk; i++) {
    ans.mx[i] = max(l.mx[i], r.mx[i]);
    ans.mn[i] = min(l.mn[i], r.mn[i]);
  }
  return ans;
}

inline void pushup(int u) {
  tr[u] = merge(tr[ls], tr[rs]);
}

inline void build(int u, int l, int r) {
  tr[u].l = l, tr[u].r = r;
  if (l == r) {
    _decode(tr[u], l);
    return ;
  }
  int mid = (tr[u].l + tr[u].r) >> 1;
  build(ls, l, mid); build(rs, mid + 1, r);
  pushup(u);
}

inline void update(int u, int pos) {
  if (tr[u].l == tr[u].r) {
    _decode(tr[u], pos);
    return ;
  }
  int mid = (tr[u].l + tr[u].r) >> 1;
  if (pos <= mid) update(ls, pos);
  else update(rs, pos);
  pushup(u);
}

inline Seg query(int u, int l, int r) {
  if (tr[u].l == l && tr[u].r == r) return tr[u];
  int mid = (tr[u].l + tr[u].r) >> 1;
  
  if (r <= mid) return query(ls, l, r);
  else if (l > mid) return query(rs, l, r);
  else return merge(query(ls, l, mid), query(rs, mid + 1, r));
}

int main() {
  //freopen("jntm.in", "r", stdin);
  //freopen("jntm.out", "w", stdout);

  scanf("%d%d", &n, &k); kk = (1 << (k - 1));
  for (RE int i = 1; i <= n; i++) {
    for (RE int j = 0; j < k; j++) {
      scanf("%d", &yy[i][j]);
    }
  }
  build(1, 1, n);
  
  int q; scanf("%d", &q);
  while (q--) {
    int opt; scanf("%d", &opt);
    if (opt == 1) {
      int x; scanf("%d", &x);
      for (RE int i = 0; i < k; i++)
        scanf("%d", &yy[x][i]);
      update(1, x);
    }
    else {
      int l, r; scanf("%d%d", &l, &r);
      Seg ans = query(1, l, r);
      int maxans = 0;
      for (RE int i = 0; i < kk; i++) {
        maxans = max(maxans, ans.mx[i] - ans.mn[i]);
      }
      printf("%d\n", maxans);
    }
  }
  return 0;
}
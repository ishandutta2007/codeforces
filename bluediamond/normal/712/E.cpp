#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

struct T {
  ld l;
  ld r;
  bool gol;
} gol;

T operator + (T a, T b) {
  if (a.gol) return b;
  if (b.gol) return a;
  ld l1 = a.l, r1 = a.r, l2 = b.l, r2 = b.r;
  ld l = l1 * l2 / (1 - r1 * (1 - l2));
  ld r = r2 + r1 * l2 * (1 - r2) / (1 - (1 - l2) * r1);
  return {l, r};
}

const int N = 100000 + 7;
int n, q;
T t[4 * N];

void upd(int v, int tl, int tr, int i, ld val) {
  if (tr < i || i < tl) return;
  if (tl == tr) {
    t[v] = {val, val};
    return;
  }
  int tm = (tl + tr) / 2;
  upd(2 * v, tl, tm, i, val);
  upd(2 * v + 1, tm + 1, tr, i, val);
  t[v] = t[2 * v] + t[2 * v + 1];
}

T get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    return gol;
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  gol.gol = 1;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    ld a, b;
    cin >> a >> b;
    upd(1, 1, n, i, a / b);
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i;
      ld a, b;
      cin >> i >> a >> b;
      upd(1, 1, n, i, a / b);
    } else {
      int l, r;
      cin >> l >> r;
      cout << fixed << setprecision(6) << get(1, 1, n, l, r).l << "\n";
    }
  }
}
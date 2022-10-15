#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = (int) 1e5 + 7;
const int INF = (int) 1e18;
int n, q, a[N], t[4 * N], t2[4 * N];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = t2[v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = min(t[2 * v], t[2 * v + 1]);
    t2[v] = max(t2[2 * v], t2[2 * v + 1]);
  }
}

int get2(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) return -INF;
  if (l <= tl && tr <= r) return t2[v];
  int tm = (tl + tr) / 2;
  return max(get2(2 * v, tl, tm, l, r), get2(2 * v + 1, tm + 1, tr, l, r));
}

int get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) return INF;
  if (l <= tl && tr <= r) return t[v];
  int tm = (tl + tr) / 2;
  return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}



signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int foo;
    cin >> foo;
    a[i] = foo - a[i];
    a[i] += a[i - 1];
  }
  build(1, 1, n);
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (get(1, 1, n, l, r) < a[l - 1] || a[r] - a[l - 1] != 0) cout << "-1\n";
    else cout << get2(1, 1, n, l, r) - a[l - 1] << "\n";
  }
  return 0;
}
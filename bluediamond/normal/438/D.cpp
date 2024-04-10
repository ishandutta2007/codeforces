#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
/// #define int ll

const int N = (int) 1e5 + 7;
int n, q;
int t[4 * N];
ll s[4 * N];

ll sum(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) return 0;
  if (l <= tl && tr <= r) return s[v];
  int tm = (tl + tr) / 2;
  return sum(2 * v, tl, tm, l, r) + sum(2 * v + 1, tm + 1, tr, l, r);
}

void op(int v, int tl, int tr, int l, int r, int mod) {
  if (t[v] < mod) return;
  if (tr < l || r < tl) return;
  if (tl == tr) {
    t[v] %= mod;
    s[v] %= mod;
    return;
  }
  int tm = (tl + tr) / 2;
  op(2 * v, tl, tm, l, r, mod);
  op(2 * v + 1, tm + 1, tr, l, r, mod);
  t[v] = max(t[2 * v], t[2 * v + 1]);
  s[v] = s[2 * v] + s[2 * v + 1];
}

void mac(int v, int tl, int tr, int i, int x) {
  if (tr < i || i < tl) return;
  if (tl == tr) {
    t[v] = x;
    s[v] = x;
    return;
  }
  int tm = (tl + tr) / 2;
  mac(2 * v, tl, tm, i, x);
  mac(2 * v + 1, tm + 1, tr, i, x);
  t[v] = max(t[2 * v], t[2 * v + 1]);
  s[v] = s[2 * v] + s[2 * v + 1];
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    mac(1, 1, n, i, x);
  }
  while (q--) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int l, r;
      cin >> l >> r;
      cout << sum(1, 1, n, l, r) << "\n";
      continue;
    }
    if (tp == 2) {
      int l, r, x;
      cin >> l >> r >> x;
      op(1, 1, n, l, r, x);
      continue;
    }
    int i, x;
    cin >> i >> x;
    mac(1, 1, n, i, x);
  }
}
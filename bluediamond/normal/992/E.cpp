#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 2e5 + 7;
int n, q, a[N], tmax[4 * N], lazy[4 * N];

void push(int v, int tl, int tr) {
  if (lazy[v]) {
    tmax[v] += lazy[v];
    if (tl < tr) {
      lazy[2 * v] += lazy[v];
      lazy[2 * v + 1] += lazy[v];
    }
    lazy[v] = 0;
  }
}

void add(int v, int tl, int tr, int l, int r, int x) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    lazy[v] += x;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  add(2 * v, tl, tm, l, r, x);
  add(2 * v + 1, tm + 1, tr, l, r, x);
  tmax[v] = max(tmax[2 * v], tmax[2 * v + 1]);
}

void add(int l, int r, int x) {
  add(1, 1, n, l, r, x);
}

int get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) return -(int) 1e18;
  if (l <= tl && tr <= r) return tmax[v];
  int tm = (tl + tr) / 2;
  return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

int rec(int v, int tl, int tr) {
  push(v, tl, tr);
  if (tmax[v] < 0) {
    return -1;
  }
  if (tl == tr) {
    if (tmax[v] == 0) {
      return tl;
    }
    return -1;
  }
  int tm = (tl + tr) / 2, x = rec(2 * v, tl, tm);
  if (x == -1) {
    x = rec(2 * v + 1, tm + 1, tr);
  }
  return x;
}

signed realMain() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    add(i, i, a[i]);
    add(i + 1, n, -a[i]);
  }
  while (q--) {
    int i, x;
    cin >> i >> x;
    x = x - a[i];
    add(i, i, x);
    add(i + 1, n, -x);
    a[i] += x;
    cout << rec(1, 1, n) << "\n";
  }
  return 0;
}
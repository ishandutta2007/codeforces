#include <bits/stdc++.h>

using namespace std;

bool home = 1;
///#define int ll
typedef long long ll;
///typedef long double ld;
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

const int N = (int) 3e5 + 7;
const int M = (int) 1e6 + 7;
int n, m, q, a[N], b[N];


int tmax[4 * M];
int lazy[4 * M];

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
  add(1, 1, (int) 1e6, l, r, x);
}

int solve(int v, int tl, int tr) {
  push(v, tl, tr);
  if (tmax[v] <= 0) {
    return -1;
  }
  if (tl == tr) {
    return tl;
  }
  int tm = (tl + tr) / 2;
  int ret = solve(2 * v + 1, tm + 1, tr);
  if (ret == -1) {
    ret = solve(2 * v, tl, tm);
  }
  return ret;
}

int solve() {
  return solve(1, 1, (int) 1e6);
}

signed realMain() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    add(1, a[i], +1);
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    add(1, b[i], -1);
  }
  cin >> q;
  while (q--) {
    int type, i, x;
    cin >> type >> i >> x;
    if (type == 1) { /// change A
      add(1, a[i], -1);
      a[i] = x;
      add(1, a[i], +1);
    } else { /// change B
      add(1, b[i], +1);
      b[i] = x;
      add(1, b[i], -1);
    }
    cout << solve() << "\n";
  }
}
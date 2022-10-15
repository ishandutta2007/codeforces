#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
const int INF = (int) 1e9;
int n, init[N], sol[N], v[N], kek[N];

struct tree {
  int tmax[4 * N], lazy[4 * N];

  void build(int v, int tl, int tr) {
    lazy[v] = 0;
    if (tl == tr) {
      tmax[v] = kek[tl];
    } else {
      int tm = (tl + tr) / 2;
      build(2 * v, tl, tm);
      build(2 * v + 1, tm + 1, tr);
      tmax[v] = max(tmax[2 * v], tmax[2 * v + 1]);
    }
  }

  void push(int v, int tl, int tr) {
    if (!lazy[v]) return;
    tmax[v] += lazy[v];
    if (tl < tr) {
      lazy[2 * v] += lazy[v];
      lazy[2 * v + 1] += lazy[v];
    }
    lazy[v] = 0;
  }

  void add(int v, int tl, int tr, int l, int r, int x) {
    push(v, tl, tr);
    if (tr < l || r < tl) return;
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
    if (l < 1) l = 1;
    if (r > n) r = n;
    add(1, 1, n, l, r, x);
  }

  int get(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (tr < l || r < tl) return -INF;
    if (l <= tl && tr <= r) return tmax[v];
    int tm = (tl + tr) / 2;
    return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
  }

  int get(int l, int r) {
    if (l < 1) l = 1;
    if (r > n) r = n;
    return get(1, 1, n, l, r);
  }

  void init() {
    build(1, 1, n);
  }
} pre, suf;

bool cmp(int i, int j) {
  return init[i] < init[j];
}

int ind[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 // freopen ("input", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> init[i];
    ind[i] = i;
  }
  sort(ind + 1, ind + n + 1, cmp);
  for (int l = 1; l <= n; l++) {
    kek[l] = -l;
  }
  pre.init();
  for (int r = 1; r <= n; r++) {
    kek[r] = r + 1;
  }
  suf.init();
  int lo = 1;
  while (lo <= n) {
    int r = lo;
    while (r + 1 <= n && init[ind[r + 1]] == init[ind[r]]) {
      r++;
    }
    for (int j = lo; j <= r; j++) {
      int i = ind[j];
      sol[i] = max(sol[i], pre.get(1, i) + suf.get(i, n));
    }
    for (int j = lo; j <= r; j++) {
      int i = ind[j];
      pre.add(i + 1, n, 2);
      suf.add(i, n, -2);
    }
    lo = r + 1;
  }
  reverse(ind + 1, ind + n + 1);
  for (int l = 1; l <= n; l++) {
    kek[l] = -l;
  }
  pre.init();
  for (int r = 1; r <= n; r++) {
    kek[r] = r;
  }
  suf.init();
  lo = 1;
  while (lo <= n) {
    int r = lo;
    while (r + 1 <= n && init[ind[r + 1]] == init[ind[r]]) {
      r++;
    }
    for (int j = lo; j <= r; j++) {
      int i = ind[j];
      sol[i] = max(sol[i], pre.get(1, i) + suf.get(i, n));
    }
    for (int j = lo; j <= r; j++) {
      int i = ind[j];
      pre.add(i + 1, n, 2);
      suf.add(i, n, -2);
    }
    lo = r + 1;
  }
  for (int i = 1; i <= n; i++) {
    cout << sol[i] / 2 << " ";
  }
  cout << "\n";


  return 0;
}
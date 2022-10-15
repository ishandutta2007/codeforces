#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
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

const int N = (int) 5e5 + 7;
const int INF = (int) 1e18;
int n, q;
int t[4 * N], lazy[4 * N];

void push(int v, int tl, int tr) {
  if (lazy[v]) {
    t[v] += lazy[v];
    if (tl < tr) {
      lazy[2 * v] += lazy[v];
      lazy[2 * v + 1] += lazy[v];
    }
    lazy[v] = 0;
  }
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
  t[v] = min(t[2 * v], t[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) return INF;
  if (l <= tl && tr <= r) return t[v];
  int tm = (tl + tr) / 2;
  return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

void add(int l, int r, int x) {
  add(1, 1, n, l, r, x);
}

int get(int l, int r) {
  return get(1, 1, n, l, r);
}

struct Q {
  int i, l, r;
};

int pr[N], val[N], ret[N], init[N], l[N], r[N];
vector<int> g[N];
vector<Q> ask[N];

void build(int a, int cur = 0) {
  l[a] = r[a] = a;
  if (g[a].empty()) {
    init[a] = cur;
    return;
  }
  for (auto &i : g[a]) {
    build(i, cur + val[i]);
    l[a] = min(l[a], l[i]);
    r[a] = max(r[a], r[i]);
  }
}

void dfs(int a) {
  for (auto &it : ask[a]) {
    ret[it.i] = get(it.l, it.r);
  }
  for (auto &b : g[a]) {
    int w = val[b];
    add(1, n, +w); add(l[b], r[b], -2 * w);
    dfs(b);
    add(1, n, -w); add(l[b], r[b], +2 * w);

  }
}

signed realMain() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) init[i] = INF;
  for (int i = 2; i <= n; i++) {
    cin >> pr[i] >> val[i];
    g[pr[i]].push_back(i);
  }
  for (int i = 1; i <= q; i++) {
    ret[i] = -1;
    int v, l, r;
    cin >> v >> l >> r;
    ask[v].push_back({i, l, r});
  }
  build(1);
  for (int i = 1; i <= n; i++) {
    add(i, i, init[i]);
  }
  dfs(1);
  for (int i = 1; i <= q; i++) {
    cout << ret[i] << "\n";
  }
  return 0;
}
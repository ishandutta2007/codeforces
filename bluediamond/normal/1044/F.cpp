#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
const int K = 19;
int n, l[N], r[N], tt;
int p[N];
int dep[N];
int euler_tour[2 * N];
int anc[K][N];
int tour_sz;
int first_time_on_tour[N];
int last_time_on_tour[N];
int lg2[2 * N];
vector<int> g[N];
pair<int, int> tab_lca[2 * N][K];

void dfs_lca(int a, int par = 0) {
  tt++;
  l[a] = tt;
  p[a] = par;
  euler_tour[++tour_sz] = a;
  first_time_on_tour[a] = last_time_on_tour[a] = tour_sz;
  for (auto &b : g[a]) {
    if (b == par) continue;
    dep[b] = 1 + dep[a];
    dfs_lca(b, a);
    euler_tour[++tour_sz] = a;
    last_time_on_tour[a] = tour_sz;
  }
  r[a] = tt;
}

void lcaTM() {
  dfs_lca(1);
  for (int i = 2; i <= tour_sz; i++) {
    lg2[i] = 1 + lg2[i / 2];
  }
  for (int i = 1; i <= n; i++) {
    anc[0][i] = p[i];
  }
  for (int k = 1; (1 << k) <= n; k++) {
    for (int i = 1; i <= n; i++) {
      anc[k][i] = anc[k - 1][anc[k - 1][i]];
    }
  }
  for (int i = 1; i <= tour_sz; i++) {
    tab_lca[i][0] = {dep[euler_tour[i]], euler_tour[i]};
  }
  for (int k = 1; (1 << k) <= tour_sz; k++) {
    for (int i = 1; i + (1 << k) - 1 <= tour_sz; i++) {
      tab_lca[i][k] = min(tab_lca[i][k - 1], tab_lca[i + (1 << (k - 1))][k - 1]);
    }
  }
}

int kth(int a, int k) {
  for (int bit = 0; (1 << bit) <= k; bit++) {
    if (k & (1 << bit)) {
      a = anc[bit][a];
    }
  }
  return a;
}

int lca(int a, int b) {
  if (first_time_on_tour[a] > last_time_on_tour[b]) {
    swap(a, b);
  }
  a = first_time_on_tour[a];
  b = last_time_on_tour[b];
  int k = lg2[b - a + 1];
  return min(tab_lca[a][k], tab_lca[b - (1 << k) + 1][k]).second;
}

int q, lmao[N];
set<pair<int, int>> rE;

struct T {
  int mx;
  int cnt;
};

T gol = {-(int) 1e9, 0};

T operator + (T a, T b) {
  if (a.mx == gol.mx) return b;
  if (b.mx == gol.mx) return a;
  if (a.mx < b.mx) swap(a, b);
  if (a.mx > b.mx) return a;
  return {a.mx, a.cnt + b.cnt};
}

T t[4 * N];
int lazy[4 * N];

void push(int v, int tl, int tr) {
  if (lazy[v]) {
    t[v].mx += lazy[v];
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
  t[v] = t[2 * v] + t[2 * v + 1];
}

T get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) return gol;
  if (l <= tl && tr <= r) return t[v];
  int tm = (tl + tr) / 2;
  return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
}

void add(int a, int sgn) {
  add(1, 1, n, l[a], r[a], sgn);
}


void add(int a, int b, int sgn) {
  int c = lca(a, b);
  if (c == b) swap(a, b);
  if (a == c) {
    int par = kth(b, dep[b] - dep[a] - 1);
    add(b, sgn);
    add(a, sgn);
    add(par, -sgn);
    add(1, sgn);
    add(a, -sgn);

    return;
  }
  add(a, sgn);
  add(b, sgn);
}

void build(int v, int tl, int tr) {
  t[v].cnt = tr - tl + 1;
  if (tl < tr) {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> q;
  build(1, 1, n);
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  lcaTM();
  while (q--) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (!rE.count({a, b})) {
      add(a, b, +1);
      rE.insert({a, b});
    } else {
      add(a, b, -1);
      rE.erase({a, b});
    }
    auto it = get(1, 1, n, 1, n);
    if (it.mx == (int) rE.size()) cout << it.cnt << "\n";
    else {
      cout << "0\n";
    }
  }
}
#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
const int M = (int) 1e3 + 7;
int n, m, init[N], ll[N], rr[N], top, nodes[N], v[N];
vector<int> g[N];

void dfs(int a, int p = -1) {
  nodes[++top] = a;
  ll[a] = top;
  for (auto &b : g[a]) {
    if (b != p) {
      dfs(b, a);
    }
  }
  rr[a] = top;
}

bitset<M> t[4 * N], tot;
int lazy[4 * N];

void shiftBitset(bitset<M> &a, int sft) {
  a = ((a << sft) & tot) | ((a >> (m - sft)));
}

void push(int v, int tl, int tr) {
  lazy[v] %= m;
  if (!lazy[v]) return;
  shiftBitset(t[v], lazy[v]);
  if (tl < tr) {
    lazy[2 * v] = (lazy[2 * v] + lazy[v]) % m;
    lazy[2 * v + 1] = (lazy[2 * v + 1] + lazy[v]) % m;
  }
  lazy[v] = 0;
}

void shift(int v, int tl, int tr, int l, int r, int x) {
  push(v, tl, tr);
  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    lazy[v] += x;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  shift(2 * v, tl, tm, l, r, x);
  shift(2 * v + 1, tm + 1, tr, l, r, x);
  t[v] = t[2 * v] | t[2 * v + 1];
}

void add(int l, int r, int x) {
  shift(1, 1, n, l, r, x);
}

bitset<M> sol;

void gather(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    sol |= t[v];
    return;
  }
  int tm = (tl + tr) / 2;
  gather(2 * v, tl, tm, l, r);
  gather(2 * v + 1, tm + 1, tr, l, r);
}

void place(int l, int r) {
  sol = 0;
  gather(1, 1, n, l, r);
}

bool prie(int x) {
  if (x <= 1) return 0;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}

bitset<M> pr;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  for (int i = 0; i < 4 * N; i++) {
    t[i][0] = 1;
  }

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    tot[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    cin >> init[i];
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    v[i] = init[nodes[i]] % m;
    add(i, i, v[i]);
  }
  for (int i = 1; i < m; i++) {
    if (prie(i)) pr[i] = 1;
  }
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int v, x;
      cin >> v >> x;
      add(ll[v], rr[v], x);
    } else {
      int v;
      cin >> v;
      place(ll[v], rr[v]);
      cout << (sol & pr).count() << "\n";
    }
  }

  return 0;
}
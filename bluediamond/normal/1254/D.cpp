#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
///#define int ll
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

const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int N = 150000 + 7;
int n, q, l[N], r[N], par[N], t, sub[N];
vector<int> g[N];
int aib[N];

void add_aib(int i, int x) {
  while (i <= n) {
    aib[i] = add(aib[i], x);
    i += i & (-i);
  }
}

int get_aib(int i) {
  int ret = 0;
  while (i) {
    ret = add(ret, aib[i]);
    i -= i & (-i);
  }
  return ret;
}

void build(int a, int p = 0) {
  par[a] = p;
  sub[a] = 1;
  l[a] = ++t;
  vector<int> kids;
  for (auto &b : g[a]) {
    if (b == p) continue;
    kids.push_back(b);
    build(b, a);
    sub[a] += sub[b];
  }
  g[a] = kids;
  r[a] = t;
}

int coef(int x, int y) {
  if (x == y) return n;
  if (y == par[x]) {
    return sub[x];
  } else {
    return n - sub[y];
  }
}

void add(int x, int y, int val) {
  if (y == par[x]) {
    add_aib(1, val);
    add_aib(l[x], add(0, -val));
    add_aib(r[x] + 1, val);
  } else {
    add_aib(l[y], val);
    add_aib(r[y] + 1, add(0, -val));
  }
}

ll get(int node) {
  return get_aib(l[node]);
}

const int K = 400;
int spec[N], id, vertex[K][N], lmao[K], who[K];

void dfs(int i, int p, int sol) {
  vertex[id][i] = sol;
  for (auto &j : g[i]) {
    if (j != p) dfs(j, i, sol);
  }
}

signed realMain() {
  cin >> n >> q;
  int rad = sqrt(n);
  if (home) rad = 1;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if ((int) g[i].size() >= rad) {
      id++;
      who[id] = i;
      spec[i] = id;
      assert(id <= 390);
      for (auto &j : g[i]) dfs(j, i, j);
    }
  }
  int inv = dv(1, n);
  build(1);
  for (int it = 1; it <= q; it++) {
    int type;
    cin >> type;
    if (type == 1) {
      int v, d;
      cin >> v >> d;
      if (spec[v]) {
        v = spec[v];
        lmao[v] = add(lmao[v], d);
        continue;
      }
      for (auto &v2 : g[v]) {
        add(v, v2, mul(d, coef(v, v2)));
      }
      if (v > 1) {
        int v2 = par[v];
        add(v, v2, mul(d, coef(v, v2)));
      }
      add_aib(l[v], mul(d, n));
      add_aib(l[v] + 1, add(0, -mul(d, n)));
    } else {
      int v;
      cin >> v;
      int ret = get(v);
      for (int j = 1; j <= id; j++) {
        ret = add(ret, mul(lmao[j], coef(who[j], vertex[j][v])));
      }
      ret = mul(ret, inv);
      cout << ret << "\n";
    }
  }
  return 0;
}
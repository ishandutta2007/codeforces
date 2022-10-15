#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = (int) 1e5 + 7;
const int INF = (int) 1e18;
const int K = 20;
int n, len, s, w[N], par[K][N], sum[K][N], dep[N], go[N], l[N], r[N], top, ord[N];

vector<int> g[N];

void dfs(int a) {
  l[a] = ++top;
  ord[top] = a;
  for (auto &b : g[a]) {
    dep[b] = 1 + dep[a];
    dfs(b);
  }
  r[a] = top;
}

int dp[N], sumdp[N];

int rec(int root, int a, int cur) {
  if (dep[root] < go[a]) return INF;
  cur += sumdp[a] - dp[a];
  int sol = cur + 1;
  for (auto &b : g[a]) {
    sol = min(sol, rec(root, b, cur));
  }
  return sol;
}

pair<int, int> t[4 * N];
int lazy[4 * N];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = {0, tl};
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
  }
}

void push(int v, int tl, int tr) {
  if (!lazy[v]) return;
  t[v].first += lazy[v];
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
  t[v] = min(t[2 * v], t[2 * v + 1]);
}

pair<int, int> getmin(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) return {INF, 0};
  if (l <= tl && tr <= r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return min(getmin(2 * v, tl, tm, l, r), getmin(2 * v + 1, tm + 1, tr, l, r));
}

bool inactive[N];

void solve(int a) {
  if (g[a].empty()) {
    dp[a] = 1;
    add(1, 1, n, l[a], l[a], -1);
    return;
  }
  for (auto &b : g[a]) {
    solve(b);
    sumdp[a] += dp[b];
  }
  dp[a] = INF;
  while (1) {
    auto it = getmin(1, 1, n, l[a], r[a]);
    int j = it.second;
    assert(inactive[j] == 0);
    if (dep[a] < go[ord[j]]) {
      if (j == l[a]) {
        cout << "what\n";
        exit(0);
      }
      inactive[j] = 1;
      add(1, 1, n, j, j, (int) 1e9);
    } else {

     dp[a] = it.first;
     break;
    }
  }
  dp[a] += sumdp[a] + 1;
  add(1, 1, n, l[a], r[a], sumdp[a] - dp[a]);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  cin >> n >> len >> s;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    sum[0][i] = w[i];
  }
  for (int i = 2; i <= n; i++) {
    cin >> par[0][i];
    g[par[0][i]].push_back(i);
  }
  build(1, 1, n);

  for (int i = 1; i <= n; i++) {
    if (w[i] > s) {
      cout << "-1\n";
      return 0;
    }
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i <= n; i++) {
      par[k][i] = par[k - 1][par[k - 1][i]];
      sum[k][i] = sum[k - 1][i] + sum[k - 1][par[k - 1][i]];
    }
  }
  dep[1] = 1;
  dfs(1);

  for (int i = 1; i <= n; i++) {
    int curs = 0, vertex = i, kek = 0;
    for (int k = K - 1; k >= 0; k--) {
      if ((1 << k) > dep[vertex]) continue;

      int p2 = par[k][vertex];
      int addup = sum[k][vertex];

      if (curs + addup <= s) {
        curs += addup;
        kek += (1 << k);
        vertex = p2;
      }
    }
    go[i] = dep[i] - min(kek, len) + 1;
    assert(go[i] <= dep[i]);
   /// cout << i << " : " << go[i] << "\n";
  }

  solve(1);

  cout << dp[1] << "\n";

  return 0;
}
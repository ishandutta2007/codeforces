#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e5 + 7;
const int K = 19;
int n, m, q, t[K][N], l[N], r[N], top;
vector<int> so[K][N];
vector<int> g[N], here[N];

vector<int> mergeso(vector<int> a, vector<int> b) {
  vector<int> c;
  int pt = 0;
  for (auto &x : a) {
    while (pt < (int) b.size() && b[pt] <= x) {
      c.push_back(b[pt++]);
      if ((int) c.size() == 10) return c;
    }
    c.push_back(x);
    if ((int) c.size() == 10) return c;
  }
  while (pt < (int) b.size()) {
    c.push_back(b[pt++]);
    if ((int) c.size() == 10) return c;
  }
  return c;
}

void dfs(int a, int p = 0) {
  t[0][a] = p;
  l[a] = ++top;
  for (auto &b : g[a]) {
    if (b == p) continue;
    dfs(b, a);
  }
  r[a] = top;
}

vector<int> sol;

int getlca(int a, int b) {
  if (a == b) {
    sol = here[a];
    return a;
  }
  if (l[a] <= l[b] && l[b] <= r[a]) {
    for (int k = K - 1; k >= 0; k--) {
      if (t[k][b] && !((l[t[k][b]] <= l[a] && l[a] <= r[t[k][b]]))) {
        sol = mergeso(sol, so[k][b]);
        b = t[k][b];
      }
    }
    sol = mergeso(sol, here[a]);
    sol = mergeso(sol, here[b]);
    return a;
  }
  if (l[b] <= l[a] && l[a] <= r[b]) {
    swap(a, b);
    for (int k = K - 1; k >= 0; k--) {
      if (t[k][b] && !((l[t[k][b]] <= l[a] && l[a] <= r[t[k][b]]))) {
        sol = mergeso(sol, so[k][b]);
        b = t[k][b];
      }
    }
    sol = mergeso(sol, here[a]);
    sol = mergeso(sol, here[b]);
    return a;
  }
  for (int k = K - 1; k >= 0; k--) {
    if (t[k][a] && !((l[t[k][a]] <= l[b] && l[b] <= r[t[k][a]]))) {
      sol = mergeso(sol, so[k][a]);
      a = t[k][a];
    }
    if (t[k][b] && !((l[t[k][b]] <= l[a] && l[a] <= r[t[k][b]]))) {
      sol = mergeso(sol, so[k][b]);
      b = t[k][b];
    }
  }
  sol = mergeso(sol, here[a]);
  sol = mergeso(sol, here[b]);
  a = t[0][a];
  b = t[0][b];
  assert(a == b);
  sol = mergeso(sol, here[a]);
  return a;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

///  freopen ("input", "r", stdin);

  cin >> n >> m >> q;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= m; i++) {
    int city;
    cin >> city;
    here[city].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    sort(here[i].begin(), here[i].end());
    here[i].resize(min(10, (int) here[i].size()));
    so[0][i] = here[i];
  }

  dfs(1);
  for (int k = 1; k < K; k++) {
    for (int i = 1; i <= n; i++) {
      t[k][i] = t[k - 1][t[k - 1][i]];
      so[k][i] = mergeso(so[k - 1][i], so[k - 1][t[k - 1][i]]);
    }
  }



  while (q--) {
    int a, b, cnt, c;
    cin >> a >> b >> cnt;
    sol.clear();
    c = getlca(a, b);
    sol.resize(min((int) sol.size(), cnt));
    cout << (int) sol.size() << " ";
    for (auto &i : sol) {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}

/**

**/
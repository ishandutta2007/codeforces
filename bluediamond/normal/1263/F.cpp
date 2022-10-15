#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N = 2000 + 7;
int n, tot[2], lca_memo[2][N][N], dep[2][N], par[2][N], la[2][N];
vector<int> g[2][N];
int con[2][N];

int lca(int it, int a, int b) {
  if (a == b) return a;
  if (a > b) swap(a, b);
  if (lca_memo[it][a][b] != -1) return lca_memo[it][a][b];
  int ret;
  if (dep[it][a] > dep[it][b]) ret = lca(it, par[it][a], b);
  else ret = lca(it, a, par[it][b]);
  lca_memo[it][a][b] = ret;
  return ret;
}

void dfs(int it, int a) {
  if (!con[it][a]) con[it][a] = (int) 1e9;
  for (auto &b : g[it][a]) {
    par[it][b] = a;
    dep[it][b] = 1 + dep[it][a];
    dfs(it, b);
    con[it][a] = min(con[it][a], con[it][b]);
  }
}

void rebuild(int it, int a) {
  if (g[it][a].empty()) return;
  for (auto &b : g[it][a]) rebuild(it, b);
  vector<pair<int, int>> kids;
  for (auto &b : g[it][a]) kids.push_back({con[it][b], b});
  sort(kids.begin(), kids.end());
  g[it][a].clear();
  for (auto &b : g[it][a]) g[it][a].push_back(a);
}

map<vector<int>, int> memo;

int best(int pos, int last1, int last2) {
  if (pos > n) {
    return 0;
  }
  if (memo.count({pos, last1, last2})) {
    return memo[{pos, last1, last2}];
  }
  assert(last1 == pos - 1 || last2 == pos - 1);
  int ret = (int) 1e9;
  /// we put right now 1 so we go to best(pos + 1, pos, last2)
  if (last1 == -1) {
    ret = min(ret, best(pos + 1, pos, last2) + dep[0][la[0][pos]]);
  } else {
    ret = min(ret, best(pos + 1, pos, last2) + dep[0][la[0][pos]] - dep[0][lca(0, la[0][pos], la[0][last1])]);
  }
  /// we put right now 2 so we go to best(pos + 1, last1, pos)
    if (last1 == -1) {
    ret = min(ret, best(pos + 1, last1, pos) + dep[1][la[1][pos]]);
  } else {
    ret = min(ret, best(pos + 1, last1, pos) + dep[1][la[1][pos]] - dep[1][lca(1, la[1][pos], la[1][last2])]);
  }
  memo[{pos, last1, last2}] = ret;
  return ret;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) lca_memo[0][i][j] = lca_memo[1][i][j] = -1;
  cin >> n;
  for (int it = 0; it < 2; it++) {
    cin >> tot[it];
    for (int i = 2; i <= tot[it]; i++) {
      int par;
      cin >> par;
      g[it][par].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
      int who;
      cin >> who;
      con[it][who] = i;
      la[it][i] = who;
    }
  }
  dfs(0, 1);
  dfs(1, 1);
  rebuild(0, 1);
  rebuild(1, 1);
  cout << tot[0] + tot[1] - best(1, 0, 0) - 2 << "\n";
  ///cout << best(1, 0, 0) << "\n";
}
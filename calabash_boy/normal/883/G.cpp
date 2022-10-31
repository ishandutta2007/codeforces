#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 300300;
vector<pair<int, int>> g[maxn];
bool used[maxn];
string str;

int dfs1(int u) {
  used[u] = true;
  int res = 1;
  for (auto p : g[u]) {
    int v = p.first;
    int e = p.second;
    if (used[v])
      continue;
    if (e > 0)
      str[e - 1] = '+';
    else if (e < 0)
      str[-e - 1] = '-';
    res += dfs1(v);
  }
  return res;
}

int dfs2(int u) {
  used[u] = true;
  int res = 1;
  for (auto p : g[u]) {
    int v = p.first;
    int e = p.second;
    if (used[v])
      continue;
    if (e > 0)
      str[e - 1] = '-';
    else if (e < 0)
      str[-e - 1] = '+';
    if (e == 0)
      res += dfs2(v);
  }
  return res;
}

signed main() {
#ifdef LOCAL
  assert(freopen("g.in", "r", stdin));
#endif
  int n, m, s;
  cin >> n >> m >> s;
  --s;
  int es = 0;
  for (int i = 0; i < m; ++i) {
    int t, u, v;
    cin >> t >> u >> v;
    --u, --v;
    if (t == 1) {
      g[u].emplace_back(v, 0);
    } else {
      ++es;
      g[u].emplace_back(v, es);
      g[v].emplace_back(u, -es);
    }
  }
  str.resize(es, '+');
  cout << dfs1(s) << '\n';
  cout << str << '\n';
  memset(used, 0, sizeof(used));
  cout << dfs2(s) << '\n';
  cout << str << '\n';
}
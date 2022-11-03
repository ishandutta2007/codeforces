#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int ans[300005];

vector<int> g[300005];

int sz[300005], up[19][300005], h[300005];

int dfs(int v, int p = -1, int hh = 0) {
  h[v] = hh;
  up[0][v] = p;
  for (int i = 1; i < 19; ++i) {
    if (up[i - 1][v] == -1) break;
    up[i][v] = up[i - 1][up[i - 1][v]];
  }
  sz[v] = 1;
  for (int u : g[v])
    sz[v] += dfs(u, v, hh + 1);
  return sz[v];
}

vector<pair<int, int>> ins[300005];

pair<int, int> go(int v) {
  int mx = 0;
  pair<int, int> ret(1e+9, -1);
  for (int u : g[v]) {
    ret = min(ret, go(u));
    mx = max(mx, sz[u]);
  }

  int x = v;
  for (int i = 18; i >= 0; --i) {
    if (up[i][x] == -1) continue;
    if (sz[up[i][x]] < 2 * mx) x = up[i][x]; 
  }
  if (sz[x] < 2 * mx) x = up[0][x];

  if (x != -1 && sz[x] >= 2 * mx) {
    int L = x;
    for (int i = 18; i >= 0; --i) {
      if (up[i][x] == -1) continue;
      if (sz[up[i][x]] >= 2 * max(mx, sz[up[i][x]] - sz[v])) x = up[i][x]; 
    }

    if (sz[x] >= 2 * max(mx, sz[x] - sz[v]) && sz[L] >= 2 * max(mx, sz[L] - sz[v])) {
      int R = x;
      // cout << v << "  " << L << " " << R << endl;
      ins[L].push_back({h[R], v});
    } 
  }
  for (auto x : ins[v]) ret = min(ret, x);
  ans[v] = ret.second + 1;
  return ret;
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i < n; ++i) {
    int a;
    scanf("%d", &a); --a;
    g[a].push_back(i);
  }

  memset(up, -1, sizeof(up));
  dfs(0);

  memset(ans, -1, sizeof(ans));
  go(0);

  while (q--) {
    int a;
    scanf("%d", &a);
    printf("%d\n", ans[a - 1]);
  }
  return 0;
}
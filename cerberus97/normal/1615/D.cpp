/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

struct edge_t {
  int u, v, og, c;
};

bool check(vector<vector<pii>>& g, int u, vector<int>& color);

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<edge_t> edges(n - 1);
    vector<vector<pii>> g(n + 1);
    for (auto& e : edges) {
      cin >> e.u >> e.v >> e.og;
      if (e.og == -1) {
        e.c = -1;
      } else {
        e.c = __builtin_popcount(e.og) % 2;
        g[e.u].pb({e.v, e.c});
        g[e.v].pb({e.u, e.c});
      }
    }
    while (m--) {
      int u, v, p;
      cin >> u >> v >> p;
      g[u].pb({v, p});
      g[v].pb({u, p});
    }
    vector<int> color(n + 1, -1);
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
      if (color[i] == -1) {
        color[i] = 0;
        ok &= check(g, i, color);
      }
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (auto& e : edges) {
      if (e.og == -1) {
        e.og = (color[e.u] ^ color[e.v]);
      }
      cout << e.u << ' ' << e.v << ' ' << e.og << '\n';
    }
  }
}

bool check(vector<vector<pii>>& g, int u, vector<int>& color) {
  bool ok = true;
  for (auto& [v, e] : g[u]) {
    if (color[v] == -1) {
      color[v] = color[u] ^ e;
      ok &= check(g, v, color);
    }
    ok &= (color[v] == (color[u] ^ e));
  }
  return ok;
}
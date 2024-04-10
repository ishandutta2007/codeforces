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
const ll inf = 1e18 + 42;

struct edge_t {
  ll u, v, w;
};

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<edge_t> edges(m);
    vector<vector<int>> g(n);
    vector<vector<int>> dist(n, vector<int>(n, n + 1));
    vector<ll> cheapest(n, inf);
    for (auto& e : edges) {
      cin >> e.u >> e.v >> e.w;
      --e.u; --e.v;
      g[e.u].pb(e.v);
      g[e.v].pb(e.u);
      dist[e.u][e.v] = dist[e.v][e.u] = min(dist[e.u][e.v], 1);
      cheapest[e.u] = min(cheapest[e.u], e.w);
      cheapest[e.v] = min(cheapest[e.v], e.w);
    }
    for (int i = 0; i < n; ++i) {
      dist[i][i] = 0;
    }
    for (int k = 0; k < n; ++k) {
      for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
          if (dist[u][k] + dist[k][v] < dist[u][v]) {
            dist[u][v] = dist[u][k] + dist[k][v];
          }
        }
      }
    }

    ll ans = inf;
    for (auto& e : edges) {
      ll min_wires = min(dist[0][e.u] + dist[n - 1][e.v], dist[0][e.v] + dist[n - 1][e.u]) + 1;
      ans = min(ans, min_wires * e.w);
    }
    for (int c = 0; c < n; ++c) {
      for (int u = 0; u < n; ++u) {
        ll len = dist[c][0] + dist[c][n - 1] + dist[c][u] + 2;
        ans = min(ans, len * cheapest[u]);
      }
    }
    cout << ans << '\n';
  }
}
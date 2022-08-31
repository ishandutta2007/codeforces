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

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    vector<bool> picked(n + 1, 0);
    vector<int> dist(n + 1, n + 1);
    dist[1] = 0;
    picked[1] = true;
    vector<int> ans = {1};
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto& v : g[u]) {
        if (dist[v] == n + 1) {
          bool can_pick = true;
          for (auto& w : g[v]) {
            if (picked[w]) {
              can_pick = false;
            }
          }
          if (can_pick) {
            ans.pb(v);
            picked[v] = true;
          }
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
      ok &= (dist[i] <= n);
    }
    if (ok) {
      cout << "YES\n";
      cout << ans.size() << '\n';
      for (auto& u : ans) {
        cout << u << ' ';
      }
      cout << '\n';
    } else {
      cout << "NO\n";
    }
  }
}
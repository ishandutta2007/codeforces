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

const int N = 3e5 + 10;

vector<int> g[N], t[N];
bool seen[N];

void dfs1(int u);
bool dfs2(int u, int v, vector<int>& path);

int main() {
  fast_cin();
  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  vector<int> active(n + 1, 0);
  int q; cin >> q;
  vector<pii> paths(q);
  for (auto& [u, v] : paths) {
    cin >> u >> v;
    active[u] ^= 1;
    active[v] ^= 1;
  }
  int cnt = accumulate(active.begin(), active.end(), 0);
  if (cnt) {
    cout << "NO\n";
    cout << cnt / 2 << '\n';
  } else {
    cout << "YES\n";
    dfs1(1);
    for (auto& [u, v] : paths) {
      vector<int> path;
      for (int i = 1; i <= n; ++i) {
        seen[i] = false;
      }
      dfs2(u, v, path);
      cout << path.size() << ' ';
      for (auto& x : path) {
        cout << x << ' ';
      }
      cout << '\n';
    }
  }
}

void dfs1(int u) {
  seen[u] = true;
  for (auto& v : g[u]) {
    if (!seen[v]) {
      t[u].pb(v);
      t[v].pb(u);
      dfs1(v);
    }
  }
}

bool dfs2(int u, int v, vector<int>& path) {
  seen[u] = true;
  path.pb(u);
  if (u == v) {
    return true;
  }
  for (auto& w : t[u]) {
    if (!seen[w] and dfs2(w, v, path)) {
      return true;
    }
  }
  path.pop_back();
  return false;
}
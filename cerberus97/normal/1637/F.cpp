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

const int N = 2e5 + 10;

vector<int> g[N];
ll h[N];

ll solve(int root);
pll dfs(int u, int p);

int main() {
  fast_cin();
  int n; cin >> n;
  int root = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
    if (h[i] > h[root]) {
      root = i;
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  cout << solve(root) << '\n';
}

ll solve(int root) {
  ll ans = 0;
  priority_queue<ll> max_vals;
  max_vals.push(0);
  max_vals.push(0);
  for (auto& u : g[root]) {
    pll vals = dfs(u, root);
    max_vals.push(vals.first);
    ans += vals.second;
  }
  ans += (h[root] - max_vals.top());
  max_vals.pop();
  ans += (h[root] - max_vals.top());
  return ans;
}

pll dfs(int u, int p) {
  ll ans = 0, mx = 0;
  for (auto& v : g[u]) {
    if (v == p) {
      continue;
    }
    pll vals = dfs(v, u);
    mx = max(mx, vals.first);
    ans += vals.second;
  }
  ans += max(0ll, h[u] - mx);
  return {max(h[u], mx), ans};
}
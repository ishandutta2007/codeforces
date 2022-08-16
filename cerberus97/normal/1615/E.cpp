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
const ll inf = 1e18 + 42;

vector<int> g[N];

int solve(int u, int p, multiset<int>& vals);

int main() {
  fast_cin();
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  multiset<int> vals;
  solve(1, 0, vals);
  ll ans = -inf;
  int max_b = n;
  for (ll r = 0; r <= k; ++r) {
    ll b = min(max_b, n / 2);
    ans = max(ans, r * (n - r) - b * (n - b));
    if (!vals.empty()) {
      max_b -= *vals.rbegin();
      vals.erase(vals.find(*vals.rbegin()));
    }
  }
  cout << ans << '\n';
}

int solve(int u, int p, multiset<int>& vals) {
  int mx = 0;
  for (auto& v : g[u]) {
    if (v == p) {
      continue;
    }
    mx = max(mx, solve(v, u, vals));
  }
  if (mx) {
    vals.erase(vals.find(mx));
  }
  ++mx;
  vals.insert(mx);
  return mx;
}
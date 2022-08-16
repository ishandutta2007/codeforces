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

vector<int> g[N];
int ht[N];

void dfs(int u, int p);

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    dfs(1, 0);
    cout << -int(g[1].size()) << ' ';
    for (int i = 2; i <= n; ++i) {
      int x = (ht[i] % 2 == 0) ? -1 : 1;
      int d = int(g[i].size()) - 1;
      cout << x * (d + 1) << ' ';
    }
    cout << '\n';
  }
}

void dfs(int u, int p) {
  for (auto& v : g[u]) {
    if (v != p) {
      ht[v] = ht[u] + 1;
      dfs(v, u);
    }
  }
}
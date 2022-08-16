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
int reqs[N], seen[N];

bool no_cycle(int u);

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
      seen[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      int k; cin >> k;
      reqs[i] = k;
      while (k--) {
        int u; cin >> u;
        g[u].pb(i);
      }
    }
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
      if (!seen[i]) {
        ok &= no_cycle(i);
      }
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    set<int> s;
    for (int i = 1; i <= n; ++i) {
      if (reqs[i] == 0) {
        s.insert(i);
      }
    }
    int ans = 0, cur = n + 1;
    while (!s.empty()) {
      auto it = s.lower_bound(cur);
      if (it == s.end()) {
        cur = 1;
        ++ans;
      } else {
        int u = *it;
        s.erase(it);
        cur = u;
        for (auto& v : g[u]) {
          --reqs[v];
          if (reqs[v] == 0) {
            s.insert(v);
          }
        }
      }
    }
    cout << ans << '\n';
  }
}

bool no_cycle(int u) {
  seen[u] = 1;
  for (auto& v : g[u]) {
    if (seen[v] == 2) {
      continue;
    } else if (seen[v] == 1) {
      return false;
    } else if (!no_cycle(v)) {
      return false;
    }
  }
  seen[u] = 2;
  return true;
}
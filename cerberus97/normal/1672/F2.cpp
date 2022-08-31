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

bool has_cycle(int u, vector<vector<int>>& g, vector<int>& seen);

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& i : a) {
      cin >> i;
    }
    for (auto& i : b) {
      cin >> i;
    }
    map<int, int> cnt;
    for (auto& i : a) {
      ++cnt[i];
    }
    int mx = -1, mxc = 0;
    map<int, int> id;
    int nid = n;
    for (auto& [k, v] : cnt) {
      if (v > mxc) {
        mxc = v;
        mx = k;
      }
      id[k] = nid++;
    }
    vector<vector<int>> g(nid);
    auto add_edge = [&](int u, int v) {
      g[u].pb(v);
    };
    for (int i = 0; i < n; ++i) {
      if (a[i] != mx) {
        add_edge(i, id[a[i]]);
      }
      if (b[i] != mx) {
        add_edge(id[b[i]], i);
      }
    }
    bool ok = true;
    vector<int> seen(nid, 0);
    for (int i = 0; i < nid; ++i) {
      if (seen[i]) {
        continue;
      } else if (has_cycle(i, g, seen)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "AC\n";
    } else {
      cout << "WA\n";
    }
  }
}

bool has_cycle(int u, vector<vector<int>>& g, vector<int>& seen) {
  seen[u] = 1;
  for (auto& v : g[u]) {
    if (seen[v] == 2) {
      continue;
    } else if (seen[v] == 1) {
      return true;
    } else if (has_cycle(v, g, seen)) {
      return true;
    }
  }
  seen[u] = 2;
  return false;
}
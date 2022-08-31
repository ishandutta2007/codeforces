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

const int N = 1e3 + 10;

int par[N], sz[N];
multiset<int> s;

int get_root(int u);
bool merge(int u, int v);

int main() {
  fast_cin();
  int n, d;
  cin >> n >> d;
  vector<pii> q(d);
  for (auto& [x, y] : q) {
    cin >> x >> y;
  }
  for (int i = 1; i <= n; ++i) {
    par[i] = i;
    sz[i] = 1;
    s.insert(1);
  }
  int extra = 0;
  for (auto& [x, y] : q) {
    if (!merge(x, y)) {
      ++extra;
    }
    ll sum = 0, need = extra + 1;
    for (auto i = s.rbegin(); i != s.rend() and need; ++i, --need) {
      sum += *i;
    }
    cout << sum - 1 << '\n';
  }
}

int get_root(int u) {
  if (u != par[u]) {
    par[u] = get_root(par[u]);
  }
  return par[u];
}

bool merge(int u, int v) {
  u = get_root(u);
  v = get_root(v);
  if (u == v) {
    return false;
  } else if (sz[u] < sz[v]) {
    swap(u, v);
  }
  s.erase(s.find(sz[u]));
  s.erase(s.find(sz[v]));
  s.insert(sz[u] + sz[v]);
  sz[u] += sz[v];
  par[v] = u;
  return true;
}
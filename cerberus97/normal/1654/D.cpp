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

const int N = 2e5 + 10, inf = 1e9 + 42, mod = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}

int mul(ll a, int b) {
  return (a * b) % mod;
}

int pwr(int x, int e) {
  int res = 1;
  while (e) {
    if (e & 1) {
      res = mul(res, x);
    }
    e /= 2;
    x = mul(x, x);
  }
  return res;
}

int divd(int a, int b) {
  return mul(a, pwr(b, mod - 2));
}

void dfs1(int u, int p);
void dfs2(int u, int p);

vector<pair<int, pii>> g[N];
int cnt[N], mn[N];
vector<int> pfactor(N);
int prod, ans;

int main() {
  fast_cin();
  vector<bool> prime(N, true);
  prime[0] = prime[1] = false;
  for (int p = 2; p < N; ++p) {
    if (!prime[p]) {
      continue;
    }
    pfactor[p] = p;
    for (int i = 2 * p; i < N; i += p) {
      prime[i] = false;
      pfactor[i] = p;
    }
  }
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
      cnt[i] = 0;
      mn[i] = inf;
    }
    for (int i = 0; i < n - 1; ++i) {
      int u, v, x, y;
      cin >> u >> v >> x >> y;
      g[u].pb({v, {y, x}});
      g[v].pb({u, {x, y}});
    }
    dfs1(1, 0);
    prod = 1;
    for (int p = 1; p <= n; ++p) {
      if (mn[p] < 0) {
        prod = mul(prod, pwr(p, -mn[p]));
      }
    }
    ans = prod;
    dfs2(1, 0);
    cout << ans << '\n';
  }
}

void dfs1(int u, int p) {
  for (auto& [v, e] : g[u]) {
    if (v == p) {
      continue;
    }
    int x = e.first, y = e.second;
    while (x > 1) {
      ++cnt[pfactor[x]];
      mn[pfactor[x]] = min(mn[pfactor[x]], cnt[pfactor[x]]);
      x /= pfactor[x];
    }
    while (y > 1) {
      --cnt[pfactor[y]];
      mn[pfactor[y]] = min(mn[pfactor[y]], cnt[pfactor[y]]);
      y /= pfactor[y];
    }
    dfs1(v, u);
    x = e.first; y = e.second;
    while (y > 1) {
      ++cnt[pfactor[y]];
      y /= pfactor[y];
    }
    while (x > 1) {
      --cnt[pfactor[x]];
      x /= pfactor[x];
    }
  }
}

void dfs2(int u, int p) {
  for (auto& [v, e] : g[u]) {
    if (v == p) {
      continue;
    }
    int x = e.first, y = e.second;
    prod = mul(prod, x);
    prod = divd(prod, y);
    ans = add(ans, prod);
    dfs2(v, u);
    prod = mul(prod, y);
    prod = divd(prod, x);
  }
}
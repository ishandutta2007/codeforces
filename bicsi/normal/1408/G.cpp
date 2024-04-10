#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int kMod = 998244353;

struct DSU {
  int n;
  vector<vector<int>> M;
  vector<int> link;
  vector<vector<ll>> dp;
  vector<int> sz, ez;

  DSU(int n) : n(n), link(n, -1), 
    dp(n, vector<long long>(1, 1)), sz(n, 1), ez(n, 0) {}

  vector<ll> combine(const vector<ll>& a, const vector<ll>& b) {
    vector<ll> ret(a.size() + b.size(), 0);
    for (int i = 0; i < (int)a.size(); ++i)
      for (int j = 0; j < (int)b.size(); ++j) 
        ret[i + j + 1] = (ret[i + j + 1] + a[i] * b[j]) % kMod;
    return ret;
  }

  int Find(int x) {
    if (link[x] == -1) return x;
    return link[x] = Find(link[x]);
  }

  void Union(int a, int b) {
    a = Find(a); b = Find(b);
    if (a != b) {
      link[a] = b;
      dp[b] = combine(dp[a], dp[b]);
      sz[b] += sz[a];
      ez[b] += ez[a];
    }
    ez[b] += 1;
    if (ez[b] == sz[b] * (sz[b] - 1) / 2)
      dp[b][0] = 1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;

  vector<vector<int>> m(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> m[i][j];
    }
  }

  vector<pair<int, int>> all(n * (n - 1) / 2);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j)
      all[m[i][j] - 1] = {i, j};
  }

  DSU dsu(n);
  for (auto [i, j] : all) 
    dsu.Union(i, j);

  for (auto x : dsu.dp[dsu.Find(0)])
    cout << x << " ";
  cout << '\n';

  return 0;
}
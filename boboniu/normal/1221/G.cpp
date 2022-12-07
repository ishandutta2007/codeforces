#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>(0));
  vector<long long> g(n);
  for (int i = 0; i < n; i++) {
  	g[i] = 1ll << i;
  }
  for (int i = 0; i < m; i++) {
  	int x, y;
  	cin >> x >> y;
  	--x;
  	--y;
  	adj[x].push_back(y);
  	adj[y].push_back(x);
  	g[x] |= 1ll << y;
  	g[y] |= 1ll << x;
  }
  if (m == 0) {
    cout << 0 << "\n";
  	return 0;
  }

  long long ans = 1ll << n;

  map<long long, long long> dp;
  function<long long(long long)> solve1 = [&](long long mask) {
	if (mask == 0) return 1ll;
	if (dp.count(mask)) return dp[mask];
	int id = __builtin_ctzll(mask);
	assert( mask & (1ll<<id));
	return dp[mask] = solve1(mask - (1ll << id)) + solve1(mask - (mask & g[id]));
  };

  auto solve3 = [&]() {
  	int isolated = 0;
  	for (int i = 0; i < n; i++) {
  	  if ((int) adj[i].size() == 0) isolated++;
  	}
  	return 1ll << isolated;
  };

  auto solve2 = [&]() {
    vector<int> col(n, -1);
    function<void(int)> dfs = [&](int x) {
      for (auto y : adj[x]) {
        if (col[y] == -1) {
          col[y] = 3 - col[x];
          dfs(y);
        }
      }
  	};
  	int component = 0;
  	for (int i = 0; i < n; i++) if (col[i] == -1) {
  	  col[i] = 1;
  	  dfs(i);
  	  component++;
  	}
  	bool bipar = 1;
  	for (int x = 0; x < n; x++)
  	  for (auto y : adj[x]) {
  	  	if (col[x] == col[y]) bipar = 0;
  	  }

  	if (bipar) return 0ll;
  	else return 1ll << component;
  };
  ans -= 2 * solve1((1ll << n) - 1);
  ans -= solve2();
  ans += 2 * solve3();
  cout << ans << "\n";
  return 0;
}
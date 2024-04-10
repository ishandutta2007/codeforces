#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1e9+7, N=100100;
map<ll, int> mp[N];
vector<int> adj[N];
ll val[N], ans, n;

void dfs(int u, int p) {
	for (auto& pr : mp[p]) {
		mp[u][__gcd(pr.first, val[u])] += pr.second;
	}
	mp[u][val[u]]++;
	for (auto& pr : mp[u]) {
		ans = (ans+pr.first*pr.second)%MOD;
	}
	for (auto& v : adj[u]) {
		if (v==p) continue;
		dfs(v, u);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> val[i];
	}
	for (int i=1; i<=n-1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	cout << ans << "\n";
	return 0;
}
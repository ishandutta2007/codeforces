#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

vector<pll> G[303030];
queue<ll> Q;
ll U[303030], A[303030], C[303030];
ll n, m, s, x;

ll find(ll u) { return u == U[u] ? u : U[u] = find(U[u]); }

void merge(ll u, ll v) {
	u = find(u); v = find(v);
	if (G[u].size() < G[v].size()) swap(u, v);
	U[v] = u; A[u] += A[v];
	for (; !G[v].empty(); G[v].pop_back()) G[u].push_back(G[v].back());
}

void tc() {
	ll i, u, v;
	cin >> n >> m >> x;
	for (i = 1; i <= n; i++) {
		cin >> A[i]; A[i] -= x;
		s += A[i];
		if (A[i] >= 0) Q.push(i);
	}

	if (s < -x) {
		cout << "NO\n";
		return;
	}

	for (i = 1; i <= m; i++) {
		cin >> u >> v;
		G[u].emplace_back(v, i);
		G[v].emplace_back(u, i);
	}

	cout << "YES\n";

	iota(U, U + n + 1, 0);
	for (; !Q.empty(); ) {
		u = Q.front(); Q.pop();
		u = find(u);
		if (A[u] >= 0) {
			for (; !G[u].empty(); ) {
				auto [v, i] = G[u].back(); G[u].pop_back();
				if (C[i] || find(v) == u) continue;
				merge(u, v);
				cout << i << "\n"; C[i] = 1;
				u = find(u);
				if (A[u] >= 0) Q.push(u);
				break;
			}
		}
	}

	for (i = 1; i <= n; i++) {
		for (auto [v, j]: G[i]) {
			if (find(i) != find(v)) {
				cout << j << "\n";
				merge(i, v);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

//	cin >> t;

	for (; t--; ) tc();

	return 0;
}
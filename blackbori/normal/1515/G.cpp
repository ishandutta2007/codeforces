#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

vector<pll> G[202020];
vector<ll> T, V[202020];
ll N[202020], S[202020], A[202020], C[202020], D[202020];
ll n, m, s, dn;

ll dfs(ll u) {
	ll r = N[u] = ++dn;

	T.push_back(u);
	for (auto &[v, _]: G[u]) {
		if (!N[v]) r = min(r, dfs(v));
		else if (!S[v]) r = min(r, N[v]);
	}

	if (r == N[u]) {
		for (s++; !S[u]; T.pop_back()) {
			V[s].push_back(T.back());
			S[T.back()] = s;
		}
	}

	return r;
}

void dfs2(ll u) {
	C[u] = 1;
	for (auto &[v, c]: G[u]) {
		if (S[v] == S[u] && !C[v]) {
			D[v] = D[u] + c;
			dfs2(v);
		}
	}
}

void solve(ll k) {
	dfs2(V[k][0]);
	ll g = 0;
	for (ll &u: V[k]) {
		for (auto &[v, c]: G[u]) if (S[v] == S[u]) {
			g = gcd(g, abs(D[u] + c - D[v]));
		}
	}
	A[k] = g;
//	cout << g << endl;
}

void tc() {
	ll i, u, v, c, q, x, t, g;
	cin >> n >> m;

	for (i = 1; i <= m; i++) {
		cin >> u >> v >> c;
		G[u].emplace_back(v, c);
	}

	for (i = 1; i <= n; i++) {
		if (!N[i]) dfs(i);
	}

	for (i = 1; i <= s; i++) {
		solve(i);
	}

	for (cin >> q; q--; ) {
		cin >> v >> x >> t;
		g = gcd(A[S[v]], t);
		if (gcd(x, g) == g) cout << "YES\n";
		else cout << "NO\n";
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
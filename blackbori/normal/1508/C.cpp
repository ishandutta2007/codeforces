#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using plll = tuple<ll, ll, ll>;

struct uf {
	ll P[202020];
	void init(ll n) { iota(P, P + n + 1, 0); }
	ll find(ll u) { return u == P[u] ? u : P[u] = find(P[u]); }
	void unite(ll u, ll v) { P[find(u)] = find(v); }
};

uf U1, U2, U3;
vector <ll> G[202020];
vector <plll> E, E2;
ll n, m, w, a;

void tc() {
	ll i, t, j, u, v, c, f;
	cin >> n >> m;
	for (w = 0, i = 0; i < m; i++){
		cin >> u >> v >> c; w ^= c;
		E.emplace_back(c, u, v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	sort(E.begin(), E.end());

	for (i = t = 1; i <= n; i ++) {
		sort(G[i].begin(), G[i].end());
		if (G[i].size() < G[t].size()) t = i;
	}

	U1.init(n);
	auto V = G[t]; V.push_back(t);
	for (auto &u: V) {
		for (i = 1, j = 0; i <= n; i++) {
			for (; j < G[u].size() && G[u][j] < i; j++);
			if (j < G[u].size() && G[u][j] == i) continue;
			U1.unite(u, i);
		}
	}

	U2.init(n);
	for (auto &[c, u, v]: E) {
		if (U2.find(u) != U2.find(v)) {
			E2.emplace_back(c, u, v);
			U2.unite(u, v);
		}
	}

	c = 0;
	for (i = 1; i <= n; i++) {
		if (U1.find(i) == i) c++;
	}

	U3 = U1;

	a = 0; f = 0;
	if (n * (n - 1) / 2 - m == n - c) f = 1;

	for (auto &[c, u, v]: E2) {
		if (U3.find(u) != U3.find(v)) {
			U3.unite(u, v); a += c;
		}
		else {
			if (f == 1) {
				a += min(w, c);
				f = 0;
			}
		}
	}

	cout << a << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

//	cin >> t;

	for (; t--; ) tc();

	return 0;
}
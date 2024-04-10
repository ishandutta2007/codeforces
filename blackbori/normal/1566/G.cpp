#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using edge = tuple<ll, ll, ll>;


struct node {
	pll m[3];
	node() { m[0] = m[1] = m[2] = pll(1e18, 1e18); }
	node(pll v[3]) { copy(v, v + 3, m); }
	void merge(node &l, node &n) {
		copy(l.m, l.m + 3, m);
		for(pll v : n.m) {
			if(v.first < m[0].first) swap(v, m[0]);
			if((v.second != m[0].second && v.first < m[1].first)
				|| (m[1].second == m[0].second)) swap(v, m[1]);
			if((v.second != m[0].second && v.second != m[1].second && v.first < m[2].first)
				|| (m[2].second == m[0].second || m[2].second == m[1].second)) swap(v, m[2]);
		}
	}
};

struct segtree {
	node T[262626];
	ll sz = 1 << 17;
	
	void update(ll i, pll v[3]) {
		i += sz; T[i] = node(v);
		for (i >>= 1; i; i >>= 1) {
			T[i].merge(T[i << 1], T[i << 1 | 1]);
		}
	}
} T;

set<edge> E, E2;
set<pll> S[101010];
pll V[101010][3];
ll C[101010];
multiset<ll> A1;
ll n, m;

void solve() {
	ll q, u, v, w, t, i;

	V[0][0] = V[0][1] = V[0][2] = pll(1e18, 0);

	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		S[i].emplace(1e18, 1e18);
		S[i].emplace(2e18, 2e18);
		S[i].emplace(3e18, 3e18);
	}

	for (i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		if (u < v) swap(u, v);
		S[u].emplace(w, v);
		S[v].emplace(w, u);
		E.emplace(u, v, w);
		E2.emplace(w, u, v);
	}

	auto calc = [&](ll i, bool f) {
		if (f) {
			C[i] = 0;
			auto it = S[i].begin();
			for (ll j = 0; j < 3; j++) {
				V[i][j] = *it; C[i] += it->first; it++;
			}
			A1.insert(C[i]);
			T.update(i, V[i]);
		}
		else {
			A1.erase(A1.find(C[i]));
		}
	};

	for (i = 1; i <= n; i++) {
		calc(i, 1);
	}

	auto ans = [&]() {
		ll a = 1e18;
		if (!A1.empty()) a = min(a, *A1.begin());

		auto [w, u, v] = *E2.begin();
//		cout << u << " " << v << " " << w << endl;
		T.update(u, V[0]); T.update(v, V[0]);
		for (auto &t: T.T[1].m) {
//			cout << t.first << " " << t.second << endl;
			if (t.second != u && t.second != v) {
				a = min(a, w + t.first);
			}
		}
		T.update(u, V[u]); T.update(v, V[v]);

		for (int i = 0; i < 3; i++) if (V[u][i].second != v) {
			for (int j = 0; j < 3; j++) if (V[v][j].second != u) {
				if (V[u][i].second != V[v][j].second) {
					a = min(a, V[u][i].first + V[v][j].first);
				}
			}
		}

		return a;
	};

	cout << ans() << "\n";

	cin >> q;
	for (; q--; ) {
		cin >> t >> u >> v;
		if (u < v) swap(u, v);
		if (t == 0) {
			auto it = E.lower_bound(edge(u, v, -1e9));
			w = get<2>(*it);
			E2.erase(edge(w, u, v));
			calc(u, 0), calc(v, 0);
			S[u].erase(pll(w, v)); S[v].erase(pll(w, u));
			calc(u, 1), calc(v, 1);
			E.erase(it);
		}
		else {
			cin >> w; E.emplace(u, v, w);
			E2.emplace(w, u, v);
			calc(u, 0), calc(v, 0);
			S[u].emplace(w, v); S[v].emplace(w, u);
			calc(u, 1), calc(v, 1);
		}

		cout << ans() << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll tc = 1;

//	cin >> tc;

	for (; tc--; ) solve();

	return 0;
}
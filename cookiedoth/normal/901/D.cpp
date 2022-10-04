#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct half_edge {
	ll v, cost;
};

const ll mx = 300000;
ll n, m, c[mx], p[mx], h[mx], used[mx];
vector<ll> g[mx], t[mx], odd;
vector<half_edge> he;

bool dfs(ll v, ll hi, ll pv) {
	p[v] = pv;
	h[v] = hi;
	used[v] = 1;
	for (auto en : g[v]) {
		ll v1 = he[en].v;
		if (used[v1] == 1 && v1 != pv && h[v1] < h[v]) {
			if ((h[v1] - h[v]) % 2 == 0) {
				ll u = v;
				while (u != v1) {
					odd.push_back(u);
					u = p[u];
				}
				odd.push_back(v1);
				return 1;
			}
		}
		else {
			if (used[v1] == 0) {
				if (dfs(v1, hi + 1, v))
					return 1;
			}
		}
	}
	return 0;
}

void build_st(ll v, ll enu) {
	if (enu != -1)
		t[v].push_back(enu);
	used[v] = 1;
	for (auto en : g[v]) {
		ll v1 = he[en].v;
		if (used[v1] == 0) {
			t[v].push_back(en);
			build_st(v1, en ^ 1);
		}
	}
}

ll put_cost(ll v, bool root) {
	cerr << "dfsing " << v << " " << root << endl;
	ll top;
	if (!root)
		top = 1;
	else
		top = 0;
	for (ll i = top; i < t[v].size(); ++i) {
		ll v1 = he[t[v][i]].v;
		ll res = put_cost(v1, 0);
		c[v] -= res;
		he[t[v][i]].cost = res;
	}
	if (!root) {
		he[t[v][0]].cost = c[v];
		ll kek = c[v];
		c[v] = 0;
		//cout << "pushing " << kek << endl;
		return kek;
	}
	else {
		return c[v];
	}
}

void add_cost(ll u, ll v, ll cost) {
	cerr << "adding " << u << " " << v << " " << cost << endl;
	for (auto en : g[u]) {
		ll v1 = he[en].v;
		if (v == v1) {
			he[en].cost += cost;
		}
	}
	for (auto en : g[v]) {
		ll v1 = he[en].v;
		if (u == v1) {
			he[en].cost += cost;
		}
	}
	c[u] -= cost;
	c[v] -= cost;
}

int main() {
	cin >> n >> m;
	for (ll i = 0; i < n; ++i) {
		cin >> c[i];
	}
	for (ll i = 0; i < m; ++i) {
		ll u, v;
		cin >> u >> v;
		u--;
		v--;
		he.push_back({v, 0});
		he.push_back({u, 0});
		g[u].push_back(i * 2);
		g[v].push_back(i * 2 + 1);
	}
	dfs(0, 0, -1);
	if (odd.size() == 0) {
		for (ll i = 0; i < n; ++i) {
			used[i] = 0;
		}
		build_st(0, -1);
		ll res = put_cost(0, 1);
		if (res == 0) {
			cout << "YES" << endl;
			for (ll i = 0; i < m; ++i) {
				cout << he[2 * i].cost << endl;
			}
		}
		else {
			cout << "NO" << endl;
		}
	}
	else {
		cerr << "case odd" << endl;
		for (auto x : odd) {
			cerr << x << " ";
		}
		cerr << endl;
		ll root = odd[0];
		for (ll i = 0; i < n; ++i) {
			used[i] = 0;
		}
		build_st(root, -1);
		ll res = put_cost(root, 1);
		for (ll i = 0; i < m; ++i) {
			cerr << he[2 * i].cost << endl;
		}
		cerr << "end" << endl;
		ll sz = odd.size();
		for (ll i = 0; i < sz - 1; ++i) {
			if (i % 2 == 0) {
				add_cost(odd[i], odd[i + 1], res / 2);
			}
			else {
				add_cost(odd[i], odd[i + 1], -res / 2);
			}
		}
		add_cost(odd[sz - 1], odd[0], res / 2);
		cout << "YES" << endl;
		for (ll i = 0; i < m; ++i) {
			cout << he[2 * i].cost << endl;
		}
	}
}
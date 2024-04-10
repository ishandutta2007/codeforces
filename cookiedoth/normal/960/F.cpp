/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll MOD = 1e9 + 7;

struct st {

	vector<int> t;
	int n;

	st() {}

	void init(int _n) {
		n = _n;
		t.resize(4 * n);
	}

	void update(int pos, int val, int v, int tl, int tr) {
		if (tl == tr)
			t[v] = val;
		else {
			int tm = (tl + tr) / 2;
			if (pos <= tm)
				update(pos, val, v * 2, tl, tm);
			else
				update(pos, val, v * 2 + 1, tm + 1, tr);
			t[v] = max(t[v * 2], t[v * 2 + 1]);
		}
	}

	int get(int l, int r, int v, int tl, int tr) {
		if (l > r)
			return 0;
		if (l == tl && r == tr)
			return t[v];
		int tm = (tl + tr) / 2;
		int res_l = get(l, min(r, tm), v * 2, tl, tm);
		int res_r = get(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
		return max(res_l, res_r);
	}

	void update(int pos, int val) {
		update(pos, val, 1, 0, n - 1);
	}

	int get(int l, int r) {
		int res = get(l, r, 1, 0, n - 1);
		return res;
	}

};

struct edge {
	int u, v, cost, dp;
};

const int mx = 1e5 + 228;
int n, m;
st t[mx];
vector<edge> e;
vector<int> g[mx], g1[mx];

bool cost_cmp(int a, int b) {
	return e[a].cost < e[b].cost;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v, cost;
		cin >> u >> v >> cost;
		u--;
		v--;
		e.push_back({u, v, cost, 0});
		g[u].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		int deg = g[i].size();
		g1[i].resize(deg);
		t[i].init(deg);
		sort(g[i].begin(), g[i].end(), cost_cmp);
	}
	for (int i = m - 1; i >= 0; --i) {
		int u = e[i].u;
		int v = e[i].v;
		int deg_v = g[v].size();
		int pos = upper_bound(g[v].begin(), g[v].end(), i, cost_cmp) - g[v].begin();
		int pos_u = lower_bound(g[u].begin(), g[u].end(), i, cost_cmp) - g[u].begin();
		if (pos < deg_v) {
			e[i].dp = t[v].get(pos, deg_v - 1) + 1;
		}
		else {
			e[i].dp = 1;
		}
		t[u].update(pos_u, e[i].dp);
	}
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		ans = max(ans, e[i].dp);
	}
	cout << ans << endl;
}
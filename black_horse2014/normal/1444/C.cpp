//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug-template.hpp"
#endif

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int MX = 550000;

struct DSU {
	int rnk[MX], par[MX], odd[MX], spoint, stk[2 * MX];
	void init(int n) {
		for (int i = 1; i <= n; i++) par[i] = i, rnk[i] = 0, odd[i] = 0;
		spoint = 0;
	}
	int get(int x) {
		while (x != par[x]) x = par[x];
		return x;
	}
	int dis(int x) {
		int res = 0;
		while (x != par[x]) res = res ^ odd[x], x = par[x];
		return res;
	}
	bool merge(int x, int y) {
		int px = get(x), py = get(y);
		int dx = dis(x), dy = dis(y);
		if (px == py) {
			if (dx == dy) {
				return false;
			}
		}
		if (rnk[px] > rnk[py]) swap(px, py);
		if (rnk[px] == rnk[py]) {
			rnk[py]++;
			par[px] = py;
			odd[px] = dx ^ dy ^ 1;
			stk[spoint++] = px;
			stk[spoint++] = -py;
		} else {
			par[px] = py;
			odd[px] = dx ^ dy ^ 1;
			stk[spoint++] = px;
		}
		return true;
	}
	void restore(int last) {
		while (spoint > last) {
			int x = stk[--spoint];
			if (x > 0) {
				par[x] = x;
			} else {
				rnk[-x]--;
			}
		}
	}
} dsu;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	vector<int> c(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	dsu.init(n);
	vector<pair<int, int>> e;
	vector<bool> okay(k + 1, true);
	okay[0] = false;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		if (c[u] == c[v]) {
			if (!dsu.merge(u, v)) {
				okay[c[u]] = false;
			}
		} else {
			if (c[u] > c[v]) {
				swap(u, v);
			}
			e.emplace_back(u, v);
		}
	}
	sort(e.begin(), e.end(), [&](pair<int, int> x, pair<int, int> y) {
		return c[x.first] < c[y.first] || c[x.first] == c[y.first] && c[x.second] < c[y.second];
	});
	int sum = accumulate(okay.begin(), okay.end(), 0);
	long long ans = sum * 1LL * (sum - 1) / 2;
	for (int i = 0, j = 0; i < e.size(); i = j) {
		int x = c[e[i].first], y = c[e[i].second];
		int cur = (okay[x] && okay[y]);
		int last = dsu.spoint;
		for (; j < e.size() && c[e[i].first] == c[e[j].first] && c[e[i].second] == c[e[j].second]; j++) {
			if (okay[x] && okay[y]) {
				if (!dsu.merge(e[j].first, e[j].second)) {
					cur = 0;
				}
			}
		}
		dsu.restore(last);
		if (okay[x] && okay[y] && !cur) {
			ans--;
		}
	}
	cout << ans << endl;
	return 0;
}
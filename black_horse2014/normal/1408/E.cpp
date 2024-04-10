#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int u, v, w;
	Edge(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {
	}
	bool operator<(const Edge &rhs) const {
		return w > rhs.w;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int m, n; cin >> m >> n;
	vector<int> a(m + 1), b(n + 1);
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	vector<Edge> E;
	for (int i = 1; i <= m; i++) {
		int s; cin >> s;
		while (s--) {
			int x; cin >> x;
			E.emplace_back(n + i, x, a[i] + b[x]);
		}
	}
	sort(E.begin(), E.end());
	vector<int> f(n + m + 1);
	for (int i = 1; i <= n + m; i++) {
		f[i] = i;
	}
	function<int(int)> find_set = [&](int u) {
		return f[u] == u ? u : f[u] = find_set(f[u]);
	};
	long long ans = 0;
	for (auto e : E) {
		int u = find_set(e.u), v = find_set(e.v), w = e.w;
		if (u == v) {
			ans += w;
		} else {
			f[u] = v;
		}
	}
	cout << ans << endl;
	return 0;
}
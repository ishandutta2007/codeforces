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

struct Data {
	int K, L, u, c, k;
	Data(int K = 0, int L = 0, int u = 0, int c = 0, int k = 0) : K(K), L(L), u(u), c(c), k(k) {};
	bool operator<(const Data &rhs) const {
		return L > rhs.L;
	}
};

struct Data1 {
	int K, L, u, c;
	Data1(int K = 0, int L = 0, int u = 0, int c = 0) : K(K), L(L), u(u), c(c) {};
	bool operator<(const Data1 &rhs) const {
		return K > rhs.K || K == rhs.K && L > rhs.L;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	const int inf = 1e9 + 7;
	vector<vector<pair<int, int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; --u, --v;
		adj[u].emplace_back(v, 1);
		adj[v].emplace_back(u, 0);
	}
	int ret = inf;
	const int P = 998244353;
	auto modExp = [&](int a, int n, int p) {
		int ret = 1;
		for (; n; n >>= 1, a = 1LL * a * a % p) {
			if (n & 1) {
				ret = ret * 1LL * a % p;
			}
		}
		return ret;
	};
	{
		vector<vector<vector<pair<int, int>>>> dis(n, vector<vector<pair<int, int>>>(2, vector<pair<int, int>>(21, {inf, inf})));
		dis[0][1][0] = {0, 0};
		priority_queue<Data> Q;
		Q.emplace(0, 0, 0, 1, 0);
		vector<vector<vector<int>>> used(n, vector<vector<int>>(2, vector<int>(21)));
		while (!Q.empty()) {
			auto t = Q.top(); Q.pop();
			int u = t.u, c = t.c, k = t.k;
			if (used[u][c][k]) {
				continue;
			}
			used[u][c][k] = 1;
			for (auto e : adj[u]) {
				int v = e.first, w = e.second;
				if (c == w) {
					pair<int, int> temp = {dis[u][c][k].first, dis[u][c][k].second + 1};
					if (temp < dis[v][c][k]) {
						dis[v][c][k] = temp;
						Q.emplace(dis[v][c][k].first, dis[v][c][k].second, v, c, k);
					}
				} else {
					pair<int, int> temp = {dis[u][c][k].first + 1, dis[u][c][k].second + 1};
					if (k + 1 > 20) {
						continue;
					}
					if (temp < dis[v][w][min(k + 1, 20)]) {
						dis[v][w][min(k + 1, 20)] = temp;
						Q.emplace(temp.first, temp.second, v, w, min(k + 1, 20));
					}
				}
			}
		}
		for (int i = 0; i < 20; i++) {
			if (dis[n - 1][0][i] > dis[n - 1][1][i]) {
				swap(dis[n - 1][0][i], dis[n - 1][1][i]);
			}
			if (dis[n - 1][0][i].first == inf || dis[n - 1][0][i].second == inf) {
				continue;
			}
	//		debug(dis[n - 1][0][i]);
			if (i < 20) {
				ret = min(ret, (1 << i) - 1 + dis[n - 1][0][i].second);
			} else if (ret == inf) {
				ret = (modExp(2, dis[n - 1][0][i].first, P) + P - 1 + dis[n - 1][0][i].second) % P;
			}
		}
	}
	if (ret != inf) {
		cout << ret << '\n';
		return 0;
	}
	{
		vector<vector<pair<int, int>>> dis(n, vector<pair<int, int>>(2, {inf, inf}));
		dis[0][1] = {0, 0};
		priority_queue<Data1> Q;
		Q.emplace(0, 0, 0, 1);
		vector<vector<int>> used(n, vector<int>(2));
		while (!Q.empty()) {
			auto t = Q.top(); Q.pop();
			int u = t.u, c = t.c;
			if (used[u][c]) {
				continue;
			}
			used[u][c] = 1;
			for (auto e : adj[u]) {
				int v = e.first, w = e.second;
				if (c == w) {
					pair<int, int> temp = {dis[u][c].first, dis[u][c].second + 1};
					if (temp < dis[v][c]) {
						dis[v][c] = temp;
						Q.emplace(dis[v][c].first, dis[v][c].second, v, c);
					}
				} else {
					pair<int, int> temp = {dis[u][c].first + 1, dis[u][c].second + 1};
					if (temp < dis[v][w]) {
						dis[v][w] = temp;
						Q.emplace(temp.first, temp.second, v, w);
					}
				}
			}
		}
		if (dis[n - 1][0] > dis[n - 1][1]) {
			swap(dis[n - 1][0], dis[n - 1][1]);
		}
		ret = ((modExp(2, dis[n - 1][0].first, P) + P - 1) % P + dis[n - 1][0].second) % P;
	}
	cout << ret << endl;
	return 0;
}
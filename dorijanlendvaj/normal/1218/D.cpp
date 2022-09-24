#include <bits/stdc++.h>
using namespace std;

long long modpow(long long n, long long k, long long MOD) {
	long long ans = 1; n %= MOD;
	while (k > 0) {
		if (k & 1) ans = (ans*n) % MOD;
		k >>= 1; n = (n*n) % MOD;
	}
	return ans;
}

long long M = 1e9+7;

void fwht(vector<int> &data, int dim, int inverse = 0) {
	for (int len = 1; 2 * len <= dim; len <<= 1) {
		for (int i = 0; i < dim; i += 2 * len) {
			for (int j = 0; j < len; j++) {
				int a = data[i + j];
				int b = data[i + j + len];
				
				data[i + j] = a + b;
				if (data[i + j] > M) data[i + j] -= M;
				data[i + j + len] = a - b;
				if (data[i + j + len] < 0) data[i + j + len] += M;
			}
		}
	}
	
	if (inverse) {
		long long xk = modpow(dim, M-2, M);
		for (int i = 0; i < dim; i++) {
			data[i] = (data[i] * xk) % M;
		}
	}
}

void conv(vector<int> &p1, vector<int> &p2) {
	fwht(p1, 1 << 17);
	fwht(p2, 1 << 17);
	for (int i = 0; i < (1 << 17); i++) p1[i] = (1LL * p1[i] * p2[i]) % M;
	fwht(p1, 1 << 17, 1);
}

const int dim_mx = 17;
int n, m, t = 1, xr;
vector<pair<int, int>> adj[100001];
vector<int> num(100001), low(200001);
vector<vector<int>> sets(100001);

void dfs(int now, int prev) {
	low[now] = num[now] = t++;
	for (auto [u, w]: adj[now]) {
		if (u != prev) {
			if (num[u]) {
				low[now] = min(low[now], num[u]);
				if (u < now) sets[low[now]].push_back(w);
			} else {
				dfs(u, now);
				low[now] = min(low[now], low[u]);

				if (low[u] >= num[u]) {
					xr ^= w;
				} else {
					sets[low[now]].push_back(w);
				}
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	dfs(1, 1);

	vector<int> pol(1 << 17);
	vector<int> pol2(1 << 17);
	pol[xr] = 1;
	for (auto x: sets) {
		if (x.empty()) continue;
		for (int i = 0; i < (1 << 17); i++) {
			pol2[i] = 0;
		}
		int xs = 0;
		for (int xk: x) {
			xs ^= xk;
		}
		for (int xk: x) {
			pol2[xk ^ xs]++;
		}

		conv(pol, pol2);
	}

	M = 998244353;
	vector<int> polx(1 << 17);
	polx[xr] = 1;
	for (auto x: sets) {
		if (x.empty()) continue;
		for (int i = 0; i < (1 << 17); i++) {
			pol2[i] = 0;
		}
		int xs = 0;
		for (int xk: x) {
			xs ^= xk;
		}
		for (int xk: x) {
			pol2[xk ^ xs]++;
		}

		conv(polx, pol2);
	}

	int min_xr = (1 << 17) - 1;
	for (int i = 0; i < (1 << 17); i++) {
		if (pol[i] > 0 || polx[i] > 0) min_xr = min(min_xr, i);
	}
	cout << min_xr << ' ' << pol[min_xr] << '\n';

	return 0;
}
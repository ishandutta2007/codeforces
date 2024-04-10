#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

int n, a[N], is_prime[N], phi[N];
vector<int> adj[N], factor[N], ffac[N];
int tot;
int svp[N], sv[N], ans[N], inv[N], g[N], size[N], dep[N];
int pos_l[N], pos_r[N], rpos[N];

int power(int a, int n) {
	int ret = 1;
	while (n) {
		if (n & 1) ret = 1LL * ret * a % MOD;
		n >>= 1;
		a = 1LL * a * a % MOD;
	}
	return ret;
}

void add(int &a, int b) {
	if ((a += b) >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

vector<int> record;

void clean() {
	for (auto w : record) {
		sv[w] = svp[w] = 0;
	}
	record.clear();
}

void dfs(int u, int from) {
	int who = -1;
	for (auto v : adj[u]) if (v != from) {
		if (who == -1 || size[v] > size[who]) {
			who = v;
		}
	}
	for (auto v : adj[u]) if (v != from && v != who) {
		dfs(v, u);
		clean();
	}
	if (who != -1) dfs(who, u);
	for (auto v : adj[u]) if (v != from && v != who) {
		for (int p = pos_l[v]; p <= pos_r[v]; p++) {
			int w = rpos[p];
			for (auto d : ffac[a[w]]) {
				add(ans[d], 1LL * phi[a[w]] * svp[d] % MOD);
				add(ans[d], 1LL * (dep[w] - 2 * dep[u]) % MOD * phi[a[w]] % MOD * sv[d] % MOD);
			}
		}
		for (int p = pos_l[v]; p <= pos_r[v]; p++) {
			int w = rpos[p];
			for (auto d : ffac[a[w]]) {
				record.push_back(d);
				add(sv[d], phi[a[w]]);
				add(svp[d], 1LL * phi[a[w]] * dep[w] % MOD);
			}
		}
	}
	for (auto d : ffac[a[u]]) {
		add(ans[d], 1LL * phi[a[u]] * svp[d] % MOD);
		add(ans[d], 1LL * (-dep[u]) % MOD * phi[a[u]] % MOD * sv[d] % MOD);
		add(sv[d], phi[a[u]]);
		add(svp[d], 1LL * phi[a[u]] * dep[u] % MOD);
		record.push_back(d);
	}
}

int tag;

void dfs_size(int u, int from) {
	pos_l[u] = ++tag;
	rpos[tag] = u;
	size[u] = ffac[a[u]].size();
	for (auto v : adj[u]) {
		if (v == from) continue;
		dep[v] = dep[u] + 1;
		dfs_size(v, u);
		size[u] += size[v];
	}
	pos_r[u] = tag;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fill(is_prime, is_prime + n + 1, true);
	is_prime[1] = false;
	for (int i = 1; i <= n; i++) {
		if (is_prime[i]) {
			factor[i].push_back(i);
			for (int j = i + i; j <= n; j += i) {
				is_prime[j] = false;
				factor[j].push_back(i);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		inv[i] = power(i, MOD - 2);
	}
	for (int i = 1; i <= n; i++) {
		phi[i] = i, g[i] = 1;
		int all = 1;
		for (auto d : factor[i]) {
			phi[i] = phi[i] / d * (d - 1);
			g[i] = 1LL * g[i] * d % MOD * inv[d - 1] % MOD;
			all *= d;
		}
		if (all == i) {
			for (int j = i; j <= n; j += i) {
				ffac[j].push_back(i);
			}
		}
		// cout << g[i] << endl;
	}
	dfs_size(1, 0);
	dfs(1, 0);
	// for (int i = 1; i <= n; i++) {
	// 	cout << "ans[" << i << "] = " << ans[i] << endl;
	// }
	for (int i = n; i >= 1; i--) {
		for (int j = i + i; j <= n; j += i) {
			add(ans[i], -ans[j]);
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		add(res, 1LL * ans[i] * g[i] % MOD);
	}
	res = 1LL * res * inv[n] % MOD;
	res = 1LL * res * inv[n - 1] % MOD;
	add(res, res);
	cout << res << endl;
	return 0;
}
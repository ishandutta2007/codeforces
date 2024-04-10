#include <bits/stdc++.h>
using namespace std;

int n;

const int MOD = 1e9 + 7;
const int N = 110;

int a[N], f[N][N], g[N][N], sz[N], c[N][N], dp[N][N][N];

int modExp(int a, int n, int p) {
	int ret = 1;
	for (; n; n >>= 1, a = 1LL * a * a % p) if (n & 1) ret = 1LL * ret * a % p;
	return ret;
}

int s[N];
vector<int> adj[N];

void add(int &x, long long y) {
	x += y % MOD;
	if (x >= MOD) x -= MOD;
}

void dfs(int u, int p) {
	sz[u] = 1;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
	int tot = 0;
	memset(f, 0, sizeof f);
	f[0][1] = 1;
	for (int v : adj[u]) {
		if (v == p) continue;
		for (int j = 0; j <= tot; j++) for (int k = 0; k <= tot+1; k++) g[j][k] = f[j][k];
		for (int j = 0; j <= tot+sz[v]; j++) for (int k = 0; k <= tot+sz[v]+1; k++) f[j][k] = 0;
		for (int j = 0; j <= sz[v]-1; j++) {
			s[j] = 0;
			for (int k = 1; k <= sz[v]; k++) s[j] = (s[j] + 1LL * k * dp[v][j][k]) % MOD;
			s[j] = 1LL * n * s[j] % MOD;
		}
		for (int j = 0; j <= tot; j++) {
			for (int k = 1; k <= tot+1; k++) if (g[j][k]) {
				for (int jj = 0; jj <= sz[v]-1; jj++) {
					add(f[j+jj][k], 1LL * g[j][k] * s[jj]);
					for (int kk = 1; kk <= sz[v]; kk++) if (dp[v][jj][kk]) {
						add(f[j+jj+1][k+kk], 1LL * g[j][k] * dp[v][jj][kk]);
					}
				}
			}
		}
		tot += sz[v];
	}
	for (int j = 0; j <= tot; j++) for (int k = 1; k <= tot+1; k++) dp[u][j][k] = f[j][k];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d", &n);
//	n = 100;
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
//		v = i + 1, u = rand() % i + 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	int rn = modExp(n, MOD - 2, MOD);
	for (int j = 0; j < n; j++) {
		int &ans = a[j];
		for (int k = 1; k <= n; k++) ans = (ans + 1LL * k * dp[1][j][k]) % MOD;
		ans = 1LL * ans * rn % MOD;
	}
	for (int j = 0; j < n; j++) {
		c[j][0] = c[j][j] = 1;
		for (int k = 1; k < j; k++) {
			c[j][k] = (c[j-1][k-1] + c[j-1][k]) % MOD;
		}
	}
	for (int j = n-1; j >= 0; j--) {
		for (int k = j+1; k < n; k++) a[j] = (a[j] + 1LL * (MOD - c[k][j]) * a[k]) % MOD;
	}
	for (int j = 0; j < n; j++) cout << a[j] << ' ';
	cout << endl;
	return 0;
}
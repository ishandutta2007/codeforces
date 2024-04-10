#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N, K;
int sz[5050];
ll D[5050][5050];
ll tmp[5050];

vector<int> adj[5050];

void dfs(int v, int p) {
	sz[v] = 1;
	D[v][0] = 1;
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
		for(int j = 0; j <= sz[v] + sz[i]; j++) tmp[j] = 0;
		ll tot = 0;
		for(int j = 0; j <= sz[i]; j++) tot = (tot + D[i][j]) % MOD;

		for(int j = 0; j <= sz[v]; j++) tmp[j] = (D[v][j] * tot) % MOD;
		for(int j = 0; j <= sz[v]; j++) {
			for(int k = 0; k <= sz[i]; k++) {
				if(j + k + 1 > K) continue;
				int m = max(j, k + 1);
				tmp[m] = (tmp[m] + D[v][j] * D[i][k]) % MOD;
			}
		}
		for(int j = 0; j <= sz[v] + sz[i]; j++) D[v][j] = tmp[j];
		sz[v] += sz[i];
	}
	// printf("%d\n", v);
	// for(int i = 0; i <= sz[v]; i++) printf("%lld ", D[v][i]); puts("");
}

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);
	ll ans = 0;
	for(int i = 0; i <= N; i++) ans = (ans + D[1][i]) % MOD;
	printf("%lld\n", ans);

	return 0;
}
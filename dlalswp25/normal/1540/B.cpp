#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const ll I2 = (MOD + 1) / 2;

int N;
vector<int> adj[202];
ll D[202][202];
int dep[202];
ll t;

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

ll inv(ll x) { return pw(x, MOD - 2); }

vector<int> dfs(int v, int p) {
	vector<int> ret;

	dep[v] = dep[p] + 1;
	for(int i : adj[v]) {
		if(i == p) continue;
		auto tv = dfs(i, v);
		for(int j : tv) {
			for(int k : ret) {
				int a = dep[j] - dep[v];
				int b = dep[k] - dep[v];
				ll prob = D[a][b];
				if(j > k) t = (t + prob) % MOD;
				else t = (t + 1 + MOD - prob) % MOD;
			}
		}
		for(int j : tv) ret.push_back(j);
	}

	for(int i : ret) if(i < v) t = (t + 1) % MOD;

	ret.push_back(v);
	return ret;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 1; i <= N; i++) {
		D[0][i] = 1;
		D[i][0] = 0;
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			D[i][j] = (D[i - 1][j] + D[i][j - 1]) * I2 % MOD;
		}
	}

	ll ans = 0;
	ll IN = inv(N);

	for(int i = 1; i <= N; i++) {
		t = 0;
		dfs(i, 0);
		// printf("%d %lld\n", i, t);
		ans = (ans + t * IN) % MOD;
		// printf("%d %lld\n", i, ans);
	}
	printf("%lld\n", ans);

	return 0;
}
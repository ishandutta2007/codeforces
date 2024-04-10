#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 998244353;

ll D[202020];
ll E[202020];
ll F[202020];
int N;
int P[202020];

vector<pii> adj[202020];

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

void init(int v, int p) {
	for(pii i : adj[v]) {
		if(i.second == p) continue;
		P[i.second] = i.first;
		init(i.second, v);
	}
}

void dfs(int v, int p) {
	ll mul = 1;
	ll e = 1;

	for(pii i : adj[v]) {
		if(i.second == p) continue;
		dfs(i.second, v);
		mul = mul * D[i.second] % MOD;
	}

	ll d = mul, e2 = 1;

	bool ok = false;

	for(pii i : adj[v]) {
		if(i.second == p) continue;
		mul = mul * inv(D[i.second]) % MOD;
		ll t = e * F[i.second] % MOD * mul % MOD;
		if(i.first < P[v]) E[v] = (E[v] + t) % MOD;
		else F[v] = (F[v] + t) % MOD;
		D[v] = (D[v] + t) % MOD;
		e = e * E[i.second] % MOD;

		if(i.first < P[v]) {
			d = d * inv(D[i.second]) % MOD;
			e2 = e2 * E[i.second] % MOD;
		}
	}

	D[v] = (D[v] + e) % MOD;
	E[v] = (E[v] + d * e2) % MOD;
	F[v] = (F[v] + e) % MOD;
}

int main() {
	scanf("%d", &N);

	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[b].push_back({i, a});
		adj[a].push_back({i, b});
	}

	for(int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end());

	init(1, 0);
	dfs(1, 0);

	// for(int i = 1; i <= N; i++) printf("%d ", P[i]); puts("");
	// for(int i = 1; i <= N; i++) printf("%lld ", D[i]); puts("");
	// for(int i = 1; i <= N; i++) printf("%lld ", E[i]); puts("");
	// for(int i = 1; i <= N; i++) printf("%lld ", F[i]); puts("");

	printf("%lld\n", D[1]);

	return 0;
}
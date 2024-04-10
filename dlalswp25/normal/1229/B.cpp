#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll gcd(ll a, ll b) { while(b) { a %= b; swap(a, b); } return a; }

int N;
ll st[20][101010];
ll g[20][101010];
ll w[101010];
int dep[101010];
vector<int> adj[101010];
int up[101010];
int cnt[101010];

ll ans = 0;

void dfs(int now, int par, int u) {
	st[0][now] = par;
	dep[now] = dep[par] + 1;
	up[now] = u;

	if(g[0][now] != 0) u = now;
	for(int i : adj[now]) {
		if(i == par) continue;
		dfs(i, now, u);
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", &g[0][i]);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0, 0);
	for(int i = 1; i < 19; i++) {
		for(int j = 1; j <= N; j++) {
			st[i][j] = st[i - 1][st[i - 1][j]];
		}
	}
	for(int i = 1; i < 19; i++) {
		for(int j = 1; j <= N; j++) {
			g[i][j] = gcd(g[i - 1][j], g[i - 1][st[i - 1][j]]);
		}
	}

	// for(int i = 0; i < 19; i++) {
	// 	for(int j = 1; j <= N; j++) {
	// 		printf("%lld ", g[i][j]);
	// 	}
	// 	puts("");
	// }

	for(int i = 1; i <= N; i++) if(!g[0][i]) cnt[up[i]]++;
	//for(int i = 1; i <= N; i++) printf("%d ", cnt[i]);

	for(int i = 1; i <= N; i++) {
		ll now = g[0][i];
		int v = i;
		if(!g[0][i]) continue;
		while(v) {
			for(int j = 18; j >= 0; j--) {
				if(!v) break;
				//printf("%d %lld %lld\n", j, g[j][v], now);
				if(gcd(g[j][v], now) < now) continue;
				ans += now * min((1 << j), dep[v]) % MOD * (1 + cnt[i]);
				ans %= MOD;
				v = st[j][v];
			}
			now = gcd(now, g[0][v]);
			//printf("%d %lld\n", v, ans);
		}
		//printf("%lld\n", ans);
	}	
	printf("%lld\n", ans);

	return 0;
}
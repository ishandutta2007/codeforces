#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll F[202020];
ll D[202020];
int N;
vector<int> adj[202020];
ll ans;

void dfs(int now, int par) {
	if(adj[now].size() == 1 && now != 1) {
		D[now] = 1; return;
	}

	for(int i : adj[now]) {
		if(i == par) continue;
		dfs(i, now);
	}

	if(now == 1) {
		ans = F[(int)adj[now].size()] * N % MOD;
		for(int i : adj[now]) ans = ans * D[i] % MOD;
	}
	else {
		D[now] = 1;
		D[now] = D[now] * F[(int)adj[now].size() - 1] % MOD;
		D[now] = D[now] * (int)adj[now].size() % MOD;
		for(int i : adj[now]) if(i != par) D[now] = D[now] * D[i] % MOD;
	}
}

int main() {
	F[0] = 1; for(int i = 1; i <= 200000; i++) F[i] = F[i - 1] * i % MOD;
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);
	printf("%lld\n", ans);

	return 0;
}
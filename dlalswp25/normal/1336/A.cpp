#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int sz[202020];
int dep[202020];
int D[202020];

vector<int> adj[202020];

void dfs(int v, int p) {
	dep[v] = dep[p] + 1;
	sz[v] = 1;
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
		sz[v] += sz[i];
	}
}

int main() {
	int N, K; scanf("%d%d", &N, &K);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);

	ll ans = 0;
	for(int i = 1; i <= N; i++) D[i] = dep[i] - sz[i];
	// for(int i = 1; i <= N; i++) printf("%d ", D[i]); puts("");

	sort(D + 1, D + N + 1);
	reverse(D + 1, D + N + 1);

	for(int i = 1; i <= K; i++) ans += D[i];
	printf("%lld\n", ans);

	return 0;
}
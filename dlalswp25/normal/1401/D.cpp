#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N, M;
vector<int> adj[101010];
int sz[101010];

ll P[606060];
ll A[101010];

void dfs(int v, int p) {
	sz[v] = 1;
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
		sz[v] += sz[i];
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		for(int i = 1; i <= N; i++) adj[i].clear();

		scanf("%d", &N);
		for(int i = 1; i < N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs(1, 0);

		scanf("%d", &M);
		for(int i = 1; i <= M; i++) scanf("%lld", &P[i]);
		sort(P + 1, P + M + 1);
		while(M > N - 1) {
			P[M - 1] = P[M - 1] * P[M] % MOD;
			M--;
		}
		for(int i = N; i >= 1; i--) {
			if(i <= (N - M)) P[i] = 1;
			else P[i] = P[i - (N - M)];
		}

		for(int i = 2; i <= N; i++) A[i] = (ll)sz[i] * (N - sz[i]);
		sort(A + 2, A + N + 1);

		// for(int i = 1; i <= N; i++) printf("%lld %lld\n", A[i], P[i]);

		ll ans = 0;
		for(int i = N; i >= 2; i--) ans = (ans + A[i] * P[i]) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> adj[202020];
int N, M;
int a, b, c;

int A[202020];
int B[202020];
int C[202020];
int D[202020];
int P[202020];
ll S[202020];

queue<int> q;

void bfs(int s) {
	for(int i = 1; i <= N; i++) D[i] = 0;
	D[s] = 1; q.push(s);

	while(q.size()) {
		int v = q.front(); q.pop();
		for(int i : adj[v]) {
			if(!D[i]) {
				D[i] = D[v] + 1;
				q.push(i);
			}
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d%d%d", &N, &M, &a, &b, &c);
		for(int i = 1; i <= M; i++) scanf("%d", &P[i]);
		for(int i = 1; i <= M; i++) {
			int u, v; scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		sort(P + 1, P + M + 1);

		for(int i = 1; i <= M; i++) S[i] = S[i - 1] + P[i];

		bfs(a); for(int i = 1; i <= N; i++) A[i] = D[i] - 1;
		bfs(b); for(int i = 1; i <= N; i++) B[i] = D[i] - 1;
		bfs(c); for(int i = 1; i <= N; i++) C[i] = D[i] - 1;

		// for(int i = 1; i <= M; i++) printf("%lld ", S[i]); puts("");

		ll ans = 1LL << 62;
		for(int i = 1; i <= N; i++) {
			int x = B[i], y = A[i] + C[i];
			ll sxy = (x + y > M ? (1LL << 60) : S[x + y]);
			ans = min(ans, S[x] * 2 + (sxy - S[x]));
			// printf("%lld\n", ans);
		}
		printf("%lld\n", ans);

		for(int i = 1; i <= N; i++) adj[i].clear();
	}

	return 0;
}
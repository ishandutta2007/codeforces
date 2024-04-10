#include <bits/stdc++.h>

using namespace std;

vector<int> adj[202020];
int indeg[202020];
int path[202020];
int D[202020];

int P[202020];
int N, M, K;

int a, b;

queue<int> q;

void bfs(int t) {
	for(int i = 1; i <= N; i++) D[i] = 10101010;

	q.push(t);
	D[t] = 0;

	while(q.size()) {
		int v = q.front(); q.pop();
		for(int i : adj[v]) {
			if(D[v] + 1 < D[i]) {
				D[i] = D[v] + 1;
				path[i] = v;
				indeg[i] = 1;
				q.push(i);
			}
			else if(D[v] + 1 == D[i]) {
				indeg[i]++;
			}
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[v].push_back(u);
	}

	scanf("%d", &K);
	for(int i = 1; i <= K; i++) scanf("%d", &P[i]);

	bfs(P[K]);
	// for(int i = 1; i <= N; i++) printf("%d ", indeg[i]); puts("");

	for(int i = 1; i < K; i++) {
		if(indeg[P[i]] == 1 && P[i + 1] == path[P[i]]) continue;
		// printf("%d\n", i);
		b++;
		if(D[P[i + 1]] != D[P[i]] - 1) a++;
	}
	printf("%d %d\n", a, b);

	return 0;
}
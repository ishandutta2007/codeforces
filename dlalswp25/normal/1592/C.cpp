#include <bits/stdc++.h>

using namespace std;

int N, K, X;
int A[101010];
vector<int> adj[101010];
int D[101010];
int E[101010];

void dfs(int v, int p) {
	E[v] = A[v];
	int cnt = 0;
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
		E[v] ^= E[i];
		D[v] = max(D[v], D[i]);
		if(D[i] == 1) cnt++;
	}
	if(cnt >= 2) D[v] = 2;
	if(E[v] == X) D[v] = max(D[v], 1);
	else if(!E[v] && D[v]) D[v] = 2;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) adj[i].clear();
		X = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			X ^= A[i];
		}
		for(int i = 1; i < N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		if(!X) { puts("YES"); continue; }
		if(K == 2) { puts("NO"); continue; }

		for(int i = 1; i <= N; i++) D[i] = E[i] = 0;
		dfs(1, 0);
		puts(D[1] == 2 ? "YES" : "NO");
	}
	return 0;
}
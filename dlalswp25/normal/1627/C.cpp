#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
vector<pii> adj[101010];
int A[101010];
int B[101010];
int ans[101010];

void dfs(int v, int p, int t) {
	for(pii i : adj[v]) {
		if(i.first == p) continue;
		ans[i.second] = t;
		dfs(i.first, v, 5 - t);
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i < N; i++) {
			scanf("%d%d", &A[i], &B[i]);
			adj[A[i]].emplace_back(B[i], i);
			adj[B[i]].emplace_back(A[i], i);
		}
		bool ok = true;
		for(int i = 1; i <= N; i++) if(adj[i].size() > 2) ok = false;
		if(!ok) { puts("-1"); continue; }
		int v = 0;
		for(int i = 1; i <= N; i++) if(adj[i].size() == 1) { v = i; break; }
		dfs(v, 0, 2);
		for(int i = 1; i < N; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}
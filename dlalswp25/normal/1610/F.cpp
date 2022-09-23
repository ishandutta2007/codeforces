#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
int A[303030];
int B[303030];
int C[303030];
set<pii> adj[303030][3];
int ans[303030];

int go(int v, int w) {
	assert(adj[v][w].size());
	auto it = adj[v][w].begin();
	int u = it -> first, e = it -> second;
	if(A[e] == v) ans[e] = 1;
	else ans[e] = 2;
	C[v] -= w; C[u] += w;
	adj[v][w].erase(it);
	adj[u][w].erase(pii(v, e));
	return u;
}

void dfs(int v, int w) {
	if(!w) {
		if(adj[v][1].size()) {
			int nxt = go(v, 1);
			dfs(nxt, 1);
		}
		else if(adj[v][2].size()) {
			int nxt = go(v, 2);
			dfs(nxt, 2);
		}
	}
	else if(w == 1) {
		if(!adj[v][1].size() && adj[v][2].size() % 2 == 0) return;
		if(adj[v][1].size()) {
			int nxt = go(v, 1);
			dfs(nxt, 1);
		}
		else if(adj[v][2].size()) {
			int nxt = go(v, 2);
			dfs(nxt, 2);
		}
	}
	else {
		if(adj[v][2].size()) {
			int nxt = go(v, 2);
			dfs(nxt, 2);
		}
		else if(adj[v][1].size()) {
			int nxt = go(v, 1);
			dfs(nxt, 1);
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		int w; scanf("%d%d%d", &A[i], &B[i], &w);
		adj[A[i]][w].insert({B[i], i});
		adj[B[i]][w].insert({A[i], i});
	}

	int p = 1;
	while(p <= N) {
		while((adj[p][1].size() + adj[p][2].size()) % 2 == 0) p++;
		if(p > N) break;
		dfs(p, 0);
	}
	p = 1;
	while(p <= N) {
		while(!adj[p][1].size() && !adj[p][2].size()) p++;
		if(p > N) break;
		dfs(p, 0);
	}

	int cnt = 0;
	for(int i = 1; i <= N; i++) if(C[i] == 1 || C[i] == -1) cnt++;
	printf("%d\n", cnt);
	for(int i = 1; i <= M; i++) printf("%d", ans[i]); puts("");

	return 0;
}
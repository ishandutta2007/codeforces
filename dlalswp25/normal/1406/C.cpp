#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[101010];
int sz[101010];
int par[101010];
int lf;

void dfs(int v, int p) {
	par[v] = p;
	sz[v] = 1;
	for(int i : adj[v]) {
		if(i != p) {
			dfs(i, v);
			sz[v] += sz[i];
		}
	}
}

void dfs2(int v, int p) {
	int c = 0;
	for(int i : adj[v]) {
		if(i != p) {
			c++;
			dfs2(i, v);
		}
	}
	if(!c) lf = v;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i < N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		dfs(1, 0);

		if(N & 1) {
			printf("%d %d\n%d %d\n", 2, par[2], 2, par[2]);
			continue;
		}

		int r = 0;
		for(int i = 1; i <= N; i++) {
			if(sz[i] == N / 2) { r = i; break; }
		}
		if(!r) {
			printf("%d %d\n%d %d\n", 2, par[2], 2, par[2]);
			continue;
		}

		int r2 = par[r];
		dfs2(r, r2);
		printf("%d %d\n%d %d\n", lf, par[lf], lf, r2);
	}
	return 0;
}
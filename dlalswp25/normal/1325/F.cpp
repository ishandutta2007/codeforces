#include <bits/stdc++.h>

using namespace std;

int N, M;
int par[101010];
int dep[101010];
bool vst[101010];
vector<int> adj[101010];

vector<int> col[505];

void dfs(int v, int p) {
	par[v] = p;
	dep[v] = dep[p] + 1;
	vst[v] = true;
	for(int i : adj[v]) {
		if(vst[i]) continue;
		dfs(i, v);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int sq = 1;
	while(sq * sq < N) sq++;

	dfs(1, 0);
	// printf("%d\n", sq);

	for(int i = 1; i <= N; i++) {
		for(int j : adj[i]) {
			int u = i, v = j;
			if(dep[u] > dep[v]) swap(u, v);
			if(dep[v] - dep[u] >= sq - 1) {
				puts("2");
				printf("%d\n", dep[v] - dep[u] + 1);
				while(dep[v] >= dep[u]) {
					printf("%d ", v);
					v = par[v];
				}
				puts("");
				return 0;
			}
		}
	}

	puts("1");
	for(int i = 1; i <= N; i++) {
		int c = dep[i] % (sq - 1) + 1;
		col[c].push_back(i);
	}

	for(int i = 1; i <= sq - 1; i++) {
		if(col[i].size() >= sq) {
			for(int j = 0; j < sq; j++) printf("%d ", col[i][j]); puts("");
			return 0;
		}
	}

	return 0;
}
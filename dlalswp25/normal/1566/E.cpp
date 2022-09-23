#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[202020];
int deg[202020];
int D[202020];
int par[202020];
vector<int> vs[202020];
bool ers[202020];

void dfs(int v, int p) {
	D[v] = D[p] + 1;
	par[v] = p;
	vs[D[v]].push_back(v);
	for(int i : adj[v]) {
		if(i == p) continue;
		deg[v]++;
		dfs(i, v);
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			adj[i].clear();
			vs[i].clear();
			deg[i] = 0;
			ers[i] = false;
		}
		for(int i = 1; i < N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs(1, 0);
		int ans = 0;
		for(int i = 1; i <= N; i++) ans += (!deg[i]);
		for(int i = N; i >= 2; i--) {
			for(int j : vs[i]) {
				if(!deg[j]) continue;
				bool ok = true;
				for(int k : adj[j]) {
					if(D[k] < D[j]) continue;
					if(ers[k]) continue;
					if(deg[k]) ok = false;
				}
				if(ok) {
					ers[j] = true;
					deg[par[j]]--;
					if(deg[par[j]]) ans--;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
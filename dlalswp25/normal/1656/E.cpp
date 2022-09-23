#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[101010];
int ans[101010];

void dfs(int v, int p, int s) {
	ans[v] = adj[v].size() * s;
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v, s * -1);
	}
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
		dfs(1, 0, 1);
		for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}
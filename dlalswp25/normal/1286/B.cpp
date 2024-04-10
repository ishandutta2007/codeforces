#include <bits/stdc++.h>

using namespace std;

vector<int> ans[2020];
int N, R;
int C[2020];
vector<int> adj[2020];
int sz[2020];

int pos[2020];

void dfs(int v, int p) {
	sz[v] = 1;
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
		sz[v] += sz[i];
	}

	if(C[v] > sz[v] - 1) { puts("NO"); exit(0); }

	for(int i : adj[v]) {
		if(i == p) continue;
		for(int j : ans[i]) {
			if(ans[v].size() == C[v]) ans[v].push_back(v);
			ans[v].push_back(j);
		}
	}
	if(ans[v].size() == C[v]) ans[v].push_back(v);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int p; scanf("%d%d", &p, &C[i]);
		if(p) {
			adj[p].push_back(i);
			adj[i].push_back(p);
		}
		else R = i;
	}

	dfs(R, 0);

	// for(int i = 1; i <= N; i++) {
	// 	for(int j : ans[i]) printf("%d ", j); puts("");
	// }

	puts("YES");
	for(int i = 0; i < ans[R].size(); i++) pos[ans[R][i]] = i + 1;
	for(int i = 1; i <= N; i++) printf("%d ", pos[i]); puts("");

	return 0;
}
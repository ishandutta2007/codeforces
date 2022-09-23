#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

pii operator+ (const pii& a, const pii& b) { return {a.first + b.first, a.second + b.second}; }

int N;
vector<int> adj[202020];
pii D[202020];
pii E[202020];
int ans[202020];

void dfs(int v, int p) {
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
		D[v] = D[v] + E[i];
		E[v] = E[v] + max(D[i], E[i]);
	}
	D[v].first += 1;
	D[v].second -= adj[v].size();
}

void dfs2(int v, int p, bool ok) {
	if(ok && D[v] > E[v]) {
		ans[v] = adj[v].size();
		for(int i : adj[v]) {
			if(i == p) continue;
			dfs2(i, v, false);
		}
	}
	else {
		ans[v] = 1;
		for(int i : adj[v]) {
			if(i == p) continue;
			dfs2(i, v, true);
		}
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	if(N == 2) {
		printf("2 2\n1 1\n");
		return 0;
	}

	dfs(1, 0);
	pii t = max(D[1], E[1]);
	printf("%d %d\n", t.first, -t.second + N - t.first);
	dfs2(1, 0, true);
	for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");

	return 0;
}
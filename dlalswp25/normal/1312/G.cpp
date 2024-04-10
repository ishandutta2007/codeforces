#include <bits/stdc++.h>

using namespace std;

int D[1010101];
int N, K;

vector<pair<char, int> > adj[1010101];
int A[1010101];
bool B[1010101];
int dfn[1010101];

int cnt;

void init(int v) {
	dfn[v] = cnt;
	if(B[v]) cnt++;
	for(auto i : adj[v]) {
		init(i.second);
	}
}

void dfs(int v, int p, int mn) {
	D[v] = 1010101010;
	if(B[v]) D[v] = mn + dfn[v] + 1;
	if(v) D[v] = min(D[v], D[p] + 1);
	else D[v] = 0;

	mn = min(mn, D[v] - dfn[v]);

	for(auto i : adj[v]) {
		dfs(i.second, v, mn);
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int p; char c;
		scanf("%d %c", &p, &c);
		adj[p].push_back({c, i});
	}

	for(int i = 0; i < N; i++) sort(adj[i].begin(), adj[i].end());

	scanf("%d", &K);
	for(int i = 1; i <= K; i++) {
		scanf("%d", &A[i]);
		B[A[i]] = true;
	}

	init(0);
	dfs(0, -1, 0);

	for(int i = 1; i <= K; i++) printf("%d ", D[A[i]]); puts("");

	return 0;
}
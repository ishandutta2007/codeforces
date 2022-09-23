#include <bits/stdc++.h>

using namespace std;

int N, A, B, da, db;
vector<int> adj[101010];
int D[101010];

int dep;

void dfs(int v, int p) {
	for(int i : adj[v]) {
		if(i != p) {
			D[i] = D[v] + 1;
			dfs(i, v);
		}
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d%d%d", &N, &A, &B, &da, &db);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i < N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		if(db < 2 * da + 1) { puts("Alice"); continue; }
		D[A] = 0;
		dfs(A, 0);
		if(D[B] <= da) { puts("Alice"); continue; }

		int mx = 0, mxi;
		for(int i = 1; i <= N; i++) {
			if(D[i] > mx) { mx = D[i]; mxi = i; }
		}

		D[mxi] = 0;
		dfs(mxi, 0);

		mx = 0;
		for(int i = 1; i <= N; i++) mx = max(mx, D[i]);
		if(mx <= 2 * da) puts("Alice");
		else puts("Bob");
	}
	return 0;
}
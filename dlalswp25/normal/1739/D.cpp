#include <bits/stdc++.h>

using namespace std;

int N, K, X, cnt;
vector<int> adj[202020];
int D[202020];

void dfs(int v, int p) {
	D[v] = 1;
	for(int i : adj[v]) {
		dfs(i, v);
		D[v] = max(D[v], D[i] + 1);
	}
	if(p > 1 && D[v] + 1 >= X) {
		cnt++; D[v] = 0;
	}
}

bool solve(int x) {
	X = x; cnt = 0;
	dfs(1, 0);
	return cnt <= K;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 2; i <= N; i++) {
			int p; scanf("%d", &p);
			adj[p].push_back(i);
		}
		int l = 2, r = N;
		while(l <= r) {
			int m = l + r >> 1;
			if(solve(m)) r = m - 1;
			else l = m + 1;
		}
		printf("%d\n", l - 1);
	}
	return 0;
}
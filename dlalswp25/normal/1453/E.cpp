#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101010;

int N;
vector<int> adj[202020];
int D[202020];
int dep[202020];
int K;

void dfs(int v, int p) {
	dep[v] = dep[p] + 1;
	if(v != 1 && adj[v].size() == 1) {
		D[v] = dep[v];
		return;
	}

	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
		if(v != 1 && D[i] - dep[v] >= K) { D[v] = INF; return; }
		D[v] = min(D[v], D[i]);
	}
}

bool solve(int x) {
	for(int i = 1; i <= N; i++) D[i] = INF;
	K = x;
	dfs(1, 0);
	int ck = 0;
	for(int i : adj[1]) {
		if(D[i] - 1 > K) return false;
		if(D[i] - 1 == K) {
			if(ck) return false;
			ck++;
		}
	}
	return true;
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

		int l = 1, r = N;
		while(l <= r) {
			int m = l + r >> 1;
			if(solve(m)) r = m - 1;
			else l = m + 1;
		}
		printf("%d\n", l);
	}
	return 0;
}
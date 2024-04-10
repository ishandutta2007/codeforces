#include <bits/stdc++.h>

using namespace std;

int N;
bool vst[202020];
bool fin[202020];
vector<int> adj[202020];
bool cycle;
int D[202020];

void dfs(int v) {
	vst[v] = true;
	for(int i : adj[v]) {
		if(vst[i]) {
			if(!fin[i]) cycle = true;
		}
		else dfs(i);
	}
	fin[v] = true;
}

int f(int v) {
	if(D[v]) return D[v];
	D[v] = 1;
	for(int i : adj[v]) {
		int t = f(i);
		if(i < v) D[v] = max(D[v], t);
		else D[v] = max(D[v], t + 1);
	}
	return D[v];
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			adj[i].clear();
			vst[i] = fin[i] = false;
			D[i] = 0;
		}
		cycle = false;
		for(int i = 1; i <= N; i++) {
			int k; scanf("%d", &k);
			for(int j = 0; j < k; j++) {
				int a; scanf("%d", &a);
				adj[i].push_back(a);
			}
		}

		for(int i = 1; i <= N; i++) {
			if(!vst[i]) dfs(i);
		}
		if(cycle) {
			puts("-1"); continue;
		}

		int ans = 0;
		for(int i = 1; i <= N; i++) ans = max(ans, f(i));
		printf("%d\n", ans);
	}
	return 0;
}
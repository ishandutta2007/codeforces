#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
vector<int> adj[202020];
int L[202020];
int R[202020];
int ans;

void dfs(int v, int p) {
	ll s = 0;
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
		s += R[i];
	}
	if(s < L[v]) ans++; 
	else R[v] = min((ll)R[v], s);
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 2; i <= N; i++) {
			int p; scanf("%d", &p);
			adj[p].push_back(i);
		}
		for(int i = 1; i <= N; i++) scanf("%d%d", &L[i], &R[i]);
		ans = 0;
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}
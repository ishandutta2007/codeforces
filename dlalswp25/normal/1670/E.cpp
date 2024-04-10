#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
vector<pii> adj[131313];
int ansV[131313];
int ansE[131313];
int id;

void dfs(int v, int p, bool x) {
	for(pii& i : adj[v]) {
		if(i.first == p) continue;
		if(x) {
			ansE[i.second] = N + id;
			ansV[i.first] = id;
			id++;
		}
		else {
			ansE[i.second] = id;
			ansV[i.first] = N + id;
			id++;
		}
		dfs(i.first, v, !x);
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int P; scanf("%d", &P);
		N = 1 << P;
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i < N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].emplace_back(b, i);
			adj[b].emplace_back(a, i);
		}
		ansV[1] = N;
		id = 1;
		dfs(1, 0, true);
		puts("1");
		for(int i = 1; i <= N; i++) printf("%d ", ansV[i]); puts("");
		for(int i = 1; i < N; i++) printf("%d ", ansE[i]); puts("");
	}
	return 0;
}
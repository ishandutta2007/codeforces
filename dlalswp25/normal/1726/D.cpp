#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
int A[202020];
int B[202020];
vector<pii> adj[202020];
char ans[202020];
int dfn[202020];
int up[202020];
vector<int> V;
int vid;

void dfs(int v, int p) {
	dfn[v] = ++vid;
	for(pii i : adj[v]) {
		if(i.first == p) continue;
		if(dfn[i.first] && dfn[i.first] < dfn[v]) V.push_back(i.second);
		else if(!dfn[i.first]) {
			up[i.first] = i.second;
			dfs(i.first, v);
		}
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i <= M; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].emplace_back(b, i);
			adj[b].emplace_back(a, i);
			A[i] = a; B[i] = b;
		}
		V.clear();
		for(int i = 1; i <= N; i++) dfn[i] = 0;
		vid = 0;
		dfs(1, 0);
		for(int i = 1; i <= M; i++) ans[i] = '0';
		for(int i : V) ans[i] = '1';
		set<int> S;
		for(int i : V) {
			S.insert(A[i]); S.insert(B[i]);
		}
		if(V.size() == 3 && S.size() == 3) {
			int x = A[V[0]], y = B[V[0]];
			if(dfn[x] > dfn[y]) swap(x, y);
			ans[V[0]] = '0';
			ans[up[y]] = '1';
		}
		for(int i = 1; i <= M; i++) printf("%c", ans[i]); puts("");
	}
	return 0;
}
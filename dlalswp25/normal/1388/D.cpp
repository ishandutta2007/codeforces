#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
vector<int> adj[202020];
bool chk[202020];
bool rt[202020];

ll A[202020];
ll ans;
vector<int> ord;

void dfs(int v, int p) {
	for(int i : adj[v]) {
		dfs(i, v);
	}
	if(A[v] >= 0) {
		ans += A[v];
		ord.push_back(v);
		chk[v] = true;
		A[p] += A[v];
	}
}

void dfs2(int v) {
	if(!chk[v]) {
		ans += A[v];
		ord.push_back(v);
		chk[v] = true;
	}
	for(int i : adj[v]) dfs2(i);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) rt[i] = true;
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for(int i = 1; i <= N; i++) {
		int p; scanf("%d", &p);
		if(p == -1) continue;
		rt[i] = false;
		adj[p].push_back(i);
	}

	for(int i = 1; i <= N; i++) if(rt[i]) dfs(i, 0);
	for(int i = 1; i <= N; i++) if(rt[i]) dfs2(i);
	printf("%lld\n", ans);
	for(int i : ord) printf("%d ", i); puts("");
	return 0;
}
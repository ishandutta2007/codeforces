#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
vector<int> adj[202020];

ll A[202020];
int B[202020];
int C[202020];

int par[202020];
ll ans = 0;

int D[202020];

void dfs(int v, int p) {
	if(v != 1) A[v] = min(A[v], A[p]);
	par[v] = p;
	for(int i : adj[v]) if(i != p) dfs(i, v);
}

void f(int v) {
	if(B[v] == C[v]) D[v] = 0;
	else if(B[v] == 0) D[v] = -1;
	else D[v] = 1;
}

void solve(int v, int p) {
	f(v);
	if(v != 1 && adj[v].size() == 1) return;

	ll d = D[v];
	for(int i : adj[v]) {
		if(i == p) continue;
		solve(i, v);

		if(d * D[i] < 0) {
			ans += A[v] * 2 * min(abs(d), (ll)abs(D[i]));
		}
		d += D[i];
	}

	D[v] = d;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld%d%d", &A[i], &B[i], &C[i]);

	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);
	solve(1, 0);
	if(D[1]) puts("-1");
	else printf("%lld\n", ans);

	return 0;
}
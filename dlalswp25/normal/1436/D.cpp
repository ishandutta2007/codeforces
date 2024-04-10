#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
vector<int> adj[202020];
ll X[202020];
ll A[202020];
ll B[202020];
ll C[202020];

void dfs(int v) {
	if(adj[v].size() == 0) {
		A[v] = X[v];
		B[v] = 0;
		C[v] = 1;
		return;
	}

	ll mx = 0;
	for(int i : adj[v]) {
		dfs(i);
		mx = max(mx, A[i]);
		C[v] += C[i];
	}
	A[v] = mx;

	ll s = 0;
	for(int i : adj[v]) {
		s += B[i] + C[i] * (mx - A[i]);
	}

	if(s > X[v]) B[v] = s - X[v];
	else {
		A[v] += (X[v] - s + C[v] - 1) / C[v];
		B[v] = (C[v] - (X[v] - s) % C[v]) % C[v];
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 2; i <= N; i++) {
		int p; scanf("%d", &p);
		adj[p].push_back(i);
	}

	for(int i = 1; i <= N; i++) scanf("%lld", &X[i]);

	dfs(1);
	printf("%lld\n", A[1]);

	return 0;
}
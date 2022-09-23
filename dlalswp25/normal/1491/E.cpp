#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[202020];
int F[50];
int id = 1;
int C[202020];
int sz[202020];
int up[202020];

void dfs(int v, int p, vector<int>& x) {
	x.push_back(v);
	sz[v] = 1;
	up[v] = p;
	for(int i : adj[v]) {
		if(i == p || C[i] != C[v]) continue;
		dfs(i, v, x);
		sz[v] += sz[i];
	}
}

void dfs2(int v, int p, int c) {
	for(int i : adj[v]) {
		if(i == p || C[i] != C[v]) continue;
		dfs2(i, v, c);
	}
	C[v] = c;
}

bool solve(int v, int k) {
	if(F[k] <= 3) return true;
	vector<int> x;
	dfs(v, 0, x);

	int R = 0;
	for(int i : x) {
		if(sz[i] == F[k - 1] || sz[i] == F[k - 2]) {
			R = i; break;
		}
	}

	if(!R) return false;
	int uR = up[R];
	id++;
	for(int i : x) C[i] = id;
	id++;
	dfs2(R, uR, id);

	if(sz[R] == F[k - 1]) return solve(R, k - 1) && solve(uR, k - 2);
	return solve(R, k - 2) && solve(uR, k - 1);
}

int main() {
	F[0] = F[1] = 1;
	for(int i = 2; i < 30; i++) F[i] = F[i - 1] + F[i - 2];

	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	if(N <= 3) { puts("YES"); return 0; }

	bool ok = false;
	int K;
	for(int i = 0; i < 30; i++) {
		if(N == F[i]) { K = i; ok = true; }
	}
	if(!ok) { puts("NO"); return 0; }

	for(int i = 1; i <= N; i++) C[i] = id;
	if(solve(1, K)) puts("YES");
	else puts("NO");

	return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
vector<int> adj[101010];

int P[101010];
int H[101010];
ll S[101010];

ll X[101010];
ll Y[101010];

bool ok;

void dfs(int v, int p) {
	S[v] = P[v];
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
		S[v] += S[i];
	}

	if(H[v] > S[v] || -H[v] > S[v] || (H[v] + S[v]) % 2) X[v] = Y[v] = -1;
	else {
		X[v] = (S[v] + H[v]) / 2;
		Y[v] = (S[v] - H[v]) / 2;
	}
}

void dfs2(int v, int p) {
	ll sx = 0;

	for(int i : adj[v]) {
		if(i == p) continue;
		sx += X[i];
	}

	if(sx > X[v]) ok = false;

	for(int i : adj[v]) {
		if(i != p) dfs2(i, v);
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i <= N; i++) scanf("%d", &P[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &H[i]);
		for(int i = 1; i < N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		dfs(1, 0);

		ok = true;
		for(int i = 1; i <= N; i++) if(X[i] < 0 || Y[i] < 0) ok = false;
		if(!ok) { puts("NO"); continue; }

		dfs2(1, 0);
		puts(ok ? "YES" : "NO");
	}
	return 0;
}
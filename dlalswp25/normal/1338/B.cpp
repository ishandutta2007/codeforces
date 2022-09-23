#include <bits/stdc++.h>

using namespace std;

vector<int> adj[101010];
int N;

int mn, mx;

bool lf[101010];
int x[101010];

void dfs(int v, int p) {
	for(int i : adj[v]) {
		if(i == p) continue;
		x[i] = x[v] ^ 1;
		dfs(i, v);
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 1; i <= N; i++) if(adj[i].size() == 1) lf[i] = true;

	mx = N - 1;
	for(int i = 1; i <= N; i++) {
		if(lf[i]) continue;
		int c = 0;
		for(int j : adj[i]) {
			c += lf[j];
		}
		if(!c) continue;
		mx -= (c - 1);
	}

	mn = 1;
	for(int i = 1; i <= N; i++) {
		if(!lf[i]) {
			dfs(i, 0);
			break;
		}
	}

	int t = -1;
	for(int i = 1; i <= N; i++) {
		if(lf[i]) {
			if(t == -1) t = x[i];
			else if(t != x[i]) mn = 3;
		}
	}
	printf("%d %d\n", mn, mx);

	return 0;
}
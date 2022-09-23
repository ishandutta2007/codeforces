#include <bits/stdc++.h>

using namespace std;

int N, X;
int G[303030];
int up[303030];
bool chk[303030];
vector<int> adj[303030];

void dfs(int v, int p) {
	up[v] = p;
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
		G[v] ^= (G[i] + 1);
	}
}

void print() {
	if(~X & 1) printf("%d", G[1] ? 1 : 2);
	else printf("%d", G[1] == 1 ? 2 : 1);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);

	print();
	X = 0;
	chk[1] = true;

	for(int i = 2; i <= N; i++) {
		int t = i;
		int bef = t;
		if(chk[t]) { print(); continue; }
		while(1) {
			chk[t] = true; X++;
			for(int i : adj[t]) {
				if(i == bef || i == up[t]) continue;
				G[1] ^= (G[i] + 1);
			}
			bef = t; t = up[t];
			if(chk[t]) break;
		}
		G[1] ^= (G[bef] + 1);
		print();
	}
	puts("");

	return 0;
}
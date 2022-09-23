#include <bits/stdc++.h>

using namespace std;

int sz[505050];
int B[505050];
int deg[505050];
int p[505050];
vector<int> adj[505050];

char S[505050];

void dfs(int now, int par) {
	sz[now] = 1;
	p[now] = par;
	for(int i : adj[now]) {
		if(i == par) continue;
		dfs(i, now);
		sz[now] += sz[i];
	}
}

int T, N;

void fsh() {
	for(int i = 1; i <= N; i++) adj[i].clear();
	for(int i = 1; i <= N; i++) deg[i] = 0;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i < N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
			deg[a]++; deg[b]++;
		}
		scanf("%s", S);
		for(int i = 1; i <= N; i++) B[i] = (S[i - 1] == 'W');

		if(N <= 2) { puts("Draw"); fsh(); continue; }
		if(N == 3) {
			int c = 0;
			for(int i = 1; i <= N; i++) c += B[i];
			if(c >= 2) puts("White");
			else puts("Draw");
			fsh(); continue;
		}

		dfs(1, 0);

		bool win = false;

		for(int i = 1; i <= N; i++) {
			if(deg[i] >= 4) { win = true; break; }
			if(deg[i] == 3) {
				int c = 0, s = 1;
				for(int j : adj[i]) {
					if(j == p[i]) continue;
					if(sz[j] == 1) c++;
					s += sz[j];
				}
				if(s == N - 1) c++;
				if(c < 2) { win = true; break; }
			}
		}

		if(win) { puts("White"); fsh(); continue; }

		for(int i = 1; i <= N; i++) {
			if(!B[i]) continue;
			for(int j : adj[i]) {
				//printf("%d %d\n", deg[i], deg[j]);
				if(deg[i] + deg[j] >= 4) { win = true; break; }
			}
			if(win) break;
		}
		if(win) { puts("White"); fsh(); continue; }

		int th = 0;
		for(int i = 1; i <= N; i++) if(deg[i] == 3) th++;

		if(th == 2) {
			puts((N & 1) ? "White" : "Draw");
			fsh(); continue;
		}

		int c = 0;
		for(int i = 1; i <= N; i++) c += B[i];

		if(th == 1) {
			if(c < 1) { puts("Draw"); fsh(); continue; }
			puts(!(N & 1) ? "White" : "Draw"); fsh(); continue;
		}
		if(c < 2) { puts("Draw"); fsh(); continue; }

		puts((N & 1) ? "White" : "Draw");
		fsh();
	}
	return 0;
}
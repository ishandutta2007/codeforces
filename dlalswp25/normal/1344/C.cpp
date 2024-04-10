#include <bits/stdc++.h>

using namespace std;

int dfn[202020];
int ed[202020];
int ans[202020];

vector<int> adj[202020];
vector<int> rev[202020];

bool chk[202020];
bool chkr[202020];

int N, M;
int id;
bool cyc;

void dfs(int v) {
	dfn[v] = ++id;
	for(int i : adj[v]) {
		if(dfn[i]) {
			if(!ed[i]) cyc = true;
		}
		else dfs(i);
	}
	ed[v] = id;
}

void dfs1(int v) {
	chk[v] = true;
	for(int i : adj[v]) {
		if(chk[i]) continue;
		dfs1(i);
	}
}

void dfs2(int v) {
	chkr[v] = true;
	for(int i : rev[v]) {
		if(chkr[i]) continue;
		dfs2(i);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		rev[b].push_back(a);
	}

	for(int i = 1; i <= N; i++) if(!dfn[i]) dfs(i);
	if(cyc) { puts("-1"); return 0; }

	for(int i = 1; i <= N; i++) {
		if(!chk[i] && !chkr[i]) {
			ans[i] = 1;
			dfs1(i); dfs2(i);
		}
		if(!chk[i]) dfs1(i);
		if(!chkr[i]) dfs2(i);
	}

	int cnt = 0;
	for(int i = 1; i <= N; i++) cnt += ans[i];
	printf("%d\n", cnt);
	for(int i = 1; i <= N; i++) printf(ans[i] ? "A" : "E"); puts("");

	return 0;
}
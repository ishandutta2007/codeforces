#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[202020];
int D[202020];
bool chk[202020];

void dfs(int v, int p) {
	int s = 0, ch = 0, u;
	int cnt = 0;
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
		s += D[i];
		ch++;
		if(chk[i]) cnt++;
		u = i;
	}
	if(!p) D[v] = s + max(ch - cnt <= 1 ? 1 : 0, cnt - 1);
	else D[v] = s + max(0, cnt - 1);
	if(!ch || (ch == 1 && chk[u])) chk[v] = true;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		if(N == 1) { puts("0"); continue; }
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i <= N; i++) chk[i] = false;
		for(int i = 1; i < N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int r = 1;
		for(int i = 1; i <= N; i++) if(adj[i].size() > 2) r = i;
		dfs(r, 0);
		printf("%d\n", D[r]);
	}
	return 0;
}
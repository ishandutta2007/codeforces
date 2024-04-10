#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[101010];
int cnt;
bool vst[101010];

void dfs(int x) {
	vst[x] = true;
	for(int i : adj[x]) {
		if(vst[i]) continue;
		dfs(i);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int t = 0;
	for(int i = 1; i <= N; i++) {
		if(vst[i]) continue;
		cnt++; dfs(i);
	}
	printf("%d\n", M - (N - cnt));
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
vector<int> adj[101010];
int L[101010];
int R[101010];
ll DL[101010];
ll DR[101010];

void dfs(int v, int p) {
	DL[v] = DR[v] = 0;
	for(int i : adj[v]) if(i != p) dfs(i, v);
	for(int i : adj[v]) {
		if(i == p) continue;
		DL[v] += max(DL[i] + abs(L[v] - L[i]), DR[i] + abs(L[v] - R[i]));
	}
	for(int i : adj[v]) {
		if(i == p) continue;
		DR[v] += max(DL[i] + abs(R[v] - L[i]), DR[i] + abs(R[v] - R[i]));
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i <= N; i++) scanf("%d%d", &L[i], &R[i]);
		for(int i = 1; i < N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		dfs(1, 0);
		printf("%lld\n", max(DL[1], DR[1]));
	}
	return 0;
}
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int sz[300005];
vector<int> adj[300005];
int p[300005];

void DFS(int now, int par) {
	sz[now] = 1;
	p[now] = par;
	for(int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i]; if(next == par) continue;
		DFS(next, now); sz[now] += sz[next];
	}
	return;
}

int main() {
	int N; scanf("%d", &N);
	int X, Y; scanf("%d%d", &X, &Y);
	for(int i = 0; i < N - 1; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	

	DFS(X, 0);
	long long ans = (long long)N * (N - 1);
	int now = Y;
	while(1) {
		if(p[now] == X) break;
		now = p[now];
	}
	ans -= (long long)(N - sz[now]) * (sz[Y]);
	printf("%lld", ans);

	return 0;
}
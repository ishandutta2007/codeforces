#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int par[1000005][22];
vector<int> adj[1000005];
bool taken[1000005];

void f(int now, int p) {
	par[now][0] = p;
	for(int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i]; if(next == p) continue;
		f(next, now);
	}
}

int main() {
	int N, K; scanf("%d%d", &N, &K);

	for(int i = 0; i < N - 1; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	f(N, 0);

	for(int i = 1; i <= 20; i++) {
		for(int j = 1; j <= N; j++) {
			par[j][i] = par[par[j][i - 1]][i - 1];
		}
	}

	taken[N] = true;
	taken[0] = true;

	int idx = N - 1, k = 1;

	while(k < N - K && idx) {
		int dist = 0, now = idx;
		for(int i = 20; i >= 0; i--) {
			if(taken[par[now][i]]) continue;
			dist += (1 << i); now = par[now][i];
		}
		//printf("%d %d\n", idx, dist);
		if(k + dist + 1 > N - K) { idx--; continue; }
		now = idx;
		while(!taken[now]) {
			taken[now] = true;
			now = par[now][0]; k++;
		}
		idx--;
	}

	for(int i = 1; i <= N; i++) if(!taken[i]) printf("%d ", i);
	return 0;
}
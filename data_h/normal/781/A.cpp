#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int n;
vector<int> adj[N];
int color[N];

void dfs(int u, int from) {
	int cnt = 1;
	for (auto v : adj[u]) {
		if (v == from) continue;
		while (cnt == color[from] || cnt == color[u]) cnt++;
		color[v] = cnt++;
	}
	for (auto v : adj[u]) {
		if (v == from) continue;
		dfs(v, u);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i + 1 < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (n <= 2) {
		printf("%d\n", 1);
		for (int i = 1; i <= n; i++) {
			printf("%d ", 1);
		}
		puts("");
		return 0;
	}
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		tot = max(tot, (int)adj[i].size() + 1);
	}
	color[0] = 0;
	color[1] = 1;
	dfs(1, 0);
	printf("%d\n", tot);
	for (int i = 1; i <= n; i++) {
		printf("%d ", color[i]);
	}
	puts("");
	return 0;
}
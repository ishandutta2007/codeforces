#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int n, m, k;
vector<int> adj[N], p;
int visit[N];

void dfs(int u) {
	visit[u] = 1;
	p.push_back(u);
	for (auto v : adj[u]) {
		if (visit[v]) continue;
		dfs(v);
		p.push_back(u);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	int ptr = 0;
	for (int i = 1; i <= k; i++) {
		int cnt = 0;
		vector<int> tmp;
		while (ptr < p.size() && cnt < (2 * n + k - 1) / k) {
			tmp.push_back(p[ptr++]);
			++cnt;
		}
		if (tmp.size() == 0) {
			tmp.push_back(1);
		}
		printf("%d", tmp.size());
		for (auto v : tmp) {
			printf(" %d", v);
		}
		puts("");
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 110000;
vector<int> adj[N], vec, v1;
int fa[N], son[N];
void dfs(int u, int p) {
	son[u] = 0;
	fa[u] = p;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u);
		son[u]++;
	}
	if (son[u] == 0) vec.push_back(u);
	if (son[u] > 1) v1.push_back(u);
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int r;
	for (int i = 1; i <= n; i++) if (adj[i].size() == 1) r = i;
	dfs(r, 0);
	if (v1.size() >= 2) return puts("No"), 0;
	if (v1.size() == 0) {
		puts("Yes\n1");
		printf("%d %d\n", r, vec[0]);
		return 0;
	}
	int u = v1[0];
	puts("Yes");
	printf("%d\n", int(vec.size()) + 1);
	printf("%d %d\n", r, u);
	for (int i = 0; i < vec.size(); i++) printf("%d %d\n", vec[i], u);
	return 0;
}
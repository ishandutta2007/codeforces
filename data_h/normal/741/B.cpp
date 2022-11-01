#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1000 + 7;

vector<int> adj[N];

int n, m, w;
int weight[N], beauty[N];
int f[N];
vector<int> s;
int tot_w, tot_b;

int visit[N];

void dfs(int u) {
	s.push_back(u);
	tot_b += beauty[u];
	tot_w += weight[u];
	s.push_back(u);
	visit[u] = 1;
	for (auto v : adj[u]) {
		if (!visit[v]) dfs(v);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &w);
	for (int i = 0; i < n; i++) {
		scanf("%d", &weight[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &beauty[i]);
	}
	for (int i = 0; i <= w; i++) f[i] = 0;
	fill(visit, visit + n, 0);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		if (visit[i]) continue;
		s.clear();
		tot_b = 0, tot_w = 0;
		dfs(i);
		for (int j = w; j >= 0; j--) {
			if (j + tot_w <= w) {
				f[j + tot_w] = max(f[j + tot_w], f[j] + tot_b);
			}
			for (auto v : s) {
				if (j + weight[v] <= w) {
					f[j + weight[v]] = max(f[j + weight[v]], f[j] + beauty[v]);
				}
			}
		}
	}
	printf("%d\n", *max_element(f, f + w + 1));
	return 0;
}
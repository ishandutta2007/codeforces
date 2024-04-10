#include <bits/stdc++.h>

const int maxn = 5e5 + 20;
const int mod = 1e9 + 7;

int n;
int a[maxn];
std::vector<int> adj[maxn];
int fa[maxn], dep[maxn];
std::vector<std::pair<int,int> > edges[maxn];

void dfs(int u,int f) {
	fa[u] = f;
	dep[u] = dep[f] + 1;

	for(auto v : adj[u]) {
		if(v != f) {
			dfs(v, u);
		}
	}
}
void addpath(int u,int v) {
	if(u == v) {
		printf("0");
		exit(0);
	}
	
	std::vector<int> path_u, path_v, path;

	path_u.push_back(n + 1);
	path_v.push_back(n + 2);
	while(dep[u] > dep[v]) {
		path_u.push_back(u);
		u = fa[u];
	}
	while(dep[v] > dep[u]) {
		path_v.push_back(v);
		v = fa[v];
	}
	while(u != v) {
		path_u.push_back(u);
		path_v.push_back(v);
		u = fa[u];
		v = fa[v];
	}
	path_u.push_back(u);
	
	path.insert(path.end(), path_u.begin(), path_u.end());
	path.insert(path.end(), path_v.rbegin(), path_v.rend());

	static int cnt = 0;

	for(int i = 1; i + 1 < path.size(); i++) {
		edges[path[i]].push_back(std::make_pair(path[i - 1], path[i + 1]));
		cnt++;
	}

	if(cnt > 5 * n) {
		printf("0");
		exit(0);
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	if(n == 1) {
		printf("0");
		exit(0);
	}

	dfs(1, 0);

	for(int i = 1; i <= n; i++) {
		if(a[i] != 0) {
			addpath(a[i], i);
		}
	}

	for(int i = 1; i <= n; i++) {
		adj[i].push_back(n + 1);
		adj[i].push_back(n + 2);
	}

	int ans = 1;
	for(int i = 1; i <= n; i++) {
		static int next[maxn] = {0};
		static int prev[maxn] = {0};
		static bool flag[maxn] = {false};

		for(auto edge : edges[i]) {
			int u = edge.first;
			int v = edge.second;

			if(next[u] && next[u] != v) {
				printf("0");
				exit(0);
			}
			if(prev[v] && prev[v] != u) {
				printf("0");
				exit(0);
			}
			next[u] = v;
			prev[v] = u;
		}

		for(auto u : adj[i]) {
			if(!flag[u]) {
				flag[u] = true;
				int cur = next[u];
				while(cur) {
					if(cur == u) {
						printf("0");
						exit(0);
					}
					if(flag[cur]) break;

					flag[cur] = true;
					cur = next[cur];
				}
			}
		}

		if(next[n + 1]) {
			int cur = n + 1, cnt = 1;
			while(cur) {
				if(cur == n + 2) break;
				cur = next[cur], cnt++;
			}
			if(cur == n + 2 && cnt < adj[i].size()) {
				printf("0");
				exit(0);
			}
		}

		int free = 0;
		for(auto u : adj[i]) if(u <= n && !prev[u]) ++free;
		if(prev[n + 2]) --free;
		for(int j = 1; j <= free; j++) ans = 1ll * ans * j % mod;
		for(auto u : adj[i]) next[u] = prev[u] = flag[u] = 0;
	}
	printf("%d\n", ans);
	return 0;
}
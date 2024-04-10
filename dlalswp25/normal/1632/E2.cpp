#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[303030];
vector<int> V[303030];
int dep[303030];
int st[20][303030];
int ans[303030];
bool vst[303030];

void dfs(int v, int p) {
	st[0][v] = p;
	dep[v] = dep[p] + 1;
	for(int i : adj[v]) {
		if(i != p) dfs(i, v);
	}
}

int lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int i = 19; i >= 0; i--) {
		if(dep[st[i][a]] < dep[b]) continue;
		a = st[i][a];
	}
	if(a == b) return a;
	for(int i = 19; i >= 0; i--) {
		if(st[i][a] == st[i][b]) continue;
		a = st[i][a]; b = st[i][b];
	}
	return st[0][a];
}

int dist(int a, int b) {
	int l = lca(a, b);
	return dep[a] + dep[b] - dep[l] * 2;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i <= N; i++) V[i].clear();
		for(int i = 1; i <= N; i++) vst[i] = false;
		for(int i = 1; i < N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dep[0] = -1;
		dfs(1, 0);
		for(int i = 1; i <= 19; i++) for(int j = 1; j <= N; j++) st[i][j] = st[i - 1][st[i - 1][j]];

		int mx = 0;
		for(int i = 1; i <= N; i++) {
			V[dep[i]].push_back(i);
			mx = max(mx, dep[i]);
		}

		for(int i = 0; i <= mx; i++) ans[i] = 0;
		ans[mx] = N;

		int u = V[mx][0], v = V[mx][0], l = u;
		vst[u] = true;
		int d = 0;
		for(int i = mx - 1; i > 0; i--) {
			for(int j : V[i + 1]) {
				if(vst[j]) continue;
				int t = lca(l, j);
				while(l != t) {
					l = st[0][l]; vst[l] = true;
					if(dist(l, u) > d) {
						v = l; d = dist(u, v);
					}
					else if(dist(l, v) > d) {
						u = l; d = dist(u, v);
					}
				}
				vector<int> path;
				t = j;
				while(!vst[j]) {
					path.push_back(j);
					j = st[0][j];
				}
				reverse(path.begin(), path.end());
				for(int k : path) {
					vst[k] = true;
					if(dist(k, u) > d) {
						v = k; d = dist(u, v);
					}
					else if(dist(k, v) > d) {
						u = k; d = dist(u, v);
					}
				}
			}
			int rad = (d + 1) / 2;
			ans[i] = i - rad;
		}

		int t = 0;
		for(int i = 1; i <= mx; i++) {
			while(t < ans[i]) { t++; printf("%d ", i); }
		}
		puts("");
	}
	return 0;
}
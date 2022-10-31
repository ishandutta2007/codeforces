#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int cnt[N], q[N], c[N], ans[N], u[N];
int n, m, h;
int vis[N];
bool chk[N];
vector<int> adj[N], radj[N];
int qn, cn;

void dfs(int u) {
	vis[u]++;
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if(!vis[v]) dfs(v);
	}
 	q[qn++] = u;
}

void rdfs(int u) {
	vis[u] = cn;
	for(int i = 0; i < radj[u].size(); i++) {
		int v = radj[u][i];
		if(!vis[v]) rdfs(v);
	}
}

void SCC() {
	cn = qn = 0;
	memset(vis, 0, sizeof vis);
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) dfs(i);
	}
	memset(vis, 0, sizeof vis);
	for(int i = qn - 1; i >= 0; i--) {
		int u = q[i];
		if(!vis[u]) {
			cn++;
			rdfs(u);
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &h);
	for (int i = 1; i <= n; i++) scanf("%d", u + i);
	while (m--) {
		int x, y; scanf("%d%d", &x, &y);
		if ((u[x] + 1) % h == u[y]) {
			adj[x].push_back(y);
			radj[y].push_back(x);
		}
		if ((u[y] + 1) % h == u[x]) {
			adj[y].push_back(x);
			radj[x].push_back(y);
		}
	}
	SCC();
	
	for (int i = 1; i <= n; i++) cnt[vis[i]]++;
	int mi = n + 1, p;
	for (int i = 1; i <= n; i++) 
		for (auto u : adj[i]) if (vis[i] != vis[u]) chk[vis[i]] = true;
	for (int i = 1; i <= cn; i++) if (!chk[i] && mi > cnt[i]) mi = cnt[i], p = i;	 
	printf("%d\n", mi);
	for (int i = 1; i <= n; i++) if (vis[i] == p) printf("%d ", i);
	return 0;
}
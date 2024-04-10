#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int c[N], ans[N * 4], prv[2 * N], q[2 * N], cnt[N];
int vis[N], v[N];
vector<int> adj[N], radj[N];

int cn, qn, n, m;
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
		if (!vis[i]) dfs(i);
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
	//freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	bool seek = false;
	for (int i = 1; i <= n; i++) {
		scanf("%d", c + i);
		for (int j = 0; j < c[i]; j++) {
			int x; scanf("%d", &x);
			adj[i].push_back(x);
			radj[x].push_back(i);
		}
	}
	
	int s; scanf("%d", &s);
	int st = 0, ed = 0;
	q[ed++] = s * 2;
	vis[2 * s] = true;
	while(st < ed) {
		int u = q[st++];
		for (int i = 0; i < adj[u / 2].size(); i++) {
			int v = adj[u / 2][i], r = u % 2;
			if (vis[v * 2 + 1 - r]) continue;
			vis[v * 2 + 1 - r] = true;
			prv[v * 2 + 1 - r] = u;
			q[ed++] = v * 2 + 1 - r;
		}
	}
	int x = -1;
	for (int i = 1; i <= n; i++) {
		if (c[i] == 0 && vis[2 * i + 1]) x = 2 * i + 1;
	}
	if (~x) {
		puts("Win");
		int cc = 0;
		while(1) {
			ans[cc++] = x / 2;
			if (x == 2 * s) break;
			x = prv[x];
		}
		for (int i = cc - 1; i >= 0; i--) printf("%d%c", ans[i], " \n"[i == 0]);
		return 0;
	}
	for (int i = 0; i <= 2 * n; i++) v[i] = vis[i];
	//memset(vis, 0, sizeof vis);
	SCC();
	for (int i = 1; i <= n; i++) cnt[vis[i]]++;
	for (int i = 1; i <= n; i++) {
		if ((v[2 * i] || v[2 * i + 1]) && cnt[vis[i]] > 1) {
			
			return puts("Draw"), 0;
		}
	}
	return puts("Lose"), 0;
}
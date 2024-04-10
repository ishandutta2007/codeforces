#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << (x) << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

int bob[N], vis[N], sz[N], ans[N]; 
vi G[N];

void get_size(int u, int p = -1) {
	sz[u] = 1;
	for(int v:G[u]) if(!vis[v] && v != p) {
		get_size(v, u);
		sz[u] += sz[v];
	}
}

void get_c(int u, int tot_sz, int& c, int p = -1) {
	int mx = tot_sz - sz[u];
	for(int v:G[u]) if(!vis[v] && v != p) {
		get_c(v, tot_sz, c, u);
		mx = max(mx, sz[v]);
	}
	if(mx * 2 <= tot_sz) c = u;
}

V<pi> tt, qq;

void dfs(int u, int p, int depth = 1) {
	tt.EB(bob[u] - depth, bob[u]);
	qq.EB(depth, u); 
	for(int v:G[u]) if(!vis[v] && v != p)
		dfs(v, u, depth + 1);
}

void centroid_decomposition(int u) {
	get_size(u);
	int c;
	get_c(u, sz[u], c);
	tt.clear();
	qq.clear();
	tt.EB(bob[c], bob[c]);
	qq.EB(0, c);
	for(int v:G[c]) if(!vis[v])
		dfs(v, c); 
	sort(ALL(tt)); reverse(ALL(tt));
	sort(ALL(qq)); reverse(ALL(qq));
	int mx = -INF;
	for(int i = 0, j = 0; i < qq.size(); i++) {
		while(j < tt.size() && tt[j].F > qq[i].F) mx = max(mx, tt[j++].S);
		ans[qq[i].S] = max(ans[qq[i].S], mx);
	}
	vis[c] = 1;
	for(int v:G[c]) if(!vis[v])
		centroid_decomposition(v);
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	int k;
	cin >> k;
	queue<int> q;
	for(int i = 0; i < k; i++) {
		int u;
		cin >> u;
		q.push(u);
		vis[u] = 1, bob[u] = 0;
	}
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int v:G[u]) if(!vis[v]) {
			vis[v] = 1;
			bob[v] = bob[u] + 1;
			q.push(v);
		}
	}
	memset(vis, 0, sizeof vis);
	centroid_decomposition(1);
	for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}
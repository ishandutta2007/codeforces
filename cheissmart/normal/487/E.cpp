#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops", "no-stack-protector")
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

vi G[N], bcc_id[N], s;
multiset<int> all_w[N];
int cnt, low[N], vis[N], t, id[N], w[N], ww[N];
void dfs(int u, int p = 0) {
	low[u] = vis[u] = ++t;
	s.PB(u);
	for(int v:G[u]) if(v != p) {
		if(vis[v]) low[u] = min(low[u], vis[v]);
		else {
			dfs(v, u);
			if(low[v] >= vis[u]) {
				++cnt;
				int k;
				do {
					k = s.back(); s.pop_back();
					bcc_id[k].PB(cnt);
				} while(k != v);
				bcc_id[u].PB(cnt);
			}
			low[u] = min(low[v], low[u]);
		}
	}
}

vi g[N], b;
int sz[N], up[N], tin[N], pa[N], depth[N];
bool iscut[N];

void dfs_sz(int u, int p = 0, int cur_depth = 1) {
	sz[u] = 1, pa[u] = p, depth[u] = cur_depth;
	for(int i=0;i<(int)g[u].size()-1;i++) {
		if(g[u][i] == p) swap(g[u][i], g[u].back());
		dfs_sz(g[u][i], u, cur_depth + 1);
		sz[u] += sz[g[u][i]];
		if(sz[g[u][i]] > sz[g[u][0]]) swap(g[u][i], g[u][0]);
	}
}

void dfs_hld(int u) {
	tin[u] = b.size();
	b.PB(u);
	for(int i=0;i<(int)g[u].size()-1;i++) {
		if(i == 0) up[g[u][i]] = up[u];
		else up[g[u][i]] = g[u][i];
		dfs_hld(g[u][i]);
	}
}


int seg[4*N];
void build(int v = 1, int tl = 0, int tr = b.size()) {
	if(tr - tl == 1) {
		seg[v] = ww[b[tl]];
		return;
 	}
 	int tm = (tl + tr) / 2;
 	build(v*2, tl, tm);
 	build(v*2+1, tm, tr);
 	seg[v] = min(seg[v*2], seg[v*2+1]);
}

void upd(int pos, int val, int v = 1, int tl = 0, int tr = b.size()) {
	if(tr - tl == 1) {
		seg[v] = val;
		return;
	}
	int tm = (tl + tr) / 2;
	if(pos < tm) upd(pos, val, v*2, tl, tm);
	else upd(pos, val, v*2+1, tm, tr);
 	seg[v] = min(seg[v*2], seg[v*2+1]);
}

int qry(int l, int r, int v = 1, int tl = 0, int tr = b.size()) {
	if(l >= r) return INF;
	if(l == tl && r == tr)  return seg[v];
	int tm = (tl + tr) / 2;
	return min(qry(l, min(r, tm), v*2, tl, tm),
		       qry(max(tm, l), r, v*2+1, tm, tr));
}

int query(int u, int v) {
	int ans = min(ww[u], ww[v]);
	while(true){
		if(up[u] == up[v]) {
			if(depth[u] > depth[v]) swap(u, v);
			ans = min(ans, qry(tin[u], tin[v]+1));
			break;
		}
		if(depth[up[u]] > depth[up[v]]) swap(u, v);
		ans = min(ans, qry(tin[up[v]], tin[v]+1));
		v = pa[up[v]];
	}
	return ans;
}

int lca(int u, int v) {
	if(up[u] == up[v]) return depth[u] < depth[v] ? u : v;
	if(depth[up[u]] > depth[up[v]]) swap(u, v);
	return lca(u, pa[up[v]]);
}

signed main()
{
	IO_OP;
	
	int n, m, q;
	cin >> n >> m >> q;
	for(int i=1;i<=n;i++) cin >> w[i];
	for(int i=0;i<m;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(rand()%n+1);
	memset(ww, 0x3f, sizeof ww);
	for(int i=1;i<=n;i++) {
		if(bcc_id[i].size() > 1) { // cut vertex
			id[i] = ++cnt;
			iscut[id[i]] = true;
			ww[id[i]] = w[i];
			all_w[id[i]].insert(w[i]);
			for(int j:bcc_id[i]) {
				g[id[i]].PB(j);
				g[j].PB(id[i]);
			}
		} else {
			id[i] = bcc_id[i][0];
			ww[id[i]] = min(ww[id[i]], w[i]);
			all_w[id[i]].insert(w[i]);
		}
	}
	g[1].PB(0);
	dfs_sz(1);
	up[1] = 1;
	dfs_hld(1);
	for(int i=1;i<=n;i++) {
		if(bcc_id[i].size() > 1) { // cut vertex
			if(pa[id[i]]) {
				int j = pa[id[i]];
				all_w[j].insert(w[i]);
				ww[j] = *all_w[j].begin();
			}
		}
	}
	// for(int i=1;i<=n;i++) 
	// 	cout << "id[" << i << "] = " << id[i] << endl;
	build();
	while(q--) {
		char op;
		cin >> op;
		if(op == 'C') {
			int u, val;
			cin >> u >> val;
			int j = id[u];
			all_w[j].erase(w[u]);
			all_w[j].insert(val);
			ww[j] = *all_w[j].begin();
			upd(tin[j], ww[j]);
			if(bcc_id[u].size() > 1) {
				int j = pa[id[u]];
				if(j) {
					all_w[j].erase(w[u]);
					all_w[j].insert(val);
					ww[j] = *all_w[j].begin();
					upd(tin[j], ww[j]);
				}
			}
			w[u] = val;
		} else{
			int u, v;
			cin >> u >> v;
			if(u == v) {
				cout << w[u] << endl;
				continue;
			}
			u = id[u], v = id[v];
			int ans = query(u, v);
			int l = lca(u, v);
			if(pa[l] && iscut[pa[l]]) ans = min(ans, ww[pa[l]]);
			cout << ans << endl;
		}
	}


}
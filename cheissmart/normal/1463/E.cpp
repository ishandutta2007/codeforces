#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 3e5 + 7;

vi G[N], g[N], chain[N];
int p[N];
int isx[N], isy[N];
int xx[N], yy[N], cnt[N], tt[N], sz[N], can[N];
vi yes, ans;

void dfs(int u) {
	can[u] = 1;
	if(tt[u]) {
		cnt[tt[u]] += sz[u];
		if(cnt[tt[u]] == chain[tt[u]].size()) {
			yes.PB(tt[u]);
		}
		return;
	}
	ans.PB(u);
	for(int v:G[u]) dfs(v);
}

void dfs2(int u) {
	if(tt[u]) sz[u] = 1;
	for(int v:G[u]) {
		dfs2(v);
		if(tt[u] == tt[v]) sz[u] += sz[v];
	}
}

int vis[N];

bool dfs1(int u) {
	vis[u] = 1;
	for(int v:g[u]) {
		if(vis[v] == 0 && dfs1(v)) return true;
		if(vis[v] == 1) return true;
	}
	vis[u] = 2;
	return false;
}

signed main()
{
	IO_OP;

	int n, k;
	cin >> n >> k;
	int root = -1;
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
		if(p[i] == 0) root = i;
		else G[p[i]].PB(i);
	}
	for(int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		if(isx[x] || isy[y] || p[x] == y) return cout << 0 << endl, 0;
		g[x].PB(y);
		xx[i] = x, yy[i] = y;
		isx[x] = 1, isy[y] = 1;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i] == 0 && dfs1(i))
			return cout << 0 << endl, 0;
	}
	for(int i = 1; i <= n; i++) {
		if(isx[i] && !isy[i]) {
			int u = i;
			while(true) {
				chain[i].PB(u);
				tt[u] = i;
				if(g[u].size()) u = g[u][0];
				else break;
			}
		}
	}
	dfs2(root);
	dfs(root);
	while(yes.size()) {
		int i = yes.back(); yes.pop_back();
		vi tmp;
		for(int u:chain[i]) {
			if(!can[u]) return cout << 0 << endl, 0;
			ans.PB(u);
			for(int v:G[u]) can[v] = 1, tmp.PB(v);
		}
		for(int u:tmp) if(tt[u] != i) dfs(u);
	}
	if(ans.size() < n) return cout << 0 << endl, 0;
	for(int i = 0; i < n; i++) cout << ans[i] << " ";
	cout << endl;
}
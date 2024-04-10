#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second
#define up asdfkl

const int MAXN = 5e5 + 10;//XXX

int n, m;
vector<int> adj[MAXN], _adj[MAXN];
int depth[MAXN];
bool vis[MAXN];

int dfs(int v, int p = -1, int de = 0){
	vis[v] = true;
	depth[v] = de;

	int mn = de;
	for (int u:adj[v])
		if (u ^ p){
			if (vis[u])
				mn = min(mn, depth[u]);
			else
				mn = min(mn, dfs(u, v, de+1));
		}

	if (mn != de && ~p){
		_adj[v].push_back(p);
		_adj[p].push_back(v);
	}

	return mn;
}

int comp[MAXN], g;
vector<int> vec[MAXN];
void _dfs(int v){
	if (vis[v]) return;
	vis[v] = true;
	comp[v] = g;
	vec[g].push_back(v);
	
	for (int u:_adj[v]) _dfs(u);
}

int sec[MAXN], sz, ord[MAXN];
void dfsOrder(int c){
	if (vis[c]) return;
	vis[c] = true;
	ord[c] = sz;
	sec[sz++] = c;

	for (int v: vec[c])
		for (int u:adj[v])
			dfsOrder(comp[u]);
}

int dn[MAXN], up[MAXN];
int _dn[MAXN], _up[MAXN];
set<pii> stL, stR;
int xL, xR;
int get(int ind, int t, int tt){
	ind += t;
	while (ind >= tt) ind -= tt;
	while (ind < 0) ind += tt;
	return ind;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	memset(vis, 0, sizeof(vis));
	for (int v = 0; v < n; v++)
		if (!vis[v] && _adj[v].size() < 2)
			_dfs(v), g++;
	memset(vis, 0, sizeof(vis));
	dfsOrder(0);

	for (int i = sz-1; ~i; i--){
		int c = sec[i];
		for (int v:vec[c]) {
			for (int u:adj[v])
				if (ord[comp[u]] > ord[c])
					dn[v] = max(dn[v], dn[u] + 1);
			_dn[v] = dn[v];
		}

		int tt = vec[c].size();

		stL.clear(), stR.clear();
		int tL = tt-1>>1, tR = tt>>1;
		for (int j = 0; j < tR; j++)
			stR.insert({dn[vec[c][j+1]] + j+1, j+1});
		for (int j = 1; j <= tL; j++)
			stL.insert({dn[vec[c][tt-j]] + j, tt-j});

		xL = xR = 0;
		for (int j = 0; j < tt; j++){
			int v = vec[c][j];

			int mx = tt>1? max(stR.rbegin()->F+xR, stL.rbegin()->F+xL): 0;
			for (int u:adj[v])
				if (ord[comp[u]] > ord[c]) {
					up[u] = max(up[u], 1 + mx);
					mx = max(mx, dn[u] + 1);
				}
			reverse(adj[v].begin(), adj[v].end());
			mx = tt>1? max(stR.rbegin()->F+xR, stL.rbegin()->F+xL): 0;
			for (int u:adj[v])
				if (ord[comp[u]] > ord[c]) {
					up[u] = max(up[u], 1 + mx);
					mx = max(mx, dn[u] + 1);
				}

      if (tt>1){
			dn[v] = max({dn[v], stR.rbegin()->F+xR, stL.rbegin()->F+xL});
			
			stR.erase({_dn[vec[c][get(j, 1, tt)]]+1-xR, get(j, 1, tt)});
			stL.erase({_dn[vec[c][get(j, -tL, tt)]]+tL-xL, get(j, -tL, tt)});

			xR--, xL++;
			stL.insert({_dn[v]+1-xL, j});
			stR.insert({_dn[vec[c][get(j,tR+1,tt)]]+tR-xR, get(j, tR+1, tt)});
		}
	}
	}

	for (int i = 0; i < sz; i++){
		int c = sec[i];
		for (int v:vec[c]) {
			for (int u:adj[v])
				if (ord[comp[u]] < ord[c])
					up[v] = max(up[v], up[u] + 1);
			_up[v] = up[v];
		}

		int tt = vec[c].size();
		stL.clear(), stR.clear();
		int tL = tt-1>>1, tR = tt>>1;
		for (int j = 0; j < tR; j++)
			stR.insert({up[vec[c][j+1]] + j+1, j+1});
		for (int j = 1; j <= tL; j++)
			stL.insert({up[vec[c][tt-j]] + j, tt-j});

		xL = xR = 0;
		for (int j = 0; j < tt; j++){
			int v = vec[c][j];



			if (tt>1){

				up[v] = max({up[v], stR.rbegin()->F+xR, stL.rbegin()->F+xL});

				stR.erase({_up[vec[c][get(j, 1, tt)]]+1-xR, get(j, 1, tt)});
				stL.erase({_up[vec[c][get(j, -tL, tt)]]+tL-xL, get(j, -tL, tt)});

				xR--, xL++;
				stL.insert({_up[v]+1-xL, j});
				stR.insert({_up[vec[c][get(j,tR+1,tt)]]+tR-xR, get(j, tR+1, tt)});
			}
		}
	}

	for (int v = 0; v < n; v++)
		cout << max(dn[v], up[v]) << " ";
	cout << "\n";
	return 0;
}
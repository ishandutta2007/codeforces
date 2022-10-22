#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 10;

#define up lsadfklj
#define F first
#define S second

int n, m, q, comp[MAXN], g, dn[MAXN], up[MAXN], d[MAXN], sec[MAXN], tl[MAXN], tr[MAXN], dd[MAXN];
ll pt[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p = -1){
	comp[v] = g;
	int mx = -1e9;
	for (int u:adj[v])
		if (u^p){
			dfs(u, v);
			dn[v] = max(dn[v], dn[u] + 1);

			up[u] = max(up[u], mx+2);
			mx = max(mx, dn[u]);
		}

	reverse(adj[v].begin(), adj[v].end());
	mx = -1e9;
	for (int u:adj[v])
		if (u^p){
			up[u] = max(up[u], mx+2);
			mx = max(mx, dn[u]);
		}
}

void dfs2(int v, int p = -1){
	if (~p)
		up[v] = max(up[v], up[p] + 1);
	d[v] = max(up[v], dn[v]);
	for (int u:adj[v])
		if (u^p)
			dfs2(u, v);
}

bool cmp(int u, int v){
	if (comp[u] ^ comp[v])
		return comp[u] < comp[v];
	return d[u] < d[v];
}
bool cmp2(int u, int val){return d[u] < val;}

map<pii, ld> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	cin >> n >> m >> q;
	while (m--){
		int u, v;	cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int v = 0; v < n; v++)
		if (!comp[v]){
			g++;
			dfs(v);
			dfs2(v);
		}
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);
	for (int i = 0; i < n;){
		int j = i;
		while (j < n && comp[sec[i]] == comp[sec[j]]) j++;
		tl[comp[sec[i]]] = i;
		tr[comp[sec[i]]] = j;
		i = j;
	}
	for (int v = 0; v < n; v++)
		dd[comp[v]] = max(dd[comp[v]], d[v]);

	for (int i = 0; i < n; i++){
		pt[i + 1] = d[sec[i]];
		if (i && comp[sec[i]] == comp[sec[i - 1]])
			pt[i + 1] += pt[i];
	}
	
	while (q--){
		int u, v; cin >> u >> v, u--, v--;
		u = comp[u], v = comp[v];
		if (u == v){
			cout << "-1\n";
			continue;
		}

		if (tr[u] - tl[u] > tr[v] - tl[v]) swap(u, v);
		if (!mp.count({u, v})){
			ll sm = 0;
			int mx = max(dd[u], dd[v]);
			for (int i = tl[u]; i < tr[u]; i++){
				int x = sec[i];
				int req = mx - d[x];
				int pos = lower_bound(sec + tl[v], sec + tr[v], req, cmp2) - sec;
				sm += 1ll * (pos-tl[v]) * mx;
				sm += 1ll * (tr[v]-pos) * (d[x] + 1) + (pt[tr[v]] - (pos == tl[v]?0ll:pt[pos]));
			}
			int s1 = tr[u] - tl[u];
			int s2 = tr[v] - tl[v];
			mp[{u, v}] = sm/ ld(1ll*s1*s2);
		}
		cout << mp[{u, v}] << "\n";
	}
	return 0;
}
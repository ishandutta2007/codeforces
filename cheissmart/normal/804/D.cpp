#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define V vector
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "LINE(" << __LINE__ << ") -> " << #x << " is " << x << endl
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;
 
const int INF = 1e9 + 7, N = 1e5 + 7;
 
int p[N], s[N];
 
int find(int u) {
	return p[u] == u ? u : p[u] = find(p[u]);
}
 
void unite(int x, int y) {
	int rx = find(x), ry = find(y);
	assert(rx != ry);
	if(s[rx] > s[ry]) swap(rx, ry);
	p[rx] = ry;
	s[ry] += s[rx];
}
 
vi G[N], aux[N];
V<ll> aux_suffix_sum[N];
 
int mxd[N], d[N], f[N];
 
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
 
	int n, m, q;
	cin >> n >> m >> q;
 
	for(int i = 1; i <= n; i++) {
		p[i] = i, s[i] = 1;
	}
 
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
		unite(u, v);
	}
	for(int i = 1; i <= n; i++) if(find(i) == i) {
		vi nodes;
		function<void(int, int)> dfs = [&](int u, int p) {
			mxd[u] = 0;
			nodes.PB(u);
			for(int v:G[u]) if(v != p) {
				dfs(v, u);
				d[i] = max(d[i], mxd[u] + 1 + mxd[v]);
				mxd[u] = max(mxd[u], 1 + mxd[v]);
			}
		};
		dfs(i, 0);
		function<void(int, int, int)> dfs2 = [&](int u, int p, int up) {
			f[u] = max(mxd[u], up);
			vi ch;
			for(int v:G[u]) if(v != p) {
				ch.PB(v);
			}
			vi pmx(ch.size()), smx(ch.size());
			for(int i = 0; i < ch.size(); i++) {
				pmx[i] = mxd[ch[i]] + 1;
				if(i) pmx[i] = max(pmx[i], pmx[i - 1]);
			}
			for(int i = int(ch.size()) - 1; i >= 0; i--) {
				smx[i] = mxd[ch[i]] + 1;
				if(i + 1 < ch.size())
					smx[i] = max(smx[i], smx[i + 1]);
			}
			for(int i = 0; i < ch.size(); i++) {
				int upp = up;
				if(i) upp = max(upp, pmx[i - 1]);
				if(i + 1 < ch.size())
					upp = max(upp, smx[i + 1]);
				int v = ch[i];
				dfs2(v, u, upp + 1);
			}
		};
		dfs2(i, 0, 0);
		for(int u:nodes)
			aux[i].PB(f[u]);
		sort(ALL(aux[i]));
		aux_suffix_sum[i].resize(aux[i].size());
		for(int j = int(aux[i].size()) - 1; j >= 0; j--) {
			aux_suffix_sum[i][j] = aux[i][j];
			if(j + 1 < aux[i].size())
				aux_suffix_sum[i][j] += aux_suffix_sum[i][j + 1];
		}
	}
	map<pi, double> memo;
	cout << fixed << setprecision(10);
	while(q--) {
		int u, v;
		cin >> u >> v;
		u = find(u), v = find(v);
		if(u == v) {
			cout << -1 << '\n';
			continue;
		}
		if(s[u] > s[v]) swap(u, v);
		if(memo.count(MP(u, v))) {
			cout << memo[{u, v}] << '\n';
			continue;
		}
		int D = max(d[u], d[v]);
		ll sum = 0; // cnt for D
		for(int f1:aux[u]) {
			// find first f2 s.t. f2 > D - f1 - 1
			int pos = upper_bound(ALL(aux[v]), D - f1 - 1) - aux[v].begin();
			sum += (ll) D * pos;
			if(pos < aux[v].size())
				sum += (f1 + 1LL) * (aux[v].size() - pos) + aux_suffix_sum[v][pos];
		}
		cout << (memo[{u, v}] = (double) sum / s[u] / s[v]) << '\n';
	}
 
}
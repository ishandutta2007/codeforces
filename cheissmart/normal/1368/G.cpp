#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

int t[N*4], lz[N*4], C;

int sum(int u, int tl, int tr) {
	if(lz[u]) return tr - tl;
	else return t[u];
}

void pull(int u, int tl, int tr) {
	int tm = (tl + tr) / 2;
	t[u] = sum(u * 2, tl, tm) + sum(u * 2 + 1, tm, tr);
}

void bld(int v = 1, int tl = 0, int tr = C) {
	if(tr - tl == 1) {
		t[v] = lz[v] = 0;
		return;
	}
	int tm = (tl + tr) / 2;
	bld(v * 2, tl, tm);
	bld(v * 2 + 1, tm, tr);
	pull(v, tl, tr);
}

void upd(int l, int r, int type, int v = 1, int tl = 0, int tr = C) {
 	if(l >= r) return;
	if(l == tl && r == tr) {
		lz[v] += type;
		return;
	}
	int tm = (tl + tr) / 2;
	upd(l, min(r, tm), type, v * 2, tl, tm);
	upd(max(l, tm), r, type, v * 2 + 1, tm, tr);
	pull(v, tl, tr);
}

int qry() {
	return t[1];
}

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	C = n * m;
	V<V<char>> a(n, V<char>(m));
	V<V<V<pi>>> G(n, V<V<pi>>(m));
	V<V<V<pi>>> link(n, V<V<pi>>(m));
	V<vi> tin(n, vi(m)), tout(n, vi(m)), vis(n, vi(m)), deg(n, vi(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	V<pi> roots;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(j + 2 < m && a[i][j + 2] == 'R') deg[i][j + 2]++;
			if(j - 2 >= 0 && a[i][j - 2] == 'L') deg[i][j - 2]++;
			if(i + 2 < n && a[i + 2][j] == 'D') deg[i + 2][j]++;
			if(i - 2 >= 0 && a[i - 2][j] == 'U') deg[i - 2][j]++;
		}
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(deg[i][j] == 0)
				roots.EB(i, j);
	int tm = 0;
	function<void(int, int)> dfs = [&](int i, int j) {
		tin[i][j] = tm++;
		if(j + 2 < m && a[i][j + 2] == 'R') {
			dfs(i, j + 2);
			G[i][j].EB(i, j + 2);
		}
		if(j - 2 >= 0 && a[i][j - 2] == 'L') {
			dfs(i, j - 2);
			G[i][j].EB(i, j - 2);
		}
		if(i + 2 < n && a[i + 2][j] == 'D') {
			dfs(i + 2, j);
			G[i][j].EB(i + 2, j);
		}
		if(i - 2 >= 0 && a[i - 2][j] == 'U') {
			dfs(i - 2, j);
			G[i][j].EB(i - 2, j);
		}
		tout[i][j] = tm;
	};
	for(pi p:roots) dfs(p.F, p.S);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == 'L') {
				link[i][j].EB(i, j + 1);
			} else if(a[i][j] == 'R') {
				link[i][j].EB(i, j - 1);
			} else if(a[i][j] == 'U') {
				link[i][j].EB(i + 1, j);
			} else {
				link[i][j].EB(i - 1, j);
			}
		}
	}
	bld();
	ll ans = 0;
	function<void(int, int)> dfs1 = [&](int i, int j) {
		for(pi u:link[i][j]) {
			int l = tin[u.F][u.S];
			int r = tout[u.F][u.S];
			upd(l, r, 1);
		}
		ans += qry();
		for(pi u:G[i][j]){
			dfs1(u.F, u.S);
		}
		for(pi u:link[i][j]) {
			int l = tin[u.F][u.S];
			int r = tout[u.F][u.S];
			upd(l, r, -1);
		}
	};
	for(pi u:roots) {
		if((u.F + u.S) % 2 == 0)
			dfs1(u.F, u.S);
	}

	cout << ans << endl;
}
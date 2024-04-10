#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define ull unsigned long long

using namespace std;

void setIO(string name) {
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

const int N = 1e5 + 100;
const int pod = (1 << 17);

int n, m;
int a, b;
vector <int> v[N];

int in[N], out[N], Time, ord[N];

void dfs(int u, int p) {
	in[u] = ++Time;
	ord[Time] = u;
	for (auto it : v[u])
		if (it != p)
			dfs(it, u);
	out[u] = Time;
}

struct gao {
	int a, b, c, d, z;
};

vector <gao> g[N];
int ans[N];

struct seg {
	pair<int, int> t[2 * pod];
	int lazy[2 * pod];
	
	pair <int, int> merge(int u) {
		int x = 2 * u, y = 2 * u + 1;
		if (t[x].fi == t[y].fi) return {t[x].fi, t[x].se + t[y].se};
		if (t[x].fi < t[y].fi) return {t[x].fi, t[x].se};
		return {t[y].fi, t[y].se};
	}
	
	void init() {
		rep(i, pod, 2 * pod - 1) t[i] = {0, 1};
		per(i, 1, pod - 1) t[i] = merge(i);
		rep(i, 1, 2 * pod - 1) lazy[i] = 0;
	}
	
	void push(int u) {
		t[2 * u].fi += lazy[u];
		t[2 * u + 1].fi += lazy[u];
		lazy[2 * u] += lazy[u];
		lazy[2 * u + 1] += lazy[u];
		lazy[u] = 0;
	}
	
	void add(int x, int y, int z, int u = 1, int l = 0, int r = pod - 1) {
		if (x <= l && r <= y) {
			t[u].fi += z;
			lazy[u] += z;
			return;
		}
		push(u);
		int m = (l + r) / 2;
		if (x <= m) add(x, y, z, 2 * u, l, m);
		if (m < y) add(x, y, z, 2 * u + 1, m + 1, r);
		t[u] = merge(u);
	}
} ja;

void qw(int l, int r, int c) {
	if (l == -1) return;
	ja.add(l, r, c);
}

int main() {
	ja.init();
	scanf ("%d%d", &n, &m);
	rep(i, 1, n - 1) {
		scanf ("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, 0);
	while (m--) {
		scanf ("%d%d", &a, &b);
		int la = in[a];
		int ra = out[a];
		int lb = in[b];
		int rb = out[b];
		if (la > lb) {
			swap(la, lb);
			swap(ra, rb);
		}
		if (rb <= ra) {
			g[la].pb({la, ra, -1, -1, 1});
			g[ra + 1].pb({la, ra, -1, -1, -1});
		}
		else {
			g[la].pb({la, ra, lb, rb, 1});
			g[ra + 1].pb({la, ra, lb, rb, -1});
			g[lb].pb({la, ra, lb, rb, 1});
			g[rb + 1].pb({la, ra, lb, rb, -1});
		}
	}
	rep(i, 1, n) {
		for (auto it : g[i]) {
			qw(it.a, it.b, it.z);
			qw(it.c, it.d, it.z);
		}
		qw(i, i, 1);
		ans[ord[i]] = pod - ja.t[1].se;
		qw(i, i, -1);
	}
	rep(i, 1, n) printf ("%d ", ans[i] - 1);
	
	
	return 0;
}
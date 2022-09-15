#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 200010;
int n, k;
int a[maxn];
vi adj[maxn];
pi f[maxn];
int d;

pi dfs(int u, int p, int m) {
	pi& res = f[u];
	if (~res.fi) return res;
	res = mp(1, 1);
	int dmax = 0;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p) {
			pi r = dfs(v, u, m);
			res.fi += r.fi;
			if (r.fi > r.se) setmax(dmax, r.se);
			else res.se += r.se;
		}
	}
	res.se += dmax;
	if (a[u] < m) {
		return res = mp(1, 0);
	}
	return res;
}

void dfs2(int u, int p, pi val, int m) {
	vi vt;
	vii pref, suff;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p) {
			vt.pb(v);
			pref.pb(f[v]);
			suff.pb(f[v]);
		}
	}
	pi t = mp(0, 0);
	vi tmp;
	int sum = 0;
	FOR(i, 0, sz(pref)) {
		tmp.pb(pref[i].fi);
		sum += pref[i].fi;
		if (pref[i].fi == pref[i].se) {
			t.fi += pref[i].fi;
		}
		else {
			setmax(t.se, pref[i].se);
		}
		pref[i] = t;
	}
	t = mp(0, 0);
	FORd(i, sz(suff), 0) {
		if (suff[i].fi == suff[i].se) {
			t.fi += suff[i].fi;
		}
		else {
			setmax(t.se, suff[i].se);
		}
		suff[i] = t;
	}
	FOR(i, 0, sz(vt)) {
		int v = vt[i];
		int x, y;
		if (val.fi == val.se) {
			x = val.fi;
			y = 0;
		}
		else {
			x = 0;
			y = val.se;
		}
		if (i) {
			x += pref[i - 1].fi;
			setmax(y, pref[i - 1].se);
		}
		if (i < sz(vt) - 1) {
			x += suff[i + 1].fi;
			setmax(y, suff[i + 1].se);
		}
		if (a[u] >= m) {
			x++;
		}
		else {
			x = y = 0;
		}
		dfs2(v, u, mp(val.fi + sum - tmp[i] + 1, x + y), m);
	}
	if (a[u] >= m) {
		int x, y;
		if (val.fi == val.se) {
			x = val.fi;
			y = 0;
		}
		else {
			x = 0;
			y = val.se;
		}
		if (f[u].fi == f[u].se) {
			x += f[u].fi;
		}
		else {
			setmax(y, f[u].se);
		}
		setmax(d, x + y);
	}
}

void solve() {
	scanf("%d%d", &n, &k);
	FOR(i, 0, n) scanf("%d", a + i);
	FOR(i, 0, n - 1) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	int l = 1, r = 1000000;
	while (l < r) {
		int m = (l + r + 1) >> 1;
		ms(f, -1); d = 0;
		dfs(0, -1, m); dfs2(0, -1, mp(0, 0), m);
		if (d >= k) l = m; else r = m - 1;
	}
	printf("%d", l);
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
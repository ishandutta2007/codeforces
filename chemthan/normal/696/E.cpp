#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int MAXN = 100000 + 10;
int n, m, q;
vector<int> adj[MAXN];
vector<int> g[MAXN];
int id[MAXN];
int size[MAXN];
int lev[MAXN];
int p[MAXN];
int num[MAXN];
int head[MAXN];
int out[MAXN];
int cnt;

pair<pair<long long, int>, int> st[MAXN << 2];
long long add[MAXN << 2];
long long lz[MAXN << 2];

void updlz(int p, int L, int R) {
	if (lz[p]) {
		add[p] += lz[p];
		st[p].fi.fi += lz[p];
		chkmin(st[p].fi.fi, LINF);
		if (L < R) {
			lz[p << 1] += lz[p];
			lz[p << 1 | 1] += lz[p];
		}
		lz[p] = 0;
	}
}
void upd(int p, int i, int L, int R, int u) {
	updlz(p, L, R);
	if (i < L || i > R) return;
	if (L == R) {
		if (sz(g[u])) {
			int ix = g[u].back();
			g[u].pop_back();
			st[p] = mp(mp(ix + add[p], u), ix);
		}
		else {
			st[p] = mp(mp(LINF, INF), INF);
		}
		return;
	}
	upd(p << 1, i, L, L + R >> 1, u);
	upd(p << 1 | 1, i, (L + R >> 1) + 1, R, u);
	st[p] = min(st[p << 1], st[p << 1 | 1]);
}
void upd2(int p, int l, int r, int L, int R, int val) {
	updlz(p, L, R);
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		lz[p] += val;
		updlz(p, L, R);
		return;
	}
	upd2(p << 1, l, r, L, L + R >> 1, val);
	upd2(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
	st[p] = min(st[p << 1], st[p << 1 | 1]);
}
pair<pair<long long, int>, int> query(int p, int l, int r, int L, int R) {
	updlz(p, L, R);
	if (l > R || r < L) return mp(mp(LINF, INF), INF);
	if (l <= L && r >= R) return st[p];
	return min(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
}

void dfs1(int u, int dad = -1) {
	size[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != dad) {
			p[v] = u, lev[v] = lev[u] + 1;
			dfs1(v, u);
			size[u] += size[v];
		}
	}
}
void dfs2(int u, int h = 0, int dad = -1) {
	num[u] = cnt++, head[u] = h;
	pair<int, int> best = make_pair(-1, -1);
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != dad) {
			best = max(best, make_pair(size[v], v));
		}
	}
	if (~best.second) {
		dfs2(best.second, h, u);
	}
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != dad && v != best.second) {
			dfs2(v, v, u);
		}
	}
	out[u] = cnt - 1;
}
pair<pair<long long, int>, int> query(int u, int v) {
	pair<pair<long long, int>, int> res = mp(mp(LINF, INF), INF);
	int hu = head[u], hv = head[v];
	while (hu != hv) {
		if (lev[hu] < lev[hv]) swap(u, v), swap(hu, hv);
		chkmin(res, query(1, num[hu], num[u], 0, n - 1));
		u = p[hu], hu = head[u];
	}
	if (lev[u] > lev[v]) swap(u, v);
	chkmin(res, query(1, num[u], num[v], 0, n - 1));
	return res;
}

void solve() {
	cin >> n >> m >> q;
	FOR(i, 0, n - 1) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(v), adj[v].pb(u);
	}
	FOR(i, 0, m) {
		int u; cin >> u; u--;
		g[u].pb(i);
	}
	dfs1(0); dfs2(0);
	FOR(i, 0, n) {
		reverse(all(g[i]));
		upd(1, num[i], 0, n - 1, i);
	}
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int u, v, k; cin >> u >> v >> k; u--, v--;
			vi ans;
			while (k--) {
				pair<pair<long long, int>, int> r = query(u, v);
				if (r.fi.fi == LINF) {
					break;
				}
				int ix = r.fi.se;
				upd(1, num[ix], 0, n - 1, ix);
				ans.pb(r.se);
			}
			cout << sz(ans);
			FOR(i, 0, sz(ans)) cout << " " << ans[i] + 1;
			cout << "\n";
		}
		else if (op == 2) {
			int u, x; cin >> u >> x; u--;
			upd2(1, num[u], out[u], 0, n - 1, x);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
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
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 200000 + 10;
const int logn = 20;
int n, m;
vii adj[maxn];
int w[maxn];
int c[maxn];
int choose[maxn];
pi edge[maxn];
int lev[maxn];
int p[logn][maxn];
pi mx[logn][maxn];
int s;

int dj[maxn];
void init() {
	FOR(i, 0, n) dj[i] = i;
}
int find(int u) {
	return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
int join(int u, int v) {
	int p = find(u);
	int q = find(v);
	if (p != q) {
		dj[p] = q;
		return 1;
	}
	return 0;
}

void dfs(int u, int dad = -1) {
	FOR(i, 1, logn) {
		p[i][u] = p[i - 1][p[i - 1][u]];
		mx[i][u] = max(mx[i - 1][u], mx[i - 1][p[i - 1][u]]);
	}
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i].fi;
		int ix = adj[u][i].se;
		if (v != dad) {
			lev[v] = lev[u] + 1;
			p[0][v] = u;
			mx[0][v] = mp(w[ix], ix);
			dfs(v, u);
		}
	}
}

pi query(int u, int v) {
	if (lev[u] < lev[v]) swap(u, v);
	pi res;
	FORd(i, logn, 0) {
		if (lev[p[i][u]] >= lev[v]) {
			chkmax(res, mx[i][u]);
			u = p[i][u];
		}
	}
	FORd(i, logn, 0) {
		if (p[i][u] != p[i][v]) {
			chkmax(res, mx[i][u]);
			chkmax(res, mx[i][v]);
			u = p[i][u];
			v = p[i][v];
		}
	}
	if (u != v) {
		chkmax(res, mx[0][u]);
		chkmax(res, mx[0][v]);
	}
	return res;
}

void solve() {
	cin >> n >> m;
	FOR(i, 0, m) cin >> w[i];
	FOR(i, 0, m) cin >> c[i];
	FOR(i, 0, m) {
		int u, v; cin >> u >> v; u--, v--;
		edge[i] = mp(u, v);
	}
	cin >> s;
	priority_queue<pair<int, int> > pq;
	FOR(i, 0, m) pq.push(mp(-w[i], i));
	init();
	long long tot = 0;
	while (sz(pq)) {
		int ix = pq.top().se;
		pq.pop();
		int u = edge[ix].fi;
		int v = edge[ix].se;
		if (join(u, v)) {
			adj[u].pb(mp(v, ix));
			adj[v].pb(mp(u, ix));
			tot += w[ix];
			choose[ix] = 1;
		}
	}
	dfs(0);
	pair<long long, int> best = mp(tot, -1);
	FOR(i, 0, m) {
		int u = edge[i].fi;
		int v = edge[i].se;
		if (choose[i]) {
			chkmin(best, mp(tot - s / c[i], i));
		}
		else {
			pi mx = query(u, v);
			chkmin(best, mp(tot - mx.fi + w[i] - s / c[i], i));
		}
	}
	cout << best.fi << "\n";
	if (~best.se) {
		int ix = best.se;
		w[ix] -= s / c[ix];
		int u = edge[ix].fi;
		int v = edge[ix].se;
		int ix2 = query(u, v).se;
		choose[ix2] = 0;
		choose[ix] = 1;
	}
	FOR(i, 0, m) if (choose[i]) {
		cout << i + 1 << " " << w[i] << "\n";
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
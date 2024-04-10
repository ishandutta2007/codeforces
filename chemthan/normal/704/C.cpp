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
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 100000 + 10;
int n, m;
int k[maxn];
int a[maxn][2];
int b[maxn];
vi g[maxn];
vii adj[maxn];
int vis[maxn];
int f[maxn][2][2];
int dp[maxn][2];
vector<pair<int, pi> > his;

void clear() {
	while (sz(his)) {
		int u = his.back().fi;
		int aa = his.back().se.fi;
		int b = his.back().se.se;
		f[u][aa][b] = -1;
		his.pop_back();
	}
}

int calc(int u, int x, int y, int pv, int bg, int val) {
	if (u == bg) return x == 0 && y == val;
	vis[u] = 1;
	his.pb(mp(u, mp(x, y)));
	int& res = f[u][x][y];
	if (~res) return res;
	res = 0;
	if (k[u] == 1) {
		if (a[u][0] > 0) return res = x == y;
		else return res = x == (y ^ 1);
	}
	else {
		if (abs(a[u][0]) != (pv >> 1)) swap(a[u][0], a[u][1]);
		int t = y; if (a[u][0] < 0) t = y ^ 1;
		if (sz(adj[u]) == 1) {
			if (!x && t) return res;
			if (t) return res = 2;
			return res = 1;
		}
		if (adj[u][0].se == (pv ^ 1)) {
			swap(adj[u][0], adj[u][1]);
		}
		int v = adj[u][0].fi;
		int w = adj[u][0].se;
		if (a[u][1] > 0) {
			addmod(res, calc(v, x ^ (0 | t), 0, w, bg, val));
			addmod(res, calc(v, x ^ (1 | t), 1, w, bg, val));
		}
		else {
			addmod(res, calc(v, x ^ (1 | t), 0, w, bg, val));
			addmod(res, calc(v, x ^ (0 | t), 1, w, bg, val));
		}
	}
	return res;
}

void solve() {
	cin >> n >> m;
	FOR(i, 0, n) {
		cin >> k[i];
		FOR(j, 0, k[i]) {
			cin >> a[i][j];
			g[abs(a[i][j])].pb(i);
			b[abs(a[i][j])] = 1;
		}
	}
	FOR(i, 1, m + 1) {
		if (sz(g[i]) == 2) {
			int u = g[i][0];
			int v = g[i][1];
			adj[u].pb(mp(v, i << 1));
			adj[v].pb(mp(u, i << 1 | 1));
		}
	}
	ms(f, -1);
	vii vv;
	FOR(i, 0, n) if (!vis[i] && sz(adj[i]) == 1) {
		int r0 = 0, r1 = 0;
		if (k[i] == 1) {
			int v = adj[i][0].fi;
			int w = adj[i][0].se;
			FOR(x, 0, 2) {
				int xx = x;
				if (a[i][0] < 0) xx ^= 1;
				clear();
				addmod(r0, calc(v, xx ^ 0, x, w, i, x));
				addmod(r1, calc(v, xx ^ 1, x, w, i, x));
			}
		}
		else {
			int v = adj[i][0].fi;
			int w = adj[i][0].se;
			if (abs(a[i][0]) == (w >> 1)) {
				swap(a[i][0], a[i][1]);
			}
			FOR(x, 0, 2) FOR(y, 0, 2) {
				int xx = x, yy = y;
				if (a[i][0] < 0) xx ^= 1;
				if (a[i][1] < 0) yy ^= 1;
				clear();
				addmod(r0, calc(v, (xx | yy) ^ 0, y, w, i, x));
				addmod(r1, calc(v, (xx | yy) ^ 1, y, w, i, x));
			}
		}
		vv.pb(mp(r0, r1));
	}
	FOR(i, 0, n) if (!vis[i] && sz(adj[i]) == 2) {
		int r0 = 0, r1 = 0;
		int v = adj[i][0].fi;
		int w = adj[i][0].se;
		if (abs(a[i][0]) == (w >> 1)) {
			swap(a[i][0], a[i][1]);
		}
		FOR(x, 0, 2) FOR(y, 0, 2) {
			int xx = x, yy = y;
			if (a[i][0] < 0) xx ^= 1;
			if (a[i][1] < 0) yy ^= 1;
			clear();
			addmod(r0, calc(v, (xx | yy) ^ 0, y, w, i, x));
			addmod(r1, calc(v, (xx | yy) ^ 1, y, w, i, x));
		}
		vv.pb(mp(r0, r1));
	}
	FOR(i, 0, n) if (!vis[i] && !sz(adj[i])) {
		if (k[i] == 1) {
			vv.pb(mp(1, 1));
		}
		else {
			vv.pb(mp(1, 3));
		}
	}
	dp[0][0] = 1;
	FOR(i, 1, sz(vv) + 1) {
		dp[i][0] = mult(dp[i - 1][0], vv[i - 1].fi);
		addmod(dp[i][0], mult(dp[i - 1][1], vv[i - 1].se));
		dp[i][1] = mult(dp[i - 1][1], vv[i - 1].fi);
		addmod(dp[i][1], mult(dp[i - 1][0], vv[i - 1].se));
	}
	int ans = dp[sz(vv)][1];
	FOR(i, 1, m + 1) {
		if (!b[i]) {
			ans = mult(ans, 2);
		}
	}
	cout << ans << "\n";
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
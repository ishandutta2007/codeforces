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

const int maxn = 500000 + 10;
const int maxc = 22;
int n;
vi adj[maxn];
string w[maxn];
int size[maxn];
int lev[maxn];
vii* f[maxn];
multiset<int> g[1 << maxc];
int mx[1 << maxc];
int ans[maxn];

void dfs1(int u, int p = -1) {
	size[u] = 1;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p) {
			lev[v] = lev[u] + 1;
			dfs1(v, u);
			size[u] += size[v];
		}
	}
}

inline void add(int key, int val) {
	g[key].insert(val);
	mx[key] = *g[key].rbegin();
}

inline void rem(int key, int val) {
	g[key].erase(g[key].find(val));
	mx[key] = sz(g[key]) ? *g[key].rbegin() : -INF;
}

void dfs2(int u, int p = -1, int key = 0, int keep = 0) {
	pi best = mp(-INF, -INF);
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p) {
			chkmax(best, mp(size[v], v));
		}
	}
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p && v != best.se) {
			dfs2(v, u, key ^ (1 << w[v][0] - 'a'), 0);
			chkmax(ans[u], ans[v]);
		}
	}
	if (best.se != -INF) {
		dfs2(best.se, u, key ^ (1 << w[best.se][0] - 'a'), 1);
		chkmax(ans[u], ans[best.se]);
		f[u] = f[best.se];
	}
	else {
		f[u] = new vii;
	}
	chkmax(ans[u], mx[key] - lev[u]);
	FOR(i, 0, maxc) {
		chkmax(ans[u], mx[key ^ (1 << i)] - lev[u]);
	}
	f[u]->pb(mp(key, lev[u]));
	add(key, lev[u]);
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p && v != best.se) {
			FOR(j, 0, sz(*f[v])) {
				int key = (*f[v])[j].fi;
				int val = (*f[v])[j].se;
				chkmax(ans[u], mx[key] + val - 2 * lev[u]);
				FOR(k, 0, maxc) {
					chkmax(ans[u], mx[key ^ (1 << k)] + val - 2 * lev[u]);
				}
			}
			FOR(j, 0, sz(*f[v])) {
				int key = (*f[v])[j].fi;
				int val = (*f[v])[j].se;
				f[u]->pb(mp(key, val));
				add(key, val);
			}
		}
	}
	if (!keep) {
		FOR(i, 0, sz(*f[u])) {
			int key = (*f[u])[i].fi;
			int val = (*f[u])[i].se;
			rem(key, val);
		}
	}
}

void solve() {
	fill_n(mx, 1 << maxc, -INF);
	cin >> n;
	FOR(i, 0, n - 1) {
		int u; cin >> u >> w[i + 1]; u--;
		adj[u].pb(i + 1);
	}
	dfs1(0), dfs2(0);
	FOR(i, 0, n) cout << ans[i] << " \n"[i == n - 1];
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
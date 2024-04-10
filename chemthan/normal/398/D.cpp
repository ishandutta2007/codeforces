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

const int maxn = 50010;
const int magic = 300;
int n, m, q, k;
int a[maxn];
vi adj[maxn];
vi heavy_adj[maxn];
map<int, int> edge[maxn];
int f[maxn];

void addedge(int u, int v) {
	edge[u][v] = 1;
	adj[u].pb(v);
	if (sz(adj[u]) == magic) {
		FOR(i, 0, sz(adj[u])) {
			int w = adj[u][i];
			if (w > 0) {
				heavy_adj[w].pb(u);
				if (w != v) {
					f[w] -= a[u];
				}
			}
		}
	}
	else if (sz(adj[u]) > magic) {
		heavy_adj[v].pb(u);
	}
	else {
		f[v] += a[u];
	}
}

void upd(int u, int v) {
	edge[u][v] ^= 1;
	if (sz(adj[u]) < magic) {
		FOR(i, 0, sz(adj[u])) {
			if (abs(adj[u][i]) == v) {
				adj[u][i] *= -1;
			}
		}
	}
	if (edge[u][v]) {
		if (sz(adj[u]) >= magic) {
			heavy_adj[v].pb(u);
		}
		else {
			f[v] += a[u];
		}
	}
	else {
		FOR(i, 0, sz(heavy_adj[v])) {
			if (heavy_adj[v][i] == u) {
				heavy_adj[v].erase(heavy_adj[v].begin() + i);
				return;
			}
		}
		f[v] -= a[u];
	}
}

void solve() {
	cin >> n >> m >> q >> k;
	FOR(i, 0, k) {
		int u; cin >> u;
		a[u] = 1;
	}
	FOR(i, 0, m) {
		int u, v; cin >> u >> v;
		addedge(u, v); addedge(v, u);
	}
	while (q--) {
		char op; cin >> op;
		if (op == 'O' || op == 'F') {
			int u; cin >> u;
			a[u] ^= 1;
			if (sz(adj[u]) < magic) {
				FOR(i, 0, sz(adj[u])) {
					int v = adj[u][i];
					if (v > 0) {
						f[v] += a[u] ? +1 : -1;
					}
				}
			}
		}
		else if (op == 'A') {
			int u, v; cin >> u >> v;
			if (!edge[u].count(v)) {
				addedge(u, v); addedge(v, u);
			}
			else {
				upd(u, v); upd(v, u);
			}
		}
		else if (op == 'D') {
			int u, v; cin >> u >> v;
			upd(u, v); upd(v, u);
		}
		else if (op == 'C') {
			int u; cin >> u;
			int ans = f[u];
			FOR(i, 0, sz(heavy_adj[u])) {
				int v = heavy_adj[u][i];
				ans += a[v];
			}
			cout << ans << "\n";
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
#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define FORalld(it, a) for (__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
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
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}

struct CentroidTree {
	struct Info {
		int d;
		Info() : d(0) {}
		Info(int d) : d(d) {}
		Info(const Info& rhs) : d(rhs.d) {}
		Info operator + (const int& w) const {
			return Info(d + w);
		}
		Info operator + (const Info& rhs) const {
			return Info(d + rhs.d);
		}
	};
	
	static const int maxn = 100000 + 10;
	static const int logn = 20;
	int n;
	vector<int> adj[maxn];
	int size[maxn];
	int rem[maxn];
	vector<int> tree[maxn];
	int lev[maxn];
	int p[logn][maxn];
	Info info[logn][maxn];
	
	void init(int n) {
		this->n = n;
		for (int i = 0; i < n; i++) {
			adj[i].clear();
			tree[i].clear();
			rem[i] = 0;
		}
	}
	void add(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void dfs(int u, int p) {
		size[u] = 1;
		for (int i = 0; i < (int) adj[u].size(); i++) {
			int v = adj[u][i];
			if (v != p && !rem[v]) {
				dfs(v, u);
				size[u] += size[v];
			}
		}
	}
	int findcentroid(int u) {
		dfs(u, -1);
		int p = -1, t = size[u];
		while (1) {
			pair<int, int> best;
			for (int i = 0; i < (int) adj[u].size(); i++) {
				int v = adj[u][i];
				if (v != p && !rem[v]) {
					best = max(best, make_pair(size[v], v));
				}
			}
			if (best.fi + best.fi <= t) {
				return u;
			}
			p = u, u = best.se;
		}
		assert(0);
	}
	void upd(int u, int dep, int p) {
		for (int i = 0; i < (int) adj[u].size(); i++) {
			int v = adj[u][i];
			if (v != p && !rem[v]) {
				info[dep][v] = info[dep][u] + 1;
				upd(v, dep, u);
			}
		}
	}
	int divide(int u, int dep = 0) {
		lev[u = findcentroid(u)] = dep;
		p[0][u] = u;
		info[dep][u] = Info(0);
		upd(u, dep, -1);
		rem[u] = 1;
		for (int i = 0; i < (int) adj[u].size(); i++) {
			int v = adj[u][i];
			if (!rem[v]) {
				int w = divide(v, dep + 1);
				tree[u].push_back(w);
				p[0][w] = u;
			}
		}
		return u;
	}
	int lca(int u, int v) {
		if (lev[u] < lev[v]) swap(u, v);
		for (int k = logn - 1; k >= 0; k--) {
			if (lev[p[k][u]] >= lev[v]) {
				u = p[k][u];
			}
		}
		if (u == v) return u;
		for (int k = logn - 1; k >= 0; k--) {
			if (p[k][u] != p[k][v]) {
				u = p[k][u], v = p[k][v];
			}
		}
		return p[0][u];
	}
	Info getInfo(int u, int v) {
		int a = lca(u, v);
		int ix = lev[a];
		return info[ix][u] + info[ix][v];
	}
	int mn[maxn];
	void build() {
		divide(0);
		for (int k = 1; k < logn; k++) {
			for (int u = 0; u < n; u++) {
				p[k][u] = p[k - 1][p[k - 1][u]];
			}
		}
		fill_n(mn, n, INF);
	}
	void upd(int u) {
		int v = u;
		while (1) {
			int ix = lev[v];
			mn[v] = min(mn[v], info[ix][u].d);
			if (v == p[0][v]) break;
			v = p[0][v];
		}
	}
	int query(int u) {
		int res = INF;
		int v = u;
		while (1) {
			int ix = lev[v];
			res = min(res, mn[v] + info[ix][u].d);
			if (v == p[0][v]) break;
			v = p[0][v];
		}
		return res;
	}
} ct;

void solve() {
	int n, m; cin >> n >> m;
	ct.init(n);
	FOR(i, 0, n - 1) {
		int u, v; cin >> u >> v; u--, v--;
		ct.add(u, v);
	}
	ct.build();
	ct.upd(0);
	while (m--) {
		int op, u; cin >> op >> u; u--;
		if (op == 1) {
			ct.upd(u);
		}
		else {
			cout << ct.query(u) << "\n";
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
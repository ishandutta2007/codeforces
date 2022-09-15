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
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cout << #x << " = " << (x) << "\n";

int n, k;

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
	
	static const int maxn = 2e5 + 10;
	static const int logn = 20;
	int n, rt;
	vector<int> adj[maxn];
	int size[maxn];
	int del[maxn];
	vector<int> tree[maxn];
	int lev[maxn];
	int p[logn][maxn];
	Info info[logn][maxn];
	
	void init(int n) {
		this->n = n;
		for (int i = 0; i < n; i++) {
			adj[i].clear();
			tree[i].clear();
			del[i] = 0;
		}
	}
	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void dfs(int u, int p) {
		size[u] = 1;
		for (int i = 0; i < (int) adj[u].size(); i++) {
			int v = adj[u][i];
			if (v != p && !del[v]) {
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
				if (v != p && !del[v]) {
					best = max(best, make_pair(size[v], v));
				}
			}
			if (best.first + best.first <= t) {
				return u;
			}
			p = u, u = best.second;
		}
	}
	void upd(int u, int dep, int p) {
		for (int i = 0; i < (int) adj[u].size(); i++) {
			int v = adj[u][i];
			if (v != p && !del[v]) {
				info[dep][v] = info[dep][u] + 1;
				upd(v, dep, u);
			}
		}
	}
	int divide(int u, int dep) {
		lev[u = findcentroid(u)] = dep;
		p[0][u] = u;
		info[dep][u] = Info(0);
		upd(u, dep, -1);
		del[u] = 1;
		for (int i = 0; i < (int) adj[u].size(); i++) {
			int v = adj[u][i];
			if (!del[v]) {
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
	void build() {
		rt = divide(0, 0);
		for (int k = 1; k < logn; k++) {
			for (int u = 0; u < n; u++) {
				p[k][u] = p[k - 1][p[k - 1][u]];
			}
		}
	}
	
	map<int, int> hs;
	long long ans;
	long long cnt[10][10];
	
	void add(int u, int ix) {
		hs[info[ix][u].d % k]++;
		for (int i = 0; i < (int) tree[u].size(); i++) {
			int v = tree[u][i];
			add(v, ix);
		}
	}
	void rem(int u, int ix) {
		hs[info[ix][u].d % k]--;
		for (int i = 0; i < (int) tree[u].size(); i++) {
			int v = tree[u][i];
			rem(v, ix);
		}
	}
	void query(int u, int ix) {
		FOR(i, 0, k) {
			ans += (long long) info[ix][u].d / k * hs[i];
			int j = info[ix][u].d % k;
			if (i <= j) {
				cnt[i][j] += hs[i];
			}
			else {
				cnt[j][i] += hs[i];
			}
		}
		ans += (info[ix][u].d + k - 1) / k;
		for (int i = 0; i < (int) tree[u].size(); i++) {
			int v = tree[u][i];
			query(v, ix);
		}
	}
	void work(int u) {
		hs.clear();
		int ix = lev[u];
		for (int i = 0; i < (int) tree[u].size(); i++) {
			int v = tree[u][i];
			add(v, ix);
		}
		for (int i = 0; i < (int) tree[u].size(); i++) {
			int v = tree[u][i];
			rem(v, ix);
			query(v, ix);
			add(v, ix);
		}
		for (int i = 0; i < (int) tree[u].size(); i++) {
			int v = tree[u][i];
			work(v);
		}
	}
	void get() {
		work(rt);
		FOR(i, 0, k) FOR(j, i, k) {
			ans += (long long) (i + j + k - 1) / k * (cnt[i][j] / 2);
		}
		cout << ans << "\n";
	}
} ct;

void solve() {
	cin >> n >> k;
	ct.init(n);
	FOR(i, 0, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		ct.addEdge(u, v);
	}
	ct.build();
	ct.get();
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
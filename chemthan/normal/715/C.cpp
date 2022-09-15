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

template<class TK, class TV> struct HashTable {
	
	static const int MAGIC = 7654321;
	int size, ptr;
	int cnt;
	int used[MAGIC];
	int lst[MAGIC];
	int* prv;
	TK* l;
	TV* x;
	
	HashTable() {
		size = 1;
		prv = (int*) malloc(size * sizeof(int));
		l = (TK*) malloc(size * sizeof(TK));
		x = (TV*) malloc(size * sizeof(TV));
		ptr = 0;
		fill_n(lst, MAGIC, -1);
		cnt = 0;
	}
	void clear() {
		free(prv);
		free(l);
		free(x);
		size = 1;
		prv = (int*) malloc(size * sizeof(int));
		l = (TK*) malloc(size * sizeof(TK));
		x = (TV*) malloc(size * sizeof(TV));
		ptr = 0;
		for (int i = 0; i < cnt; i++) {
			lst[used[i]] = -1;
		}
		cnt = 0;
	}
	void enlarge() {
		size <<= 1;
		prv = (int*) realloc(prv, size * sizeof(int));
		l = (TK*) realloc(l, size * sizeof(TK));
		x = (TV*) realloc(x, size * sizeof(TV));
	}
	TV& operator [] (const TK& key) {
		int hs = (key % MAGIC + MAGIC) % MAGIC;
		if (!~lst[hs]) {
			used[cnt++] = hs;
		}
		for (int e = lst[hs]; ~e; e = prv[e]) {
			if (l[e] == key) {
				return x[e];
			}
		}
		if (ptr == size) {
			enlarge();
		}
		l[ptr] = key, x[ptr] = 0;
		prv[ptr] = lst[hs], lst[hs] = ptr;
		return x[ptr++];
	}
	void erase(const TK& key) {
		int hs = (key % MAGIC + MAGIC) % MAGIC;
		int nxt = -1;
		for (int e = lst[hs]; ~e; e = prv[e]) {
			if (l[e] == key) {
				if (!~nxt) {
					lst[hs] = prv[e];
				}
				else {
					prv[nxt] = prv[e];
				}
				return;
			}
			nxt = e;
		}
	}
};

const int maxn = 100000 + 10;
int n, m;
int p10[maxn];
int ip10[maxn];

typedef int T;
pair<T, T> euclid(T a, T b) {
	if (b == 0) return make_pair(1, 0);
	pair<T, T> r = euclid(b, a % b);
	return make_pair(r.second, r.first - a / b * r.second);
}
int inverse(int a, int m) {
	pi r = euclid(a, m);
	return (r.fi % m + m) % m;
}

struct CentroidTree {
	struct Info {
		int d, x, y;
		Info() : d(0), x(0), y(0) {}
		Info(int d, int x, int y) : d(d), x(x), y(y) {}
		Info(const Info& rhs) : d(rhs.d), x(rhs.x), y(rhs.y) {}
		Info operator + (const int& w) const {
			Info res(d + 1, x, y);
			res.x = mult(res.x, 10, m);
			addmod(res.x, w, m);
			addmod(res.y, mult(w, p10[d], m), m);
			return res;
		}
	};
	
	static const int maxn = 100000 + 10;
	static const int logn = 20;
	int n, rt;
	vector<pair<int, int> > adj[maxn];
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
	void add(int u, int v, int w) {
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	void dfs(int u, int p) {
		size[u] = 1;
		for (int i = 0; i < (int) adj[u].size(); i++) {
			int v = adj[u][i].first;
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
				int v = adj[u][i].first;
				if (v != p && !rem[v]) {
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
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			if (v != p && !rem[v]) {
				info[dep][v] = info[dep][u] + w;
				upd(v, dep, u);
			}
		}
	}
	int divide(int u, int dep) {
		lev[u = findcentroid(u)] = dep;
		p[0][u] = u;
		info[dep][u] = Info(0, 0, 0);
		upd(u, dep, -1);
		rem[u] = 1;
		for (int i = 0; i < (int) adj[u].size(); i++) {
			int v = adj[u][i].first;
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
	void build() {
		rt = divide(0, 0);
		for (int k = 1; k < logn; k++) {
			for (int u = 0; u < n; u++) {
				p[k][u] = p[k - 1][p[k - 1][u]];
			}
		}
	}
	HashTable<int, int> hs;
	long long ans;
	void add(int u, int ix) {
		hs[info[ix][u].y]++;
		for (int i = 0; i < (int) tree[u].size(); i++) {
			int v = tree[u][i];
			add(v, ix);
		}
	}
	void del(int u, int ix) {
		hs[info[ix][u].y]--;
		for (int i = 0; i < (int) tree[u].size(); i++) {
			int v = tree[u][i];
			del(v, ix);
		}
	}
	void query(int u, int ix) {
		int z = mult(info[ix][u].x, ip10[info[ix][u].d], m);
		z = (m - z) % m;
		ans += hs[z];
		ans += !info[ix][u].x;
		ans += !info[ix][u].y;
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
			del(v, ix);
			query(v, ix);
			add(v, ix);
		}
		for (int i = 0; i < (int) tree[u].size(); i++) {
			int v = tree[u][i];
			work(v);
		}
	}
} ct;

void solve() {
	cin >> n >> m;
	ct.init(n);
	FOR(i, 0, n - 1) {
		int u, v, w; cin >> u >> v >> w; w %= m;
		ct.add(u, v, w);
	}
	p10[0] = 1; FOR(i, 1, maxn) p10[i] = mult(p10[i - 1], 10, m);
	FOR(i, 0, maxn) ip10[i] = inverse(p10[i], m);
	ct.build();
	ct.work(ct.rt);
	cout << ct.ans << "\n";
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
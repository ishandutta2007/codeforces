#include <bits/stdc++.h>
using namespace std;

#ifdef _LOCAL_
	#define cout cerr
#endif
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

struct DSU {
	static const int maxn = 1000000 + 5;
	int flag;
	vector<int> dj;
	int size;
	int ptr1, ptr2;
	pair<int, int> his1[maxn];
	int his2[maxn];
	
	void init(int n) {
		flag = 0;
		dj.resize(n);
		for (int i = 0; i < n; i++) dj[i] = i;
		size = n;
		ptr1 = ptr2 = 0;
	}
	int find(int u) {
		if (dj[u] == u) return dj[u];
		int p = find(dj[u]);
		if (flag) {
			his1[ptr1++] = make_pair(u, dj[u]);
		}
		return dj[u] = p;
	}
	int join(int u, int v) {
		int p = find(u);
		int q = find(v);
		if (p != q) {
			if (flag) {
				his1[ptr1++] = make_pair(p, dj[p]);
				his2[ptr2++] = size;
			}
			size--;
			dj[p] = q;
			return 1;
		}
		return 0;
	}
	void rollback() {
		for (int i = ptr1 - 1; i >= 0; i--) {
			int u = his1[i].first;
			int p = his1[i].second;
			dj[u] = p;
		}
		for (int i = ptr2 - 1; i >= 0; i--) {
			size = his2[i];
		}
		ptr1 = ptr2 = 0;
	}
} dsu;

const int maxn = 100000 + 5;
const int magic = 800;
int n, k, m, q;
vi adj[maxn];
vector<pair<int, pi> > g[magic];
int ans[maxn];

int compare(pair<int, pi> a, pair<int, pi> b) {
	if (a.se.se != b.se.se) return a.se.se < b.se.se;
	return a < b;
}

void solve() {
	cin >> n >> k >> m;
	FOR(i, 0, m) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(v), adj[v].pb(u);
	}
	dsu.init(n);
	cin >> q;
	FOR(i, 0, q) {
		int l, r; cin >> l >> r; l--, r--;
		ans[i] -= n - (r - l + 1);
		if (r - l < magic) {
			dsu.flag = 1;
			FOR(u, l, r + 1) {
				FOR(j, 0, sz(adj[u])) {
					int v = adj[u][j];
					if (v >= l && v <= r) {
						dsu.join(u, v);
					}
				}
			}
			ans[i] += dsu.size;
			dsu.rollback();
		}
		else {
			int ix = (l + magic - 1) / magic;
			g[ix].pb(mp(i, mp(l, r)));
		}
	}
	FOR(i, 0, magic) if (sz(g[i])) {
		dsu.init(n);
		sort(all(g[i]), compare);
		int ptr = i * magic;
		FOR(j, 0, sz(g[i])) {
			int ix = g[i][j].fi;
			int l = g[i][j].se.fi;
			int r = g[i][j].se.se;
			while (ptr <= r) {
				FOR(k, 0, sz(adj[ptr])) {
					int v = adj[ptr][k];
					if (v >= i * magic && v < ptr) {
						dsu.join(ptr, v);
					}
				}
				ptr++;
			}
			dsu.flag = 1;
			FOR(u, l, i * magic) {
				FOR(k, 0, sz(adj[u])) {
					int v = adj[u][k];
					if (v > u && v <= r) {
						dsu.join(u, v);
					}
				}
			}
			ans[ix] += dsu.size;
			dsu.flag = 0;
			dsu.rollback();
		}
	}
	FOR(i, 0, q) cout << ans[i] << "\n";
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
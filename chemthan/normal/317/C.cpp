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

const int maxn = 300 + 5;
int n, V, m;
int a[maxn];
int b[maxn];
int need[maxn];

template<class T, T oo> struct MaximumFlow {
	static const int MAXV = 100000 + 5;
	static const int MAXE = 1000000 + 5;
	int n, s, t, E;
	int adj[MAXE], nxt[MAXE], lst[MAXV], run[MAXV], lev[MAXV], frm[MAXV], que[MAXV];
	T flw[MAXE], cap[MAXE];
	void init(int n, int s, int t) {
		this->n = n, this->s = s, this->t = t, E = 0;
		fill_n(lst, n + 1, -1);
	}
	void add(int u, int v, T c1, T c2) {
		adj[E] = v, flw[E] = 0, cap[E] = c1, nxt[E] = lst[u], lst[u] = E++;
		adj[E] = u, flw[E] = 0, cap[E] = c2, nxt[E] = lst[v], lst[v] = E++;
	}
	int bfs() {
		fill_n(lev, n + 1, -1);
		lev[s] = 0;
		int qsize = 0;
		que[qsize++] = s;
		for (int i = 0; i < qsize; i++) {
			for (int u = que[i], e = lst[u]; ~e; e = nxt[e]) {
				int v = adj[e];
				if (flw[e] < cap[e] && !~lev[v]) {
					lev[v] = lev[u] + 1;
					que[qsize++] = v;
				}
			}
		}
		return lev[t] != -1;
	}
	T dfs(int u, T bot) {
		if (u == t) return bot;
		for (int& e = run[u]; ~e; e = nxt[e]) {
			int v = adj[e];
			T delta = 0;
			if (lev[v] == lev[u] + 1 && flw[e] < cap[e] && (delta = dfs(v, min(bot, cap[e] - flw[e]))) > 0) {
				flw[e] += delta; flw[e ^ 1] -= delta;
				frm[v] = e;
				return delta;
			}
		}
		return 0;
	}
	vector<pair<pi, int> > res;
	T maxflow() {
		T total = 0;
		while (bfs()) {
			for (int i = 0; i <= n; i++) run[i] = lst[i];
			for (T delta = dfs(s, V); delta > 0; delta = dfs(s, V)) {
				total += delta;
				vi path;
				int cur = t;
				while (cur != s) {
					if (cur != t) {
						path.pb(cur);
					}
					int e = frm[cur];
					cur = adj[e ^ 1];
				}
				FOR(i, 0, sz(path) - 1) {
					int u = path[i];
					need[u] = delta;
				}
				while (1) {
					int found = 0;
					FOR(i, 0, sz(path) - 1) {
						int u = path[i];
						int v = path[i + 1];
						if (need[u]) {
							found = 1;
							int x = min(V - a[u], need[u]);
							if (a[v] >= x) {
								res.pb(mp(mp(v, u), x));
								need[u] -= x;
								a[u] += x;
								a[v] -= x;
							}
							else if (a[v]) {
								res.pb(mp(mp(v, u), a[v]));
								need[u] -= a[v];
								a[u] += a[v];
								a[v] = 0;
							}
						}
					}
					if (!found) break;
				}
			}
		}
		return total;
	}
};
MaximumFlow<long long, (long long) 1e18> mf;

void solve() {
	cin >> n >> V >> m;
	long long dif = 0, sum = 0;
	FOR(i, 0, n) cin >> a[i], dif += a[i], sum += a[i];
	FOR(i, 0, n) cin >> b[i], dif -= b[i];
	if (dif) {
		cout << "NO\n";
		return;
	}
	int tot = n, s = tot++, t = tot++;
	mf.init(tot, s, t);
	FOR(i, 0, m) {
		int u, v; cin >> u >> v; u--, v--;
		mf.add(u, v, LINF, 0);
		mf.add(v, u, LINF, 0);
	}
	FOR(i, 0, n) {
		mf.add(s, i, a[i], 0);
		mf.add(i, t, b[i], 0);
	}
	if (mf.maxflow() != sum) {
		cout << "NO\n";
		return;
	}
	cout << sz(mf.res) << "\n";
	FOR(i, 0, sz(mf.res)) {
		cout << mf.res[i].fi.fi + 1 << " " << mf.res[i].fi.se + 1 << " " << mf.res[i].se << "\n";
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
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

const int maxn = 100000 + 10;
int n, m;
vector<pair<int, long long> > adj[maxn];
vector<pair<int, long long> > adj2[maxn];
long long d[maxn];
int vis[maxn];
vi ver;

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

void dfs(int u) {
	vis[u] = 1;
	ver.pb(u);
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i].fi;
		long long w = adj[u][i].se;
		if (!vis[v]) {
			d[v] = d[u] ^ w;
			dfs(v);
		}
	}
}

int work(int u) {
	ver.clear();
	dfs(u);
	vector<long long> cycle;
	FOR(j, 0, sz(ver)) {
		int u = ver[j];
		FOR(i, 0, sz(adj2[u])) {
			int v = adj2[u][i].fi;
			long long w = adj2[u][i].se;
			if (u < v) {
				cycle.pb(d[u] ^ d[v] ^ w);
			}
		}
	}
	vi v1(63), v2(63);
	FOR(k, 0, 63) {
		int cnt[2] = {};
		FOR(i, 0, sz(ver)) {
			int u = ver[i];
			cnt[bit(d[u], k)]++;
		}
		v1[k] = mult(cnt[0], cnt[1]);
		v2[k] = (long long) cnt[0] * (cnt[0] - 1) / 2 % MOD;
		addmod(v2[k], (long long) cnt[1] * (cnt[1] - 1) / 2 % MOD);
	}
	vector<long long> g[63];
	FOR(i, 0, sz(cycle)) {
		if (cycle[i]) {
			g[__lg(cycle[i])].pb(cycle[i]);
		}
	}
	FORd(i, 63, 1) {
		if (sz(g[i]) > 1) {
			FOR(j, 1, sz(g[i])) {
				long long tmp = g[i][0] ^ g[i][j];
				if (tmp) {
					g[__lg(tmp)].pb(tmp);
				}
			}
		}
	}
	FORd(i, 63, 0) if (sz(g[i])) {
		long long tmp = g[i][0];
		FOR(j, 0, 64) {
			if (bit(tmp, j)) {
				int tot = v1[j];
				addmod(tot, v2[j]);
				v1[j] = v2[j] = tot;
			}
			else {
				v1[j] = mult(v1[j], 2);
				v2[j] = mult(v2[j], 2);
			}
		}
	}
	int res = 0;
	FOR(i, 0, 63) {
		addmod(res, mult((1LL << i) % MOD, v1[i]));
	}
	return res;
}

void solve() {
	cin >> n >> m;
	init();
	FOR(i, 0, m) {
		int u, v; long long w; cin >> u >> v >> w; u--, v--;
		if (join(u, v)) {
			adj[u].pb(mp(v, w)), adj[v].pb(mp(u, w));
		}
		else {
			adj2[u].pb(mp(v, w)), adj2[v].pb(mp(u, w));
		}
	}
	int ans = 0;
	FOR(i, 0, n) if (!vis[i]) {
		addmod(ans, work(i));
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
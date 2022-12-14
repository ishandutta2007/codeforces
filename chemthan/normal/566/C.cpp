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

const int maxn = 200010;
int n;
int w[maxn];
vii adj[maxn];
int del[maxn];
int size[maxn];
double sumdif[maxn];
double sumdst[maxn];
pair<double, int> ans = mp(1e100, -1);

void dfs(int u, int p) {
	size[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].fi;
		if (v != p && !del[v]) {
			dfs(v, u);
			size[u] += size[v];
		}
	}
}

int findcenter(int u) {
	int p = -1; dfs(u, -1);
	int cap = size[u] >> 1;
	while (1) {
		bool found = false;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].fi;
			if (v != p && !del[v] && size[v] > cap) {
				found = true;
				p = u; u = v;
				break;
			}
		}
		if (!found) return u;
	}
}

void dfs2(int u, int d = 0, int p = -1) {
	sumdst[u] = pow((double) d, 1.5) * w[u];
	sumdif[u] = pow((double) d, 0.5) * w[u];
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i].fi;
		int l = adj[u][i].se;
		if (v != p) {
			dfs2(v, d + l, u);
			sumdst[u] += sumdst[v];
			sumdif[u] += sumdif[v];
		}
	}
}

void tcd(int u) {
	u = findcenter(u);
	del[u] = 1;
	dfs2(u);
	chkmin(ans, mp(sumdst[u], u));
	pair<double, int> best = mp(-1e100, -1);
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].fi;
		if (!del[v]) {
			chkmax(best, mp(sumdif[v], v));
		}
	}
	if (~best.se) {
		tcd(best.se);
	}
}

void solve() {
	cin >> n;
	FOR(i, 0, n) cin >> w[i];
	FOR(i, 0, n - 1) {
		int u, v, l; cin >> u >> v >> l; u--; v--;
		adj[u].pb(mp(v, l)); adj[v].pb(mp(u, l));
	}
	tcd(0);
	cout << ans.se + 1 << " " << prec(9) << ans.fi << "\n";
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
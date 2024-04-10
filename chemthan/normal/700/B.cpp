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
int n, k;
int a[maxn];
vi adj[maxn];
int size[maxn];
int lev[maxn];

void dfs(int u, int p) {
	size[u] = a[u];
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != p) {
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
			int v = adj[u][i];
			if (v != p && size[v] > cap) {
				found = true;
				p = u; u = v;
				break;
			}
		}
		if (!found) return u;
	}
}

void dfs2(int u, int p = -1) {
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p) {
			lev[v] = lev[u] + 1;
			dfs2(v, u);
		}
	}
}

void solve() {
	cin >> n >> k;
	FOR(i, 0, k << 1) {
		int u; cin >> u; u--;
		a[u] = 1;
	}
	FOR(i, 0, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	int center = findcenter(0);
	dfs2(center);
	long long ans = 0;
	FOR(i, 0, n) {
		if (a[i]) {
			ans += lev[i];
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
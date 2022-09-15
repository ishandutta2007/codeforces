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

const int maxn = 50 + 10;
int n, m, k;
int a[maxn][maxn];
int vis[maxn][maxn];
vii g;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int inside(int u, int v) {
	if (!(u >= 0 && u < n)) return 0;
	if (!(v >= 0 && v < m)) return 0;
	return 1;
}

int dfs(int u, int v) {
	vis[u][v] = 1;
	g.pb(mp(u, v));
	FOR(i, 0, 4) {
		int nu = u + dx[i];
		int nv = v + dy[i];
		if (inside(nu, nv) && !vis[nu][nv] && a[nu][nv] == '.') {
			dfs(nu, nv);
		}
	}
}

void solve() {
	cin >> n >> m >> k;
	FOR(i, 0, n) {
		string s; cin >> s;
		FOR(j, 0, m) a[i][j] = s[j];
	}
	vector<pair<int, vii> > v;
	FOR(i, 0, n) FOR(j, 0, m) if (!vis[i][j] && a[i][j] == '.') {
		g.clear();
		dfs(i, j);
		int found = 0;
		FOR(k, 0, sz(g)) {
			int x = g[k].fi;
			int y = g[k].se;
			if (!x || x == n - 1 || !y || y == m - 1) {
				found = 1;
				break;
			}
		}
		if (!found) {
			v.pb(mp(sz(g), g));
		}
	}
	sort(all(v));
	reverse(all(v));
	int tot = 0;
	while (sz(v) > k) {
		vii g = v.back().se;
		FOR(i, 0, sz(g)) {
			int u = g[i].fi;
			int v = g[i].se;
			a[u][v] = '*';
			tot++;
		}
		v.pop_back();
	}
	cout << tot << "\n";
	FOR(i, 0, n) {
		FOR(j, 0, m) cout << char(a[i][j]);
		cout << "\n";
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
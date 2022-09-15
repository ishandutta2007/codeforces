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

const int maxn = 3010;
int n, m;
vi adj[maxn];
int d[maxn][maxn];
set<pi> st1[maxn];
set<pi> st2[maxn];
int f[maxn][maxn];
int g[maxn][maxn];

void filldst(int u) {
	fill_n(d[u], n, INF);
	d[u][u] = 0;
	queue<int> q; q.push(u);
	while (sz(q)) {
		int v = q.front();
		q.pop();
		if (u != v) {
			st1[u].insert(mp(d[u][v], v));
			st2[v].insert(mp(d[u][v], u));
			f[u][v] = g[v][u] = 1;
			if (sz(st1[u]) > 5) {
				int w = st1[u].begin()->se;
				f[u][w] = 0;
				st1[u].erase(st1[u].begin());
			}
			if (sz(st2[v]) > 5) {
				int w = st2[v].begin()->se;
				g[v][w] = 0;
				st2[v].erase(st2[v].begin());
			}
		}
		FOR(i, 0, sz(adj[v])) {
			int w = adj[v][i];
			if (d[u][w] == INF) {
				d[u][w] = d[u][v] + 1;
				q.push(w);
			}
		}
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, m) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		adj[u].pb(v);
	}
	FOR(i, 0, n) filldst(i);
	int dmax = 0; vi ans;
	FOR(i, 0, n) FOR(j, 0, n) if (i != j && d[i][j] < INF) {
		if (g[i][j]) st2[i].erase(mp(d[j][i], j));
		if (f[j][i]) st1[j].erase(mp(d[j][i], i));
		if (sz(st2[i])) {
			int u = st2[i].rbegin()->se;
			if (f[j][u]) st1[j].erase(mp(d[j][u], u));
			if (sz(st1[j])) {
				int v = st1[j].rbegin()->se;
				if (chkmax(dmax, d[u][i] + d[i][j] + d[j][v])) {
					ans.clear();
					ans.pb(u);
					ans.pb(i);
					ans.pb(j);
					ans.pb(v);
				}
			}
			if (f[j][u]) st1[j].insert(mp(d[j][u], u));
		}
		if (sz(st1[j])) {
			int v = st1[j].rbegin()->se;
			if (g[i][v]) st2[i].erase(mp(d[v][i], v));
			if (sz(st2[i])) {
				int u = st2[i].rbegin()->se;
				if (chkmax(dmax, d[u][i] + d[i][j] + d[j][v])) {
					ans.clear();
					ans.pb(u);
					ans.pb(i);
					ans.pb(j);
					ans.pb(v);
				}
			}
			if (g[i][v]) st2[i].insert(mp(d[v][i], v));
		}
		if (g[i][j]) st2[i].insert(mp(d[j][i], j));
		if (f[j][i]) st1[j].insert(mp(d[j][i], i));
	}
	FOR(i, 0, sz(ans)) printf("%d ", ans[i] + 1);
	puts("");
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
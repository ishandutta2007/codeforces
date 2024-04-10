#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcount(n)
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
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 100010;
int n, m;
vector<pair<pi, int> > edges;
vi adj[maxn];
int num[maxn];
int x, y, z;
vi vx, vy;
int f[maxn];

int dj[maxn];
int sz[maxn];
void init() {
	FOR(i, 0, n) dj[i] = i, sz[i] = 1;
}
int find(int u) {
	return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
void join(int u, int v) {
	int p = find(u);
	int q = find(v);
	if (p != q) {
		dj[p] = q;
		sz[q] += sz[p];
	}
}

void dfs(int u, int k) {
	num[u] = k;
	if (k == 1) {
		x += sz[u];
		vx.pb(u);
	}
	else {
		y += sz[u];
		vy.pb(u);
	}
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (!num[v]) {
			dfs(v, k == 1 ? 2 : 1);
		}
		else if (num[v] == k) {
			z = 1;
		}
	}
}

vi work(int c) {
	vi res;
	init();
	FOR(i, 0, n) adj[i].clear(), num[i] = f[i] = 0;
	FOR(i, 0, sz(edges)) {
		int u = edges[i].fi.fi;
		int v = edges[i].fi.se;
		int w = edges[i].se;
		if (c != w) {
			join(u, v);
		}
	}
	FOR(i, 0, sz(edges)) {
		int u = edges[i].fi.fi;
		int v = edges[i].fi.se;
		int w = edges[i].se;
		if (c == w) {
			int p = find(u);
			int q = find(v);
			if (p == q) {
				res.pb(-1);
				return res;
			}
			adj[p].pb(q);
			adj[q].pb(p);
		}
	}
	FOR(i, 0, n) if (!num[i] && dj[i] == i) {
		x = y = z = 0;
		vx.clear(); vy.clear();
		dfs(i, 1);
		if (z) {
			res.pb(-1);
			return res;
		}
		if (x < y) {
			FOR(j, 0, sz(vx)) {
				f[vx[j]] = 1;
			}
		}
		else {
			FOR(j, 0, sz(vy)) {
				f[vy[j]] = 1;
			}
		}
	}
	FOR(i, 0, n) {
		int p = find(i);
		if (f[p]) {
			res.pb(i);
		}
	}
	return res;
}

int isbad(vi r) {
	return sz(r) && r[0] == -1;
}

void solve() {
	cin>>n>>m;
	FOR(i, 0, m) {
		int u, v; string s;
		cin>>u>>v>>s; u--; v--;
		int c = s == "B";
		edges.pb(mp(mp(u, v), c));
	}
	vi r1 = work(0);
	vi r2 = work(1);
	if (isbad(r1) && isbad(r2)) {
		cout<<"-1\n";
		return;
	}
	vi res;
	if (isbad(r1)) res = r2;
	else if (isbad(r2)) res = r1;
	else if (sz(r1) < sz(r2)) res = r1;
	else res = r2;
	cout<<sz(res)<<"\n";
	FOR(i, 0, sz(res)) cout<<res[i] + 1<<" ";
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
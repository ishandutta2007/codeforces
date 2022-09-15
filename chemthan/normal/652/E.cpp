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

const int maxn = 300010;
int n, m, a, b;
vector<pair<pi, int> > edges;
vii adj[maxn];
int cnt;
int num[maxn];
int low[maxn];
int val[maxn];

int dj[maxn];
int hs[maxn];
void init() {
	FOR(i, 0, n) dj[i] = i;
}
int find(int u) {
	return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
void join(int u, int v) {
	dj[find(u)] = dj[find(v)];
}

void dfs(int u, int p = -1) {
	num[u] = low[u] = ++cnt;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i].fi;
		if (v != p) {
			if (num[v]) {
				chkmin(low[u], num[v]);
			}
			else {
				dfs(v, u);
				if (low[v] < num[v]) {
					join(u, v);
				}
				chkmin(low[u], low[v]);
			}
		}
	}	
}

void dfs2(int u, int k, int p = -1) {
	val[u] = k;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i].fi;
		int w = adj[u][i].se;
		if (v != p) {
			dfs2(v, k | w | hs[v], u);
		}
	}
}

void solve() {
	cin>>n>>m;
	FOR(i, 0, m) {
		int u, v, w; cin>>u>>v>>w; u--; v--;
		adj[u].pb(mp(v, w)); adj[v].pb(mp(u, w));
		edges.pb(mp(mp(u, v), w));
	}
	cin>>a>>b; a--; b--;
	init(); dfs(0);
	FOR(i, 0, n) adj[i].clear();
	FOR(i, 0, sz(edges)) {
		int u = edges[i].fi.fi;
		int v = edges[i].fi.se;
		int w = edges[i].se;
		int p = find(u);
		int q = find(v);
		if (p != q) {
			adj[p].pb(mp(q, w));
			adj[q].pb(mp(p, w));
		}
		else if (w) {
			hs[p] = 1;
		}
	}
	a = find(a); b = find(b);
	dfs2(a, hs[a]);
	val[b] ? cout<<"YES\n" : cout<<"NO\n";
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
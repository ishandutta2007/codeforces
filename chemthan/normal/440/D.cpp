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
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 410;
int n, k;
vii edges;
vi adj[maxn];
int from[maxn];
int f[maxn][maxn];
map<pi, int> r[maxn];
int chosen[maxn];

void dfs(int u, int p = -1) {
	from[u] = p;
	f[u][0] = 1; f[u][1] = 0;	
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p) {
			dfs(v, u);
			int g[maxn]; fill_n(g, n + 1, INF);
			FOR(j, 1, n + 1) FOR(l, 0, n + 1 - j) {
				if (chkmin(g[j + l], f[u][j] + f[v][l])) {
					r[j + l][mp(u, v)] = l;
				}
			}
			FOR(j, 1, n + 1) f[u][j] = g[j];
		}
	}
}

void trace(int u, int k) {
	chosen[u] = 1;
	FORd(i, sz(adj[u]), 0) {
		int v = adj[u][i];
		if (v != from[u]) {
			int l = r[k][mp(u, v)];
			if (l) {
				trace(v, l);
			}
			k -= l;
		}
	}
}

void solve() {
	cin>>n>>k;
	FOR(i, 0, n - 1) {
		int u, v; cin>>u>>v; u--; v--;
		edges.pb(mp(u, v));
		adj[u].pb(v); adj[v].pb(u);
	}
	FOR(i, 0, n) fill_n(f[i], n + 1, INF);
	dfs(0);
	int ans = f[0][k], imin = 0;
	FOR(i, 1, n) if (chkmin(ans, f[i][k] + 1)) imin = i;
	cout<<ans<<"\n";
	trace(imin, k);
	FOR(i, 0, sz(edges)) {
		int u = edges[i].fi;
		int v = edges[i].se;
		if (chosen[u] + chosen[v] == 1) {
			cout<<i + 1<<" ";
		}
	}
	cout<<"\n";
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
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

const int maxn = 300010;
const int maxe = 20;
int n, q;
vi adj[maxn];
int size[maxn];
int p[maxn][maxe];
int lev[maxn];
int tin[maxn];
int tou[maxn];
int tms;
int cen[maxn];
int pos[maxn];

void dfs(int u, int dad = -1) {
	tin[u] = tms++;
	FOR(i, 1, maxe) {
		p[u][i] = p[p[u][i - 1]][i - 1];
	}
	size[u] = 1;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != dad) {
			lev[v] = lev[u] + 1;
			p[v][0] = u;
			dfs(v, u);
			size[u] += size[v];
		}
	}
	tou[u] = tms++;
}

int isparent(int u, int v) {
	return tin[u] <= tin[v] && tou[u] >= tou[v];
}

void dfs2(int u, int dad = -1) {
	pi opt = mp(0, 0);
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != dad) {
			dfs2(v, u);
			chkmax(opt, mp(size[v], v));
		}
	}
	if (opt.fi == 0) {
		pos[u] = u;
		cen[u] = u;
	}
	else {
		int cur = pos[opt.se];
		FORd(i, maxe, 0) {
			if (!isparent(p[cur][i], u) && 2 * size[p[cur][i]] < size[u]) {
				cur = p[cur][i];
			}
		}
		pos[u] = cur;
		if (cur != u) {
			cen[u] = p[cur][0];
		}
		else {
			cen[u] = cur;
		}
	}
}

void solve() {
	cin>>n>>q;
	FOR(i, 0, n - 1) {
		int u; cin>>u; u--;
		adj[u].pb(i + 1);
	}
	dfs(0); dfs2(0);
	while (q--) {
		int u; cin>>u; u--;
		cout<<cen[u] + 1<<"\n";
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
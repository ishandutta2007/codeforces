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
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}

const int maxn = 500010;
int n;
vi adj[maxn];
int lev[maxn];
int sz[maxn];
int mcld[maxn];

void dfs(int u, int p = -1) {
	sz[u] = 1;
	int dmax = 0, imax = 0;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p) {
			lev[v] = lev[u] + 1;
			dfs(v, u);
			sz[u] += sz[v];
			if (dmax < sz[v]) {
				dmax = sz[v];
				imax = v;
			}
		}
	}
	mcld[u] = imax;
}

vi* dfs2(int u, int p) {
	vi* res;
	if (sz(adj[u]) == 1) {
		res = new vi;
		(*res).pb(lev[u]);
	}
	else {
		res = dfs2(mcld[u], u);
	}
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p && v != mcld[u]) {
			vi* t = dfs2(v, u);
			FOR(j, 0, sz(*t)) {
				(*res).pb((*t)[j]);
			}
		}
	}
	return res;
}

void solve() {
	cin>>n;
	FOR(i, 0, n - 1) {
		int u, v; cin>>u>>v; u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0);
	int ans = 0;
	FOR(i, 0, sz(adj[0])) {
		int u = adj[0][i];
		vi* r = dfs2(u, 0);
		map<int, int> cnt;
		FOR(j, 0, sz(*r)) {
			cnt[(*r)[j]]++;
		}
		FORall(it, cnt) {
			map<int, int>::iterator it2 = it; it2++;
			int u = it->fi, v = it->se;
			if (it2 != cnt.end()) {
				int x = it2->fi;
				if (u + v > x) {
					it2->se += u + v - x;
				}
			}
			else {
				ans = max(ans, u + v - 1);
			}
		}
	}
	cout<<ans;
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
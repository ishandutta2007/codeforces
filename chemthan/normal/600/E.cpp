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
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 100010;
int n;
int c[maxn];
vi adj[maxn];
int size[maxn];
int mcld[maxn];
ll ans[maxn];

void fdfs(int u, int p = -1) {
	size[u] = 1; mcld[u] = -1;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p) {
			fdfs(v, u); size[u] += size[v];
			if (!~mcld[u] || size[mcld[u]] < size[v]) {
				mcld[u] = v;
			}
		}
	}
}

pair<map<int, ll>*, map<int, ll>* > dfs(int u, int p = -1) {
	pair<map<int, ll>*, map<int, ll>* > res;
	int k = mcld[u];
	if (~k) res = dfs(k, u);
	else {
		res.fi = new map<int, ll>;
		res.se = new map<int, ll>;
	}
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p && v != k) {
			pair<map<int, ll>*, map<int, ll>* > t = dfs(v, u);
			FORall(it, *t.fi) {
				int x = it->fi;
				ll y = it->se;
				(*res.se)[(*res.fi)[x]] -= x;
				(*res.se)[(*res.fi)[x] + y] += x;
				(*res.fi)[x] += y;
			}
		}
	}
	int x = c[u], y = 1;
	(*res.se)[(*res.fi)[x]] -= x;
	(*res.se)[(*res.fi)[x] + y] += x;
	(*res.fi)[x] += y;
	ans[u] = res.se->rbegin()->se;
	return res;
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", c + i);
	FOR(i, 0, n - 1) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	fdfs(0); dfs(0);
	FOR(i, 0, n) printf("%I64d ", ans[i]);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
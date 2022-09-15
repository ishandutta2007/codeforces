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

const int maxn = 300010;
int n, m, q;
vi adj[maxn];
int lev[maxn];
int d[maxn];
int dmax, imax;

int p[maxn];
int find(int u) {
	return p[u] == u ? u : p[u] = find(p[u]);
}
void join(int i, int j) {
	int u = find(i);
	int v = find(j);
	if (u != v) p[v] = u;
}

int dfs(int u, int p = -1) {
	if (dmax < lev[u]) {
		dmax = lev[u];
		imax = u;
	}
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p) {
			lev[v] = lev[u] + 1;
			dfs(v, u);
		}
	}
}

int diameter(int u) {
	lev[u] = dmax = 0; imax = u; dfs(u);
	lev[imax] = dmax = 0; dfs(imax);
	return dmax;
}

void solve() {
	scanf("%d%d%d", &n, &m, &q);
	FOR(i, 0, n) p[i] = i;
	FOR(i, 0, m) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		adj[u].pb(v); adj[v].pb(u);
		join(u, v);
	}
	FOR(i, 0, n) if (p[i] == i) {
		d[i] = diameter(i);
	}
	while (q--) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int u; scanf("%d", &u); u--;
			int v = find(u);
			printf("%d\n", d[v]);
		}
		else {
			int u, v; scanf("%d%d", &u, &v); u--; v--;
			int x = find(u);
			int y = find(v);
			if (x != y) {
				int t = (d[x] + 1) / 2 + (d[y] + 1) / 2 + 1;
				p[y] = x;
				d[x] = max(t, max(d[x], d[y]));
			}
		}
	}
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
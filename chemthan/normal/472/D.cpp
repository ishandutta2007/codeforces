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

const int maxn = 2010;
const int maxe = 15;
int n;
int d[maxn][maxn];
vii adj[maxn];
ll dis[maxn];
int lev[maxn];
int p[maxn][maxe];
int tin[maxn];
int tou[maxn];
int tms;

void dfs(int u, int dad = -1) {
	tin[u] = tms++;
	FOR(i, 1, maxe) p[u][i] = p[p[u][i - 1]][i - 1];
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i].fi;
		if (v != dad) {
			dis[v] = dis[u] + adj[u][i].se;
			lev[v] = lev[u] + 1;
			p[v][0] = u;
			dfs(v, u);
		}
	}
	tou[u] = tms++;
}

int isparent(int u, int v) {
	return tin[u] <= tin[v] && tou[u] >= tou[v];
}

int lca(int u, int v) {
	if (lev[u] < lev[v]) swap(u, v);
	if (isparent(v, u)) return v;
	FORd(i, maxe, 0) if (lev[p[u][i]] >= lev[v]) u = p[u][i];
	FORd(i, maxe, 0) if (p[u][i] != p[v][i]) {u = p[u][i]; v = p[v][i];}
	return p[u][0];
}

int dj[maxn];
int find(int u) {
	return dj[u] == u ? u : dj[u] = find(dj[u]);
}
void join(int u, int v) {
	dj[find(u)] = find(v);
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) dj[i] = i;
	FOR(i, 0, n) FOR(j, 0, n) scanf("%d", &d[i][j]);
	vector<pair<int, pi> > v;
	FOR(i, 0, n) {
		if (d[i][i]) {
			printf("NO");
			return;
		}
		FOR(j, i + 1, n) {
			if (d[i][j] != d[j][i] || !d[i][j]) {
				printf("NO");
				return;
			}
			v.pb(mp(d[i][j], mp(i, j)));
		}
	}
	sort(all(v));
	int cnt = 0;
	FOR(i, 0, sz(v)) {
		int x = v[i].se.fi;
		int y = v[i].se.se;
		if (find(x) == find(y)) continue;
		join(x, y);
		int w = v[i].fi;
		adj[x].pb(mp(y, w));
		adj[y].pb(mp(x, w));
		if (++cnt == n - 1) break;
	}
	if (cnt < n - 1) {
		printf("NO");
		return;
	}
	dfs(0);
	FOR(i, 0, n) FOR(j, i + 1, n) {
		int u = lca(i, j);
		ll t = dis[i] + dis[j] - 2 * dis[u];
		if (t != d[i][j]) {
			printf("NO");
			return;
		}
	}
	printf("YES");
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
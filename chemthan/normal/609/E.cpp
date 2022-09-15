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
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

struct Edge {
	int a, b;
	ll w;
};
const int maxn = 200010;
int n, m;
vi adj[maxn];
map<pi, ll> dis;
Edge edges[maxn];

int dj[maxn];
void init() {
	FOR(i, 0, maxn) dj[i] = i;
}
int find(int u) {
	return dj[u] == u ? u : dj[u] = find(dj[u]);
}
int join(int u, int v) {
	int p = find(u);
	int q = find(v);
	dj[p] = q;
}

const int maxe = 25;
int lev[maxn];
int p[maxn][maxe];
ll d[maxn][maxe];

void dfs(int u, int dad = -1) {
	FOR(i, 1, maxe) {
		p[u][i] = p[p[u][i - 1]][i - 1];
		d[u][i] = max(d[u][i - 1], d[p[u][i - 1]][i - 1]);
	}
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != dad) {
			lev[v] = lev[u] + 1;
			p[v][0] = u; d[v][0] = dis[mp(u, v)];
			dfs(v, u);
		}
	}
}

ll maxpath(int u, int v) {
	ll res = 0;
	if (lev[u] < lev[v]) swap(u, v);
	FORd(i, maxe, 0) {
		if (lev[p[u][i]] >= lev[v]) {
			res = max(res, d[u][i]);
			u = p[u][i];
		}
	}
	if (u == v) return res;
	FORd(i, maxe, 0) {
		if (p[u][i] != p[v][i]) {
			res = max(res, d[u][i]);
			res = max(res, d[v][i]);
			u = p[u][i];
			v = p[v][i];
		}
	}
	res = max(res, d[u][0]);
	res = max(res, d[v][0]);
	return res;
}

void solve() {
	scanf("%d%d", &n, &m);
	priority_queue<pair<ll, pi> > pq;
	FOR(i, 0, m) {
		scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].w);
		edges[i].a--; edges[i].b--;
		pq.push(mp(-edges[i].w, mp(edges[i].a, edges[i].b)));
		dis[mp(edges[i].a, edges[i].b)] = dis[mp(edges[i].b, edges[i].a)] = edges[i].w;
	}
	init();
	ll tot = 0;
	while (sz(pq)) {
		int u = pq.top().se.fi;
		int v = pq.top().se.se;
		ll w = -pq.top().fi;
		pq.pop();
		if (find(u) != find(v)) {
			adj[u].pb(v);
			adj[v].pb(u);
			join(u, v);
			tot += w;
		}
	}
	dfs(0);
	FOR(i, 0, m) {
		printf("%I64d\n", tot + edges[i].w - maxpath(edges[i].a, edges[i].b));
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
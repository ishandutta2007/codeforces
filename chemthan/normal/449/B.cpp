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

const int maxn = 100010;
int n, m, k;
vii adj[maxn];
vii rou;
vector<pair<pi, int> > edges;
ll d[maxn];
int deg[maxn];

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	FOR(i, 0, m) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w); u--; v--;
		adj[u].pb(mp(v, w)); adj[v].pb(mp(u, w));
		edges.pb(mp(mp(u, v), w));
	}
	FOR(i, 0, k) {
		int u, w; scanf("%d%d", &u, &w); u--;
		adj[0].pb(mp(u, w)); rou.pb(mp(u, w));
		edges.pb(mp(mp(0, u), w));
	}
	FOR(i, 1, n) d[i] = LINF;
	priority_queue<pair<ll, int> > pq; pq.push(mp(-d[0], 0));
	while (sz(pq)) {
		int u = pq.top().se;
		ll w = -pq.top().fi;
		pq.pop();
		if (d[u] != w) continue;
		FOR(i, 0, sz(adj[u])) {
			int v = adj[u][i].fi;
			int w = adj[u][i].se;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pq.push(mp(-d[v], v));
			}
		}
	}
	FOR(i, 0, sz(edges)) {
		int u = edges[i].fi.fi;
		int v = edges[i].fi.se;
		int w = edges[i].se;
		if (d[u] == d[v] + w) deg[u]++;
		if (d[v] == d[u] + w) deg[v]++;
	}
	int ans = 0;
	FOR(i, 0, k) {
		int u = rou[i].fi;
		int w = rou[i].se;
		if (w > d[u]) ans++;
		else {
			if (deg[u] > 1) {
				ans++;
				deg[u]--;
			}
		}
	}
	printf("%d", ans);
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
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
int n, m;
vi adj[maxn];
int deg[maxn];
vector<pair<int, pi> > query;
pi doc[maxn];
int tin[maxn];
int tou[maxn];
int tms;

int dj[maxn];
void init() {
	FOR(i, 0, maxn) dj[i] = i;
}
int find(int u) {
	return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
void join(int u, int v) {
	dj[find(u)] = find(v);
}

void dfs(int u) {
	tin[u] = tms++;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		dfs(v);
	}
	tou[u] = tms++;
}

int isparent(int u, int v) {
	return tin[u] <= tin[v] && tou[u] >= tou[v];
}

void solve() {
	scanf("%d%d", &n, &m);
	int cnt = 0;
	FOR(i, 0, m) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int u, v; scanf("%d%d", &u, &v); u--; v--;
			adj[v].pb(u); query.pb(mp(op, mp(u, v)));
			deg[u]++;
		}
		else if (op == 2) {
			int u; scanf("%d", &u); u--;
			query.pb(mp(op, mp(u, cnt++)));
		}
		else {
			int u, id; scanf("%d%d", &u, &id); u--; id--;
			query.pb(mp(op, mp(u, id)));
		}
	}
	FOR(i, 0, n) {
		if (!deg[i]) {
			adj[n].pb(i);
		}
	}
	dfs(n); init();
	FOR(i, 0, m) {
		int op = query[i].fi;
		if (op == 1) {
			int u = query[i].se.fi;
			int v = query[i].se.se;
			join(u, v);
		}
		else if (op == 2) {
			int u = query[i].se.fi;
			int id = query[i].se.se;
			doc[id] = mp(u, find(u));
		}
		else {
			int u = query[i].se.fi;
			int id = query[i].se.se;
			int x = doc[id].fi;
			int y = doc[id].se;
			if (isparent(u, x) && isparent(y, u)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
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
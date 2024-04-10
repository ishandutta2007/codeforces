#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
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
const ld PI = 2 * acos(0);

const int maxn = 100010;
int n;
vi adj[maxn];
int a[maxn];
ll f[maxn][2];

ll exp(ll n, ll k) {
	if (!k) return 1;
	if (k & 1) return n * exp(n, k - 1) % MOD;
	ll t = exp(n, k >> 1);
	return t * t % MOD;
}

void dfs(int u, int p = -1) {
	vector<ll> g, h;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p) {
			dfs(v, u);
			g.pb(f[v][0]);
			h.pb(f[v][1]);
		}
	}
	ll tot = 1;
	FOR(i, 0, sz(g)) tot = tot * (g[i] + h[i]) % MOD;
	if (a[u]) {
		f[u][0] = 0;
		f[u][1] = tot;
	}
	else {
		f[u][0] = tot;
		FOR(i, 0, sz(g))
			f[u][1] = (f[u][1] + tot * exp(g[i] + h[i], MOD - 2) % MOD * h[i]) % MOD;
	}
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n - 1) {
		int u; scanf("%d", &u);
		adj[u].pb(i + 1);
		adj[i + 1].pb(u);
	}
	FOR(i, 0, n) scanf("%d", a + i);
	dfs(0);
	printf("%I64d", f[0][1]);
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
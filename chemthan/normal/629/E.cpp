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
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
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
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
void setmin(ll& a, ll val) {if (a > val) a = val;}
void setmax(ll& a, ll val) {if (a < val) a = val;}

const int maxn = 100010;
const int maxe = 20;
int n, m;
vi adj[maxn];
int a[maxn];
int b[maxn];
int p[maxn][maxe];
ll val[maxn][maxe];
int lev[maxn];
int tin[maxn];
int tou[maxn];
int tms;
ll sum[2][maxn];

void dfs(int u, int dad = -1) {
	tin[u] = tms++;
	FOR(i, 1, maxe) p[u][i] = p[p[u][i - 1]][i - 1];
	sum[0][u] = lev[u];
	sum[1][u] = 1;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != dad) {
			lev[v] = lev[u] + 1;
			p[v][0] = u;
			dfs(v, u);
			sum[0][u] += sum[0][v];
			sum[1][u] += sum[1][v];
		}
	}
	tou[u] = tms++;
}

void dfs2(int u, int dad = -1) {
	if (u) {
		val[u][0] = sum[1][p[u][0]];
	}
	FOR(i, 1, maxe) {
		val[u][i] = val[u][i - 1] + val[p[u][i - 1]][i - 1];
	}
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != dad) {
			dfs2(v, u);
		}
	}
}

int isparent(int u, int v) {
	return tin[u] <= tin[v] && tou[u] >= tou[v];
}

int lca(int u, int v) {
	if (lev[u] < lev[v]) swap(u, v);
	if (isparent(v, u)) return v;
	FORd(i, maxe, 0) {
		if (lev[p[u][i]] >= lev[v]) {
			u = p[u][i];
		}
	}
	FORd(i, maxe, 0) {
		if (p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	}
	return p[u][0];
}

int get(int u, int v) {
	FORd(i, maxe, 0) {
		if (lev[p[u][i]] > lev[v]) {
			u = p[u][i];
		}
	}
	return u;
}

ll calc(int a, int b) {
	if (a == b) return 0;
	ll res = 0;
	FORd(i, maxe, 0) {
		if (lev[p[a][i]] > lev[b]) {
			res += val[a][i];
			a = p[a][i];
		}
	}
	return res + val[a][0];
}

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, n - 1) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0); dfs2(0);
	FOR(i, 0, m) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		if (lev[a] > lev[b]) swap(a, b);
		if (!isparent(a, b)) {
			int c = lca(a, b);
			ll res = (sum[0][a] - sum[1][a] * lev[c]) * sum[1][b] + sum[1][a] * (sum[0][b] - sum[1][b] * lev[c]);
			printf("%0.9lf\n", (ld) res / sum[1][a] / sum[1][b] + 1);
		}
		else {
			int d = get(b, a);
			ll sum0a = sum[0][a] - sum[0][d];
			ll sum1a = sum[1][a] - sum[1][d];
			sum0a -= sum1a * lev[a];
			ll sum0b = sum[0][b] - sum[1][b] * lev[a];
			ll res = sum0a * sum[1][b] + sum1a * sum0b;
			ll tot = sum1a * sum[1][b];
			if (a) {
				sum0a = sum[0][0] - sum[0][a];
				sum1a = sum[1][0] - sum[1][a];
				sum0a += sum1a * lev[a];
				int e = get(a, 0);
				sum0a -= 2 * (calc(a, e) - (lev[a] - 1) * sum[1][a]);
				res += sum0a * sum[1][b] + sum1a * sum0b;
				tot += sum1a * sum[1][b];
			}
			printf("%0.9lf\n", (ld) res / tot + 1);
		}
	}
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
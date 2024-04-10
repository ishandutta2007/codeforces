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
int n, m;
vi adj[maxn];
int c[maxn];
vi add[maxn];
vi del[maxn];
int tin[maxn];
int tou[maxn];
int eve[maxn];
int tms;
ll f[maxn];

ll st[maxn << 3];
ll lz[maxn << 3];
void updatelz(int node, int L, int R) {
	if (lz[node]) {
		st[node] += lz[node];
		chkmin(st[node], LINF);
		if (L < R) {
			lz[node << 1] += lz[node];
			lz[(node << 1) + 1] += lz[node];
		}
		lz[node] = 0;
	}
}
void update(int node, int i, int L, int R, ll val) {
	updatelz(node, L, R);
	if (i < L || i > R) return;
	if (L == R) {
		st[node] = val;
		return;
	}
	update(node << 1, i, L, L + R >> 1, val);
	update((node << 1) + 1, i, (L + R >> 1) + 1, R, val);
	st[node] = min(st[node << 1], st[(node << 1) + 1]);
}
void update(int node, int l, int r, int L, int R, ll val) {
	updatelz(node, L, R);
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		lz[node] += val;
		updatelz(node, L, R);
		return;
	}
	update(node << 1, l, r, L, L + R >> 1, val);
	update((node << 1) + 1, l, r, (L + R >> 1) + 1, R, val);
	st[node] = min(st[node << 1], st[(node << 1) + 1]);
}
ll query(int node, int l, int r, int L, int R) {
	updatelz(node, L, R);
	if (l > R || r < L) return LINF;
	if (l <= L && r >= R) return st[node];
	return min(query(node << 1, l, r, L, L + R >> 1), query((node << 1) + 1, l, r, (L + R >> 1) + 1, R));
}

void dfs(int u, int p = -1) {
	tin[u] = ++tms;
	FOR(i, 0, sz(add[u])) {
		int k = add[u][i];
		eve[k] = ++tms;
	}
	ll tot = 0;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p) {
			dfs(v, u);
			tot += f[v];
		}
	}
	tou[u] = tms;
	FOR(i, 0, sz(add[u])) {
		int k = add[u][i];
		update(1, eve[k], 0, 2 * maxn - 1, tot + c[k]);
	}
	if (u) {
		FOR(i, 0, sz(del[u])) {
			int k = del[u][i];
			update(1, eve[k], 0, 2 * maxn - 1, LINF);
		}
	}
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p) {
			update(1, tin[v], tou[v], 0, 2 * maxn - 1, tot - f[v]);
		}
	}
	f[u] = query(1, tin[u], tou[u], 0, 2 * maxn - 1);
	if (f[u] >= LINF) {
		puts("-1");
		exit(0);
	}
}

void solve() {
	FOR(i, 0, maxn << 3) st[i] = LINF;
	scanf("%d%d", &n, &m);
	FOR(i, 0, n - 1) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	FOR(i, 0, m) {
		int u, v; scanf("%d%d%d", &u, &v, c + i); u--; v--;
		add[u].pb(i);
		del[v].pb(i);
	}
	if (n == 1) {
		puts("0");
	}
	else {
		dfs(0);
		printf("%I64d\n", f[0]);
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
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
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 500000 + 10;
int n;
vector<int> adj[maxn];
int size[maxn];
int lev[maxn];
int p[maxn];
int num[maxn];
int tou[maxn];
int head[maxn];
int cnt;

int st[maxn << 2];
int lz[maxn << 2];
void pushdown(int p, int L, int R) {
	if (lz[p] != -1) {
		st[p] = lz[p];
		if (L < R) {
			lz[p << 1] = lz[p];
			lz[p << 1 | 1] = lz[p];
		}
		lz[p] = -1;
	}
}
void upd(int p, int l, int r, int L, int R, int val) {
	pushdown(p, L, R);
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		lz[p] = val;
		pushdown(p, L, R);
		return;
	}
	upd(p << 1, l, r, L, L + R >> 1, val);
	upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
}
int query(int p, int i, int L, int R) {
	pushdown(p, L, R);
	if (i < L || i > R) return -1;
	if (L == R) return st[p];
	return max(query(p << 1, i, L, L + R >> 1), query(p << 1 | 1, i, (L + R >> 1) + 1, R));
}

void dfs1(int u, int dad = -1) {
	size[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != dad) {
			p[v] = u, lev[v] = lev[u] + 1;
			dfs1(v, u);
			size[u] += size[v];
		}
	}
}
void dfs2(int u, int h = 0, int dad = -1) {
	num[u] = cnt++, head[u] = h;
	pair<int, int> best = make_pair(-1, -1);
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != dad) {
			best = max(best, make_pair(size[v], v));
		}
	}
	if (~best.second) {
		dfs2(best.second, h, u);
	}
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != dad && v != best.second) {
			dfs2(v, v, u);
		}
	}
	tou[u] = cnt - 1;
}
void upd(int u, int v, int val) {
	int hu = head[u], hv = head[v];
	while (hu != hv) {
		if (lev[hu] < lev[hv]) swap(u, v), swap(hu, hv);
		upd(1, num[hu], num[u], 0, n - 1, val);
		u = p[hu], hu = head[u];
	}
	if (lev[u] > lev[v]) swap(u, v);
	upd(1, num[u], num[v], 0, n - 1, val);
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n - 1) {
		int u, v; scanf("%d%d", &u, &v); u--, v--;
		adj[u].pb(v), adj[v].pb(u);
	}
	fill_n(lz, maxn << 2, -1);
	dfs1(0), dfs2(0);
	int q; scanf("%d", &q);
	while (q--) {
		int op, u; scanf("%d%d", &op, &u); u--;
		if (op == 1) {
			upd(1, num[u], tou[u], 0, n - 1, 1);
		}
		else if (op == 2) {
			upd(0, u, 0);
		}
		else {
			printf("%d\n", query(1, num[u], 0, n - 1));
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
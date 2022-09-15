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
int n, q;
vi adj[maxn];
int lev[maxn];
int tin[maxn];
int tou[maxn];
int tms;

void dfs(int u) {
	tin[u] = tms++;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		lev[v] = lev[u] + 1;
		dfs(v);
	}
	tou[u] = tms - 1;
}

struct SegTree {
	static const int MAXN = 300010;
	int st[4 * MAXN];
	int lz[4 * MAXN];
	void updatelz(int node, int L, int R) {
		if (lz[node]) {
			addmod(st[node], mult(R - L + 1, lz[node]));
			if (L < R) {
				addmod(lz[node << 1], lz[node]);
				addmod(lz[node << 1 | 1], lz[node]);
			}
			lz[node] = 0;
		}
	}
	void update(int node, int l, int r, int L, int R, int x) {
		updatelz(node, L, R);
		if (l > R || r < L) return;
		if (l <= L && r >= R) {
			lz[node] = x;
			updatelz(node, L, R);
			return;
		}
		update(node << 1, l, r, L, (L + R) >> 1, x);
		update(node << 1 | 1, l, r, ((L + R) >> 1) + 1, R, x);
		st[node] = st[node << 1];
		addmod(st[node], st[(node << 1) + 1]);
	}
	int query(int node, int l, int r, int L, int R) {
		updatelz(node, L, R);
		if (l > R || r < L) return 0;
		if (l <= L && r >= R) return st[node];
		int res = query(node << 1, l, r, L, (L + R) >> 1);
		addmod(res, query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R));
		return res;
	}
} seg[2];

void solve() {
	cin >> n;
	FOR(i, 1, n) {
		int u; cin >> u; u--;
		adj[u].pb(i);
	}
	dfs(0);
	cin >> q;
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int u, x, k; cin >> u >> x >> k; u--;
			int tmp = x;
			addmod(tmp, mult(lev[u], k));
			seg[0].update(1, tin[u], tou[u], 0, n - 1, tmp);
			seg[1].update(1, tin[u], tou[u], 0, n - 1, k);
		}
		else if (op == 2) {
			int u; cin >> u; u--;
			int r1 = seg[0].query(1, tin[u], tin[u], 0, n - 1);
			int r2 = seg[1].query(1, tin[u], tin[u], 0, n - 1);
			int ans = r1;
			submod(ans, mult(lev[u], r2));
			cout << ans << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
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

const int maxn = 200010;
int n, d, q;
vi adj[maxn];
int dad[maxn];
vector<pair<int, pi> > query;
int deg[maxn];
int tin[maxn];
int tou[maxn];
int tms;

struct SegmentTree {
	int st[8 * maxn];
	int lz[8 * maxn];
	SegmentTree() {
		FOR(i, 0, 8 * maxn) lz[i] = 1;
	}
	void update1(int node, int i, int L, int R, int val) {
		if (lz[node] != 1) {
			st[node] = 1LL * st[node] * lz[node] % MOD;
			if (L < R) {
				lz[node << 1] = 1LL * lz[node << 1] * lz[node] % MOD;
				lz[(node << 1) + 1] = 1LL * lz[(node << 1) + 1] * lz[node] % MOD;
			}
			lz[node] = 1;
		}
		if (i < L || i > R) return;
		if (L == R) {st[node] = val; return;}
		update1(node << 1, i, L, (L + R) >> 1, val);
		update1((node << 1) + 1, i, ((L + R) >> 1) + 1, R, val);
		st[node] = (st[node << 1] + st[(node << 1) + 1]) % MOD;
	}
	void update2(int node, int l, int r, int L, int R, int val) {
		if (lz[node] != 1) {
			st[node] = 1LL * st[node] * lz[node] % MOD;
			if (L < R) {
				lz[node << 1] = 1LL * lz[node << 1] * lz[node] % MOD;
				lz[(node << 1) + 1] = 1LL * lz[(node << 1) + 1] * lz[node] % MOD;
			}
			lz[node] = 1;
		}
		if (l > R || r < L) return;
		if (l <= L && r >= R) {
			st[node] = 1LL * st[node] * val % MOD;
			if (L < R) {
				lz[node << 1] = 1LL * lz[node << 1] * val % MOD;
				lz[(node << 1) + 1] = 1LL * lz[(node << 1) + 1] * val % MOD;
			}
			return;
		}
		update2(node << 1, l, r, L, (L + R) >> 1, val);
		update2((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R, val);
		st[node] = (st[node << 1] + st[(node << 1) + 1]) % MOD;
	}
	int query(int node, int l, int r, int L, int R) {
		if (lz[node] != 1) {
			st[node] = 1LL * st[node] * lz[node] % MOD;
			if (L < R) {
				lz[node << 1] = 1LL * lz[node << 1] * lz[node] % MOD;
				lz[(node << 1) + 1] = 1LL * lz[(node << 1) + 1] * lz[node] % MOD;
			}
			lz[node] = 1;
		}
		if (l > R || r < L) return 0;
		if (l <= L && r >= R) return st[node];
		return (query(node << 1, l, r, L, (L + R) >> 1) + query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R)) % MOD;
	}
} smt[2];

int dfs(int u) {
	tin[u] = tms++;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		dfs(v);
	}
	tou[u] = tms++;
}

void solve() {
	n = 1;
	scanf("%d%d", &d, &q);
	FOR(i, 0, q) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int p, v; scanf("%d%d", &p, &v); p--;
			query.pb(mp(op, mp(p, v)));
			dad[n] = p;
			adj[p].pb(n++);
		}
		else {
			int u; scanf("%d", &u); u--;
			query.pb(mp(op, mp(u, 0)));
		}
	}
	dfs(0);
	FOR(i, 0, n) smt[0].update1(1, tin[i], 0, (maxn << 1) - 1, 1);
	smt[1].update1(1, tin[0], 0, (maxn << 1) - 1, d);
	n = 1;
	FOR(i, 0, q) {
		if (query[i].fi == 1) {
			int p = query[i].se.fi;
			int v = query[i].se.se;
			deg[p]++;
			int k = 1LL * (deg[p] + 1) * fpow(deg[p], MOD - 2) % MOD;
			int l = smt[0].query(1, tin[n], tin[n], 0, (maxn << 1) - 1);
			smt[0].update2(1, tin[p], tou[p], 0, (maxn << 1) - 1, k);
			smt[1].update1(1, tin[n], 0, (maxn << 1) - 1, 1LL * l * v % MOD);
			smt[1].update2(1, tin[p], tou[p], 0, (maxn << 1) - 1, k);
			n++;
		}
		else {
			int u = query[i].se.fi;
			int r1 = smt[1].query(1, tin[u], tou[u], 0, (maxn << 1) - 1);
			int r2 = 1;
			if (u) {
				int v = dad[u];
				r2 = smt[0].query(1, tin[v], tin[v], 0, (maxn << 1) - 1);
			}
			printf("%d\n", 1LL * r1 * fpow(r2, MOD - 2) % MOD);
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
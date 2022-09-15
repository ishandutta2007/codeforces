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
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cout << #x << " = " << (x) << "\n";

struct Node {
	long long mn;
	int ix;
	long long lz;
	Node() {
		mn = LINF;
		ix = -1;
		lz = LINF;
	}
	Node(const Node& rhs) : mn(rhs.mn), ix(rhs.ix), lz(rhs.lz) {}
};
Node merge(Node x, Node y) {
	Node res;
	if (x.ix == -1) {
		res.mn = y.mn;
		res.ix = y.ix;
		res.lz = LINF;
	}
	else if (y.ix == -1) {
		res.mn = x.mn;
		res.ix = x.ix;
		res.lz = LINF;
	}
	else if (x.mn < y.mn) {
		res.mn = x.mn;
		res.ix = x.ix;
		res.lz = LINF;
	}
	else {
		res.mn = y.mn;
		res.ix = y.ix;
		res.lz = LINF;
	}
	return res;
}

const int maxn = 1e5 + 5;
int n, q, s;
vector<pair<pi, int> > adj[maxn];
int l[maxn];
int r[maxn];
int t[maxn];
int w[maxn];
long long d[maxn];

Node st[maxn << 2];
void build(int p, int L, int R) {
	if (L == R) {
		st[p].ix = L;
		return;
	}
	build(p << 1, L, L + R >> 1);
	build(p << 1 | 1, (L + R >> 1) + 1, R);
	st[p] = merge(st[p << 1], st[p << 1 | 1]);
}
void pushdown(int p, int L, int R) {
	if (st[p].lz < LINF) {
		if (st[p].ix != -1) {
			chkmin(st[p].mn, st[p].lz);
		}
		if (L < R) {
			chkmin(st[p << 1].lz, st[p].lz);
			chkmin(st[p << 1 | 1].lz, st[p].lz);
		}
		st[p].lz = LINF;
	}
}
void upd(int p, int l, int r, int L, int R, long long val) {
	pushdown(p, L, R);
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		chkmin(st[p].lz, val);
		pushdown(p, L, R);
		return;
	}
	upd(p << 1, l, r, L, L + R >> 1, val);
	upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
	st[p] = merge(st[p << 1], st[p << 1 | 1]);
}
void rem(int p, int i, int L, int R) {
	pushdown(p, L, R);
	if (i < L || i > R) return;
	if (L == R) {
		st[p].mn = LINF;
		st[p].ix = -1;
		return;
	}
	rem(p << 1, i, L, L + R >> 1);
	rem(p << 1 | 1, i, (L + R >> 1) + 1, R);
	st[p] = merge(st[p << 1], st[p << 1 | 1]);
}
Node query(int p, int l, int r, int L, int R) {
	pushdown(p, L, R);
	if (l > R || r < L) return Node();
	if (l <= L && r >= R) return st[p];
	return merge(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
}

set<int> st2[maxn << 2];
void add2(int p, int l, int r, int L, int R, int val) {
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		st2[p].insert(val);
		return;
	}
	if (L < R) {
		add2(p << 1, l, r, L, L + R >> 1, val);
		add2(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
	}
}
void rem2(int p, int l, int r, int L, int R, int val) {
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		st2[p].erase(val);
		return;
	}
	if (L < R) {
		rem2(p << 1, l, r, L, L + R >> 1, val);
		rem2(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
	}
}
int query2(int p, int i, int L, int R) {
	if (i < L || i > R) return -1;
	int res = sz(st2[p]) ? *st2[p].begin() : -1;
	if (L < R) chkmax(res, max(query2(p << 1, i, L, L + R >> 1), query2(p << 1 | 1, i, (L + R >> 1) + 1, R)));
	return res;
}

void solve() {
	cin >> n >> q >> s; s--;
	FOR(i, 0, q) {
		int tp; cin >> tp;
		if (tp == 1) {
			int u, v, w; cin >> u >> v >> w; u--, v--;
			adj[u].pb(mp(mp(v, v), w));
		}
		else if (tp == 2) {
			int u, l, r, w; cin >> u >> l >> r >> w; u--, l--, r--;
			adj[u].pb(mp(mp(l, r), w));
		}
		else if (tp == 3) {
			cin >> t[i] >> l[i] >> r[i] >> w[i]; t[i]--, l[i]--, r[i]--;
			add2(1, l[i], r[i], 0, n - 1, i);
		}
	}
	fill_n(d, n, -1);
	build(1, 0, n - 1);
	upd(1, s, s, 0, n - 1, 0);
	FOR(i, 0, n) {
		if (st[1].mn == LINF) break;
		int u = st[1].ix;
		d[u] = st[1].mn;
		rem(1, u, 0, n - 1);
		FOR(i, 0, sz(adj[u])) {
			int l = adj[u][i].fi.fi;
			int r = adj[u][i].fi.se;
			int w = adj[u][i].se;
			upd(1, l, r, 0, n - 1, d[u] + w);
		}
		while (1) {
			int ix = query2(1, u, 0, n - 1);
			if (ix == -1) break;
			rem2(1, l[ix], r[ix], 0, n - 1, ix);
			upd(1, t[ix], t[ix], 0, n - 1, d[u] + w[ix]);
		}
	}
	FOR(i, 0, n) cout << d[i] << " \n"[i == n - 1];
}

int main() {
	ios_base::sync_with_stdio(0); //cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
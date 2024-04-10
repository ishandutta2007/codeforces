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

struct matrix {
	static const int MAXN = 2;
	static const int MOD = (int) 1e9 + 7;
	int x[MAXN][MAXN];
	
	matrix() {
		memset(x, 0, sizeof(x));
	}
	int iszero() {
		FOR(i, 0, MAXN) FOR(j, 0, MAXN) if (x[i][j]) return 0;
		return 1;
	}
	matrix unit() {
		matrix res;
		for (int i = 0; i < MAXN; i++) res.x[i][i] = 1;
		return res;
	}
	matrix operator + (matrix A) {
		matrix res;
		for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
			res.x[i][j] = (x[i][j] + A.x[i][j]) % MOD;
		}
		return res;
	}
	matrix operator * (matrix A) {
		matrix res;
		for (int i = 0; i < MAXN; i++) for (int k = 0; k < MAXN; k++) for (int j = 0; j < MAXN; j++) {
			res.x[i][j] = (res.x[i][j] + (long long) x[i][k] * A.x[k][j]) % MOD;
		}
		return res;
	}
	matrix operator ^ (long long k) {
		if (!k) return unit();
		matrix res, tmp;
		for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
			res.x[i][j] = tmp.x[i][j] = x[i][j];
		}
		k--;
		while (k) {
			if (k & 1) res = res * tmp;
			tmp = tmp * tmp;
			k >>= 1;
		}
		return res;
	}
} nil;

const int maxn = 100000 + 10;
int n, q;
int a[maxn];
matrix fib;

matrix st[maxn << 2];
matrix lz[maxn << 2];
void build(int p, int L, int R) {
	if (L == R) {
		st[p] = fib ^ a[L];
		return;
	}
	build(p << 1, L, L + R >> 1);
	build(p << 1 | 1, (L + R >> 1) + 1, R);
	st[p] = st[p << 1] + st[p << 1 | 1];
}
void updlz(int p, int L, int R) {
	if (!lz[p].iszero()) {
		st[p] = st[p] * lz[p];
		if (L < R) {
			if (lz[p << 1].iszero()) lz[p << 1] = lz[p << 1].unit();
			if (lz[p << 1 | 1].iszero()) lz[p << 1 | 1] = lz[p << 1 | 1].unit();
			lz[p << 1] = lz[p << 1] * lz[p];
			lz[p << 1 | 1] = lz[p << 1 | 1] * lz[p];
		}
		ms(lz[p].x, 0);
	}
}
void upd(int p, int l, int r, int L, int R, matrix val) {
	updlz(p, L, R);
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		if (lz[p].iszero()) lz[p] = lz[p].unit();
		lz[p] = lz[p] * val;
		updlz(p, L, R);
		return;
	}
	upd(p << 1, l, r, L, L + R >> 1, val);
	upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
	st[p] = st[p << 1] + st[p << 1 | 1];
}
matrix query(int p, int l, int r, int L, int R) {
	updlz(p, L, R);
	if (l > R || r < L) return nil;
	if (l <= L && r >= R) return st[p];
	return query(p << 1, l, r, L, L + R >> 1) + query(p << 1 | 1, l, r, (L + R >> 1) + 1, R);
}

void solve() {
	fib.x[0][0] = fib.x[0][1] = fib.x[1][0] = 1;
	cin >> n >> q;
	FOR(i, 0, n) cin >> a[i];
	build(1, 0, n - 1);
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int l, r, x; cin >> l >> r >> x; l--, r--;
			upd(1, l, r, 0, n - 1, fib ^ x);
		}
		else if (op == 2) {
			int l, r; cin >> l >> r; l--, r--;
			matrix res = query(1, l, r, 0, n - 1);
			cout << res.x[1][0] << "\n";
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
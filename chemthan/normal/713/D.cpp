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

const int MAXN = 1000 + 1;
const int MAXM = 1000 + 1;
const int LOGN = 10;
const int LOGM = 10;
int n, m;
int a[MAXN][MAXM];
int f[LOGM][MAXN][MAXM];
int g[LOGM][LOGN][MAXM][MAXN];

void build() {
	for (int k = 1; k <= n; k++) {
		for (int j = 1; 1 << j <= m; j++) {
			for (int i = 0; i + (1 << j) - 1 <= m; i++) {
				f[j][k][i] = max(f[j - 1][k][i], f[j - 1][k][i + (1 << (j - 1))]);
			}
		}
	}
	for (int k = 1; k <= m; k++) {
		for (int l = 0; k + (1 << l) - 1 <= m; l++) {
			for (int i = 1; i <= n; i++) {
				g[l][0][k][i] = f[l][i][k];
			}
			for (int j = 1; 1 << j <= n; j++) {
				for (int i = 0; i + (1 << j) - 1 <= n; i++) {
					g[l][j][k][i] = max(g[l][j - 1][k][i], g[l][j - 1][k][i + (1 << (j - 1))]);
				}
			}
		}
	}
}
inline int query(int i, int j, int a, int b) {
	int lga = __lg(a);
	int lgb = __lg(b);
	int res = g[lgb][lga][j][i];
	res = max(res, g[lgb][lga][j + b - (1 << (lgb))][i + a - (1 << (lga))]);
	res = max(res, g[lgb][lga][j][i + a - (1 << (lga))]);
	res = max(res, g[lgb][lga][j + b - (1 << (lgb))][i]);
	return res;
}

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 1, n + 1) FOR(j, 1, m + 1) scanf("%d", &a[i][j]);
	FOR(i, 1, n + 1) FOR(j, 1, m + 1) {
		if (a[i][j]) {
			f[0][i][j] = min(f[0][i - 1][j - 1], min(f[0][i - 1][j], f[0][i][j - 1])) + 1;
		}
	}
	build();
	int q; scanf("%d", &q);
	while (q--) {
		int x[2], y[2];
		FOR(i, 0, 2) scanf("%d%d", x + i, y + i);
		int lo = 0, hi = min(x[1] - x[0] + 1, y[1] - y[0] + 1);
		while (lo < hi) {
			int mi = lo + hi + 1 >> 1;
			if (query(x[0] + mi - 1, y[0] + mi - 1, x[1] - x[0] - mi + 2, y[1] - y[0] - mi + 2) >= mi) {
				lo = mi;
			}
			else {
				hi = mi - 1;
			}
		}
		printf("%d\n", lo);
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
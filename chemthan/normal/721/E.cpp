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

const int maxn = 100000 + 10;
int l, n, p, t;
int a[maxn];
int b[maxn];
pi f[maxn];
int g[maxn];

int ff(int ix, int st) {
	int l = 0, r = ix - 1;
	while (l < r) {
		int m = l + r + 1 >> 1;
		if (a[m] + p <= st - t) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}
	int res = 0;
	if (a[l] + p <= st - t) {
		if (st - t < b[l]) {
			if (st - t >= f[l].fi) {
				chkmax(res, f[l].se + (st - t - f[l].fi - a[l]) / p);
			}
			else {
				chkmax(res, f[l].se - 1);
			}
		}
		else {
			chkmax(res, g[l]);
		}
	}
	if (l) chkmax(res, g[l - 1]);
	return res;
}

void solve() {
	cin >> l >> n >> p >> t;
	FOR(i, 0, n) cin >> a[i] >> b[i];
	f[0] = mp(0, 0);
	g[0] = (b[0] - a[0]) / p;
	FOR(i, 1, n) {
		int x = ff(i, a[i]);
		int l = 0, r = min(b[i] - a[i], p - 1);
		while (l < r) {
			int m = l + r >> 1;
			if (ff(i, a[i] + m) == x) {
				l = m + 1;
			}
			else {
				r = m;
			}
		}
		int z = 0;
		if (ff(i, a[i] + l) > x) {
			x++;
			z = l;
		}
		f[i] = mp(z, x);
		g[i] = max(g[i - 1], x + (b[i] - a[i] - z) / p);
	}
	cout << g[n - 1] << "\n";
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
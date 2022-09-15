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

const int maxn = 1500 + 10;
const int maxk = 1000000 + 10;
int n, m;
int a, b, k;
int p;
int g[maxk];
int f[maxn][maxn];
int h[maxn];

void solve() {
	cin >> n >> m >> a >> b >> k;
	p = mult(a, inv(b));
	if (p != 1) {
		g[0] = fpow(MOD - p + 1, k);
		FOR(i, 1, k + 1) {
			g[i] = mult(g[i - 1], k - i + 1);
			g[i] = mult(g[i], inv(i));
			g[i] = mult(g[i], p);
			g[i] = mult(g[i], inv(MOD - p + 1));
		}
	}
	else {
		g[k] = 1;
	}
	f[0][m - 1] = 1;
	FOR(i, 1, n + 1) {
		fill_n(h, m, 0);
		h[0] = f[i - 1][0];
		FOR(j, 1, m) {
			h[j] = h[j - 1];
			addmod(h[j], f[i - 1][j]);
		}
		int t1 = 0, t2 = 0;
		FOR(r, 0, m) {
			addmod(t1, g[r]);
			if (r) {
				addmod(t2, mult(g[r], h[r - 1]));
			}
			int tmp = h[m - 1];
			if (r < m - 1) {
				submod(tmp, h[m - r - 2]);
			}
			f[i][r] = mult(tmp, t1);
			submod(f[i][r], t2);
			f[i][r] = mult(f[i][r], g[m - r - 1]);
		}
	}
	int ans = 0;
	FOR(i, 0, m) addmod(ans, f[n][i]);
	cout << ans << "\n";
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
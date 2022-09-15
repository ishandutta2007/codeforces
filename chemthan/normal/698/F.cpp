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

const int maxn = 1000000 + 10;
int n;
int a[maxn];
vi g[maxn];
int f[maxn];
int d[maxn];
int m[maxn];
int mm[maxn];
int t[maxn];
int fac[maxn];

int ff(int k) {
	return k == 1 ? 1 : n / k;
}

void solve() {
	cin >> n;
	fac[0] = 1; FOR(i, 1, n + 1) fac[i] = mult(fac[i - 1] , i);
	FOR(i, 2, n + 1) {
		if (!sz(g[i])) {
			for (int j = i; j <= n; j += i) {
				g[j].pb(i);
			}
		}
	}
	g[1].pb(1);
	FOR(i, 1, n + 1) {
		f[i] = 1;
		FOR(j, 0, sz(g[i])) {
			f[i] *= g[i][j];
		}
		d[f[i]]++;
	}
	FOR(i, 1, n + 1) {
		cin >> a[i];
		if (a[i]) {
			d[f[a[i]]]--;
			if (sz(g[i]) != sz(g[a[i]])) {
				cout << 0 << "\n";
				return;
			}
			FOR(j, 0, sz(g[i])) {
				if (ff(g[i][j]) != ff(g[a[i]][j])) {
					cout << 0 << "\n";
					return;
				}
				if (!m[g[i][j]]) m[g[i][j]] = g[a[i]][j];
				else if (m[g[i][j]] != g[a[i]][j]) {
					cout << 0 << "\n";
					return;
				}
				if (!mm[g[a[i]][j]]) mm[g[a[i]][j]] = g[i][j];
				else if (mm[g[a[i]][j]] != g[i][j]) {
					cout << 0 << "\n";
					return;
				}
			}
		}
	}
	FOR(i, 1, n + 1) if (sz(g[i]) == 1 && g[i][0] == i && !m[i]) {
		t[ff(i)]++;
	}
	int ans = 1;
	FOR(i, 1, n + 1) {
		ans = mult(ans, fac[d[i]]);
		ans = mult(ans, fac[t[i]]);
	}
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
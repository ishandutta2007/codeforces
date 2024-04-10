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

const int maxn = 500 + 10;
int n, k;
int a[maxn];
int b[maxn];
int sum[maxn];
int mx[maxn][maxn];

int f[maxn][maxn];
int r[maxn][maxn];

int calc(int u, int v) {
	if (u == n && v == k) return 1;
	int& res = f[u][v];
	if (~res) return res;
	res = 0;
	FOR(i, u, n) {
		if (sum[i + 1] - sum[u] == b[v] && ((long long) mx[u][i] * (i - u + 1) != b[v] || u == i)) {
			if (calc(i + 1, v + 1)) {
				r[u][v] = i;
				res = 1;
				return res;
			}
		}
	}
	return res;
}

pair<int, int> findix(int l, int r) {
	int mx = 0, ix = 0;
	FOR(i, l, r + 1) {
		if (chkmax(mx, a[i])) {
			ix = i;
		}
	}
	if (a[r] == mx && a[r - 1] < mx) {
		return mp(r, 0);
	}
	if (a[l] == mx && a[l + 1] < mx) {
		return mp(l, 1);
	}
	FOR(i, l + 1, r) {
		if (a[i] == mx && a[i - 1] < mx) {
			return mp(i, 0);
		}
		if (a[i] == mx && a[i + 1] < mx) {
			return mp(i, 1);
		}
	}
}

void solve() {
	cin >> n;
	FOR(i, 0, n) cin >> a[i], sum[i + 1] = sum[i] + a[i];
	cin >> k;
	FOR(i, 0, k) cin >> b[i];
	FOR(i, 0, n) {
		int tmp = 0;
		FOR(j, i, n) {
			chkmax(tmp, a[j]);
			mx[i][j] = tmp;
		}
	}
	ms(f, -1);
	vector<pair<int, char> > ans;
	if (!calc(0, 0)) {
		cout << "NO\n";
	}
	else {
		int cu = 0, v = 0;
		int tot = 0;
		while (cu != n) {
			int ncu = r[cu][v];
			if (cu < ncu) {
				int ix = findix(cu, ncu).fi;
				int sign = findix(cu, ncu).se;
				if (!sign) {
					int tmp = ix - tot;
					FORd(i, ix, cu) {
						ans.pb(mp(tmp, 'L'));
						tmp--;
						tot++;
					}
					FOR(i, ix + 1, ncu + 1) {
						ans.pb(mp(tmp, 'R'));
						tot++;
					}
				}
				else {
					int tmp = ix - tot;
					FOR(i, ix + 1, ncu + 1) {
						ans.pb(mp(tmp, 'R'));
						tot++;
					}
					FORd(i, ix, cu) {
						ans.pb(mp(tmp, 'L'));
						tmp--;
						tot++;
					}
				}
			}
			cu = ncu + 1;
			v++;
		}
		cout << "YES\n";
		FOR(i, 0, sz(ans)) {
			cout << ans[i].fi + 1 << " " << ans[i].se << "\n";
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
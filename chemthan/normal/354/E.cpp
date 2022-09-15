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

const int maxd = 20;
int a[maxd];
vector<pair<vector<int>, int> > g[maxd];
int f[maxd][maxd];
int nxt[maxd][7];

int calc(int pos, int r) {
	if (r > 6) return 0;
	if (pos == maxd) {
		return r == 0;
	}
	int& res = f[pos][r];
	if (~res) return res;
	res = 0;
	int d = (a[pos] - r + 10) % 10;
	FOR(i, 0, sz(g[d])) {
		int tot = r + g[d][i].se;
		if (calc(pos + 1, tot / 10)) {
			res = 1;
			nxt[pos][r] = i;
			return res;
		}
	}
	return res;
}

int ar[] = {0, 4, 7};

void go(int pos, vector<int> cur) {
	if (pos == 6) {
		int tot = 0;
		FOR(i, 0, 6) tot += cur[i];
		g[tot % 10].pb(mp(cur, tot));
		return;
	}
	FOR(i, 0, 3) {
		vector<int> ncur = cur;
		ncur.pb(ar[i]);
		go(pos + 1, ncur);
	}
}

void solve() {
	go(0, vector<int>());
	int test; cin >> test;
	while (test--) {
		long long n; cin >> n;
		ms(a, 0);
		int cnt = 0;
		while (n) {
			a[cnt++] = n % 10;
			n /= 10;
		}
		ms(f, -1);
		if (!calc(0, 0)) {
			cout << -1 << "\n";
		}
		else {
			int cpos = 0, cr = 0;
			long long res[6] = {}, tmp = 1;
			FOR(pos, 0, maxd) {
				int d = (a[cpos] - cr + 10) % 10;
				int k = nxt[cpos][cr];
				FOR(i, 0, 6) {
					res[i] += tmp * g[d][k].fi[i];
				}
				cpos++, cr = (cr + g[d][k].se) / 10;
				tmp *= 10;
			}
			sort(res, res + 6); reverse(res, res + 6);
			FOR(i, 0, 6) cout << res[i] << " \n"[i == 5];
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
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

const int maxn = 1000000 + 10;
int n;
string t[maxn];
int x[maxn];
int y[maxn];
vii gx;
vii gy;

int check(int op) {
	gx.clear(), gy.clear();
	FOR(i, 1, n + 1) {
		if (x[i] == x[0]) {
			gx.pb(mp(y[i], i));
		}
		if (y[i] == y[0]) {
			gy.pb(mp(x[i], i));
		}
	}
	sort(all(gx));
	sort(all(gy));
	int k;
	
	k = upper_bound(all(gx), mp(y[0], 2 * INF + 5)) - gx.begin();
	if (k < sz(gx)) {
		int ix = gx[k].se;
		if (!op) {
			if (t[ix] == "R" || t[ix] == "Q") {
				return 1;
			}
		}
		else {
			if (t[ix] == "B" || t[ix] == "Q") {
				return 1;
			}
		}
	}
	k = lower_bound(all(gx), mp(y[0], -2 * INF - 5)) - gx.begin() - 1;
	if (k >= 0) {
		int ix = gx[k].se;
		if (!op) {
			if (t[ix] == "R" || t[ix] == "Q") {
				return 1;
			}
		}
		else {
			if (t[ix] == "B" || t[ix] == "Q") {
				return 1;
			}
		}
	}
	if (op) return 0;
	k = upper_bound(all(gy), mp(x[0], 2 * INF + 5)) - gy.begin();
	if (k < sz(gy)) {
		int ix = gy[k].se;
		if (!op) {
			if (t[ix] == "R" || t[ix] == "Q") {
				return 1;
			}
		}
		else {
			if (t[ix] == "B" || t[ix] == "Q") {
				return 1;
			}
		}
	}
	k = lower_bound(all(gy), mp(x[0], -2 * INF - 5)) - gy.begin() - 1;
	if (k >= 0) {
		int ix = gy[k].se;
		if (!op) {
			if (t[ix] == "R" || t[ix] == "Q") {
				return 1;
			}
		}
		else {
			if (t[ix] == "B" || t[ix] == "Q") {
				return 1;
			}
		}
	}
	return 0;
}

void solve() {
	cin >> n >> x[0] >> y[0];
	FOR(i, 1, n + 1) cin >> t[i] >> x[i] >> y[i];
	if (check(0)) {
		cout << "YES\n";
		return;
	}
	FOR(i, 0, n + 1) {
		x[i] += y[i];
	}
	if (check(1)) {
		cout << "YES\n";
		return;
	}
	FOR(i, 0, n + 1) {
		x[i] -= y[i];
		x[i] -= y[i];
	}
	if (check(1)) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
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
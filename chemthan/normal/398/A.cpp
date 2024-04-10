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

int a, b;

long long calc(int k, int l) {
	if (a < k || b < l) {
		return -LINF << 3;
	}
	long long res = (long long) (a - k + 1) * (a - k + 1) + k - 1;
	int r = b % l;
	int d = b / l;
	res -= (long long) r * (d + 1) * (d + 1);
	res -= (long long) (l - r) * d * d;
	return res;
}

void solve() {
	cin >> a >> b;
	if (!a) {
		cout << (long long) -b * b << "\n";
		FOR(i, 0, b) cout << "x";
		cout << "\n";
		return;
	}
	else if (!b) {
		cout << (long long) a * a << "\n";
		FOR(i, 0, a) cout << "o";
		cout << "\n";
		return;
	}
	pair<long long, pi> best = mp(-LINF << 3, mp(-1, -1));
	FOR(i, 1, 100010) {
		chkmax(best, mp(calc(i, i + 1), mp(i, i + 1)));
		chkmax(best, mp(calc(i + 1, i), mp(i + 1, i)));
		chkmax(best, mp(calc(i, i), mp(i, i)));
	}
	cout << best.fi << "\n";
	int k = best.se.fi, l = best.se.se;
	vector<int> ra, rb;
	FOR(i, 0, k - 1) ra.pb(1);
	ra.pb(a - k + 1);
	int r = b % l;
	int d = b / l;
	FOR(i, 0, l) {
		if (r-- > 0) {
			rb.pb(d + 1);
		}
		else {
			rb.pb(d);
		}
	}
	if (k == l) {
		FOR(i, 0, k) {
			FOR(j, 0, ra[i]) cout << "o";
			FOR(j, 0, rb[i]) cout << "x";
		}
	}
	else if (k > l) {
		FOR(i, 0, ra[0]) cout << "o";
		FOR(i, 0, l) {
			FOR(j, 0, rb[i]) cout << "x";
			FOR(j, 0, ra[i + 1]) cout << "o";
		}
	}
	else if (k < l) {
		FOR(i, 0, rb[0]) cout << "x";
		FOR(i, 0, k) {
			FOR(j, 0, ra[i]) cout << "o";
			FOR(j, 0, rb[i + 1]) cout << "x";
		}
	}
	cout << "\n";
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
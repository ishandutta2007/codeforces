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

const int maxn = 1e8;
const int magic = 2e3 + 5;
vi ver, hor;

int ask(int x, int y) {
	cout << 0 << " " << x << " " << y << "\n";
	cout.flush();
	int res; cin >> res;
	return res;
}

void findhor(int x, int l, int r) {
	if (r - l < 2) return;
	int m = (l + r) / 2;
	if (m + m > l + r) m--;
	int mx = (r - l - 2) >> 1;
	for (int i = 0; i <= (l + r & 1); i++, m++) {
		int d = ask(x, m);
		if (!d) {
			hor.pb(m);
			findhor(x, l, m);
			findhor(x, m, r);
			return;
		}
		else if (d <= mx) {
			int d2 = ask(x, m + 1);
			if (d2 < d) {
				hor.pb(m + d);
				findhor(x, l, m + d);
				findhor(x, m + d, r);
				return;
			}
			else {
				hor.pb(m - d);
				findhor(x, l, m - d);
				findhor(x, m - d, r);
				return;
			}
		}
	}
}

void findver(int l, int r, int y) {
	if (r - l < 2) return;
	int m = (l + r) / 2;
	if (m + m > l + r) m--;
	int mx = (r - l - 2) >> 1;
	for (int i = 0; i <= (l + r & 1); i++, m++) {
		int d = ask(m, y);
		if (!d) {
			ver.pb(m);
			findver(l, m, y);
			findver(m, r, y);
			return;
		}
		else if (d <= mx) {
			int d2 = ask(m + 1, y);
			if (d2 < d) {
				ver.pb(m + d);
				findver(l, m + d, y);
				findver(m + d, r, y);
				return;
			}
			else {
				ver.pb(m - d);
				findver(l, m - d, y);
				findver(m - d, r, y);
				return;
			}
		}
	}
}

void findhor(int x) {
	for (int i = -maxn; i < maxn; i += 2e3 + 1) {
		findhor(x, i - 1, min(maxn, i + 2000) + 1);
	}
}

void findver(int y) {
	for (int i = -maxn; i < maxn; i += 2e3 + 1) {
		findver(i - 1, min(maxn, i + 2000) + 1, y);
	}
}

void solve() {
	srand(2311);
	while (1) {
		int x = 1000 * (rand() % (maxn / 1000 + maxn / 1000 + 1) - maxn / 1000);
		int y = 1000 * (rand() % (maxn / 1000 + maxn / 1000 + 1) - maxn / 1000);
		if (ask(x, y) >= magic) {
			findhor(x), findver(y);
			break;
		}
	}
	sort(all(ver)), sort(all(hor));
	cout << 1 << " " << sz(ver) << " " << sz(hor) << "\n";
	FOR(i, 0, sz(ver)) cout << ver[i] << " \n"[i == sz(ver) - 1];
	FOR(i, 0, sz(hor)) cout << hor[i] << " \n"[i == sz(hor) - 1];
	cout.flush();
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
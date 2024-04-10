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
int n;
int a[maxn][3];
pair<int, pi> best;
map<pi, vii> hs;

void solve() {
	cin >> n;
	FOR(i, 0, n) {
		FOR(j, 0, 3) cin >> a[i][j];
		sort(a[i], a[i] + 3);
		chkmax(best, mp(a[i][0], mp(i + 1, 0)));
		map<pi, int> tmp;
		FOR(j, 0, 3) FOR(k, j + 1, 3) FOR(l, 0, 3) if (l != j && l != k) {
			if (!tmp.count(mp(a[i][j], a[i][k]))) {
				tmp[mp(a[i][j], a[i][k])] = 1;
				hs[mp(a[i][j], a[i][k])].pb(mp(a[i][l], i + 1));
			}
		}
	}
	FORall(it, hs) {
		pi x = it->fi;
		vii y = it->se;
		sort(all(y)), reverse(all(y));
		if (sz(y) > 1) {
			chkmax(best, mp(min(min(x.fi, x.se), y[0].fi + y[1].fi), mp(y[0].se, y[1].se)));
		}
	}
	if (best.se.se) {
		cout << 2 << "\n";
		cout << best.se.fi << " " << best.se.se << "\n";
	}
	else {
		cout << 1 << "\n";
		cout << best.se.fi << "\n";
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
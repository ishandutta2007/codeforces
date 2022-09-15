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
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "-----------\n";

const int maxn = 50 + 5;
int n, m;
int a[maxn][maxn];
int b[maxn][maxn];
vii ans;

void fix(int u, int v) {
	if (a[u][v] == 'L') {
		if (a[u + 1][v] == 'R') {
			fix(u + 1, v - 1);
		}
		if (a[u + 1][v] == 'U') {
			fix(u + 1, v);
		}
		if (a[u + 1][v] == 'L') {
			ans.pb(mp(u, v));
			a[u][v] = a[u][v + 1] = 'U';
			a[u + 1][v] = a[u + 1][v + 1] = 'D';
		}
	}
	else if (a[u][v] == 'U') {
		if (a[u][v + 1] == 'D') {
			fix(u - 1, v + 1);
		}
		if (a[u][v + 1] == 'L') {
			fix(u, v + 1);
		}
		if (a[u][v + 1] == 'U') {
			ans.pb(mp(u, v));
			a[u][v] = a[u + 1][v] = 'L';
			a[u][v + 1] = a[u + 1][v + 1] = 'R';
		}
	}
}

void solve() {
	cin >> n >> m;
	FOR(i, 0, n) {
		string s; cin >> s;
		FOR(j, 0, m) a[i][j] = s[j];
	}
	FOR(i, 0, n) {
		string s; cin >> s;
		FOR(j, 0, m) b[i][j] = s[j];
	}
	FOR(i, 0, n) FOR(j, 0, m) if (a[i][j] != b[i][j]) {
		fix(i, j);
	}
	cout << sz(ans) << "\n";
	FOR(i, 0, sz(ans)) {
		cout << ans[i].fi + 1 << " " << ans[i].se + 1 << "\n";
	}
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
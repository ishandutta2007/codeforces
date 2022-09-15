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

const int maxn = 110;
int n, m;
int a[maxn];
string op[maxn];
int team[maxn];
int f[20][1 << 20];
vector<int> vz[1 << 20];
int best[1 << 20];

int calc(int pos, int msk) {
	if (pos == m) {
		return 0;
	}
	int& res = f[pos][msk];
	if (res != -INF << 1) return res;
	if (team[pos] == 1) {
		if (op[pos] == "p") {
			int k = best[msk];
			if (~k) {
				res = calc(pos + 1, msk ^ (1 << k)) + a[k];
			}
		}
		else if (op[pos] == "b") {
			res = -INF;
			FOR(i, 0, sz(vz[msk])) {
				int k = vz[msk][i];
				chkmax(res, calc(pos + 1, msk ^ (1 << k)));
			}
		}
	}
	else {
		if (op[pos] == "p") {
			int k = best[msk];
			if (~k) {
				res = calc(pos + 1, msk ^ (1 << k)) - a[k];
			}
		}
		else if (op[pos] == "b") {
			res = INF;
			FOR(i, 0, sz(vz[msk])) {
				int k = vz[msk][i];
				chkmin(res, calc(pos + 1, msk ^ (1 << k)));
			}
		}
	}
	return res;
}

void solve() {
	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	sort(a, a + n); reverse(a, a + n);
	cin >> m;
	FOR(i, 0, m) cin >> op[i] >> team[i];
	int k = min(m, n);
	FOR(msk, 0, 1 << k) {
		best[msk] = -1;
		FOR(i, 0, k) if (bit(msk, i)) {
			best[msk] = i;
			break;
		}
		FOR(i, 0, k) if (bit(msk, i)) {
			vz[msk].pb(i);
		}
	}
	FOR(i, 0, m) FOR(msk, 0, 1 << k) f[i][msk] = -INF << 1;
	cout << calc(0, (1 << k) - 1) << "\n";
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
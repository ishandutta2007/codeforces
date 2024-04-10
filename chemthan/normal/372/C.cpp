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

const int maxn = 150000 + 1;
const int maxm = 300 + 1;
int n, m, d;
int a[maxm];
int b[maxm];
int t[maxm];
long long f[2][maxn];
long long rmq[maxn << 1];

inline void upd(int p, long long val) {
	for (rmq[p += n] = val; p > 1; ) p >>= 1, rmq[p] = min(rmq[p << 1], rmq[p << 1 | 1]);
}
inline long long query(int l, int r) {
	long long res = LINF;
	for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = min(res, rmq[l++]);
		if (r & 1) res = min(res, rmq[--r]);
	}
	return res;
}

void solve() {
	cin >> n >> m >> d;
	FOR(i, 0, m) cin >> a[i] >> b[i] >> t[i], a[i]--;
	int cnt = 0;
	FOR(pos, 0, n) f[cnt][pos] = abs(a[m - 1] - pos);
	FORd(i, m - 1, 0) {
		FOR(pos, 0, n) upd(pos, f[cnt][pos]);
		FOR(pos, 0, n) {
			int l = max((long long) 0, pos - (long long) d * (t[i + 1] - t[i]));
			int r = min((long long) n - 1, pos + (long long) d * (t[i + 1] - t[i]));
			f[cnt ^ 1][pos] = query(l, r) + abs(pos - a[i]);
		}
		cnt ^= 1;
	}
	long long ans = LINF;
	FOR(i, 0, n) chkmin(ans, f[cnt][i]);
	ans *= -1;
	FOR(i, 0, m) ans += b[i];
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
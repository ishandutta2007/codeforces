#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define FORalld(it, a) for (__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
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
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}

typedef long long T;
const T oo = (T) 1e18;
struct ConvexhullTrick {
	struct Line {
		T a, b;
		Line(T a, T b) : a(a), b(b) {}
	};
	long double intersect(Line ln1, Line ln2) {
		return (long double) (ln2.b - ln1.b) / (ln1.a - ln2.a);
	}
	int bad(Line ln1, Line ln2, Line ln3) {
		return (long double) (ln1.a - ln2.a) * (ln2.b - ln3.b) >= (long double) (ln2.a - ln3.a) * (ln1.b - ln2.b);
	}
	vector<Line> hull;
	vector<long double> pos;
	ConvexhullTrick() {
		pos.push_back(-oo);
		pos.push_back(+oo);
	}
	void add(T a, T b) {
		Line ln(a, b);
		pos.pop_back();
		while (hull.size() >= 2 && bad(hull[hull.size() - 2], hull[hull.size() - 1], ln)) {
			hull.pop_back();
			pos.pop_back();
		}
		hull.push_back(ln);
		if (hull.size() >= 2) pos.push_back(intersect(hull[hull.size() - 2], hull[hull.size() - 1]));
		pos.push_back(+oo);
	}
	T query(T x) {
		if (!hull.size()) return oo;
		int k = lower_bound(pos.begin(), pos.end(), x) - pos.begin() - 1;
		return hull[k].a * x + hull[k].b;
	}
};

const int maxn = 100000 + 10;
const int maxp = 100 + 10;
int n, m, p;
int d[maxn];
int h[maxn];
int t[maxn];
long long dp[maxp][maxn];

void solve() {
	cin >> n >> m >> p;
	FOR(i, 1, n) cin >> d[i], d[i] += d[i - 1];
	vi v;
	FOR(i, 0, m) {
		cin >> h[i] >> t[i], h[i]--;
		v.pb(t[i] - d[h[i]]);
	}
	sort(all(v));
	if (v.back() < 0) {
		long long ans = 0;
		FOR(i, 0, sz(v)) {
			ans += -v[i];
		}
		cout << ans << "\n";
		return;
	}
	long long sum = 0;
	FOR(i, 0, sz(v)) sum += v[i];
	FOR(k, 1, p + 1) FOR(i, 0, sz(v)) dp[k][i] = LINF;
	dp[1][sz(v) - 1] = (long long) m * v.back() - sum;
	FOR(k, 1, p) {
		ConvexhullTrick cht;
		FORd(i, sz(v) - 1, 0) {
			if (dp[k][i + 1] < LINF) {
				cht.add(v[i + 1], dp[k][i + 1]);
			}
			dp[k + 1][i] = cht.query(-i - 1) + (long long) (i + 1) * v[i];
		}
	}
	long long ans = LINF;
	FOR(k, 1, p + 1) FOR(i, 0, sz(v)) chkmin(ans, dp[k][i]);
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
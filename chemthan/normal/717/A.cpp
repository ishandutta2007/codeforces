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

struct Num {
	int a, b;
	Num() : a(0), b(0) {}
	Num(int a, int b) : a(a), b(b) {}
	Num(const Num& rhs) : a(rhs.a), b(rhs.b) {}
	Num operator + (const Num& rhs) const {
		Num res;
		res.a = a + rhs.a;
		if (res.a >= MOD) res.a -= MOD;
		res.b = b + rhs.b;
		if (res.b >= MOD) res.b -= MOD;
		return res;
	}
	Num operator - (const Num& rhs) const {
		Num res;
		res.a = a - rhs.a;
		if (res.a < 0) res.a += MOD;
		res.b = b - rhs.b;
		if (res.b < 0) res.b += MOD;
		return res;
	}
	Num operator * (const Num& rhs) const {
		Num res;
		res.a = ((long long) a * rhs.a + (long long) 5 * b * rhs.b) % MOD;
		res.b = ((long long) a * rhs.b + (long long) b * rhs.a) % MOD;
		return res;
	}
	Num operator ^ (long long k) {
		if (!k) return Num(1, 0);
		Num tmp = Num(a, b), res = Num(a, b); k--;
		while (k) {
			if (k & 1) res = res * tmp;
			tmp = tmp * tmp;
			k >>= 1;
		}
		return res;
	}
	friend Num geometricseries(Num a, long long k) {
		if (!k) return Num(1, 0);
		if (k == 1) return a;
		vector<int> bit;
		while (k) {
			bit.push_back(k & 1);
			k >>= 1;
		}
		Num res = a, tmp = a;
		for (int i = bit.size() - 2; i >= 0; i--) {
			res = res + (res * tmp);
			tmp = tmp * tmp;
			if (bit[i] & 1) {
				tmp = tmp * a;
				res = res + tmp;
			}
		}
		return res;
	}
};

const int maxk = 200 + 10;
int k;
long long l, r;
int c[maxk][maxk];
int s[maxk][maxk];
int fac[maxk];
Num n1[maxk];
Num n2[maxk];

int calc(long long x) {
	int res = 0;
	FOR(i, 1, k + 1) {
		FOR(j, 0, i + 1) {
			Num tmp = n1[j] * n2[i - j];
			tmp = geometricseries(tmp, x);
			if ((i - j) & 1) {
				tmp.a = (MOD - tmp.a) % MOD;
				tmp.b = (MOD - tmp.b) % MOD;
			}
			tmp = tmp * Num(c[j][i], 0);
			if (i & 1) {
				addmod(res, mult(s[k][i], mult(tmp.b, inv(fpow(5, i >> 1)))));
			}
			else {
				addmod(res, mult(s[k][i], mult(tmp.a, inv(fpow(5, i >> 1)))));
			}
		}
	}
	return res;
}

void solve() {
	FOR(i, 0, maxk) c[0][i] = 1;
	FOR(i, 1, maxk) FOR(j, 1, maxk) c[i][j] = (c[i][j - 1] + c[i - 1][j - 1]) % MOD;
	s[0][0] = 1;
	FOR(i, 1, maxk) FOR(j, 1, maxk) {
		submod(s[i][j], mult(i - 1, s[i - 1][j]));
		addmod(s[i][j], s[i - 1][j - 1]);
	}
	fac[0] = 1; FOR(i, 1, maxk) fac[i] = mult(fac[i - 1], i);
	n1[0] = n2[0] = Num(1, 0);
	n1[1] = Num(inv(2), inv(2)), n2[1] = Num(inv(2), MOD - inv(2));
	FOR(i, 1, maxk) n1[i] = n1[i - 1] * n1[1], n2[i] = n2[i - 1] * n2[1];
	cin >> k >> l >> r;
	int ans = calc(r + 2);
	submod(ans, calc(l + 1));
	ans = mult(ans, inv(fac[k]));
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
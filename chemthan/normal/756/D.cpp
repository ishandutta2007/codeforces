#include <bits/stdc++.h>
using namespace std;

#ifdef _LOCAL_
	#define cout cerr
#endif
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

template<class T, T p, class mul, class dvd> struct FiniteField {
	T x;
	FiniteField() {
		x = 0;
	}
	FiniteField(const FiniteField& rhs) {
		x = rhs.x;
	}
	template<class G> T normalize(G x) {
		if (x >= 0 && x < p) return x;
		x %= p;
		if (x < 0) x += p;
		else if (x >= p) x -= p;
	}
	template<class G> FiniteField operator () (const G& y) {
		x = normalize(y);
		return *this;
	}
	template<class G> FiniteField operator = (const G& y) {
		x = normalize(y);
		return *this;
	}
	FiniteField operator ++(int) {
		FiniteField res = *this;
		if ((++x) >= p) x -= p;
		return res;
	}
	FiniteField operator ++() {
		if ((++x) >= p) x -= p;
		return *this;
	}
	FiniteField operator --(int) {
		FiniteField res = *this;
		if ((--x) < 0) x += p;
		return res;
	}
	FiniteField operator --() {
		if ((--x) < 0) x += p;
		return *this;
	}
	FiniteField operator += (const T& y) {
		if ((x += normalize(y)) >= p) x -= p;
		return *this;
	}
	FiniteField operator -= (const T& y) {
		if ((x -= normalize(y)) < 0) x += p;
		return *this;
	}
	FiniteField operator += (const FiniteField& rhs) {
		if ((x += rhs.x) >= p) x -= p;
		return *this;
	}
	FiniteField operator -= (const FiniteField& rhs) {
		if ((x -= rhs.x) < 0) x += p;
		return *this;
	}
	FiniteField operator + (const FiniteField& rhs) const {
		FiniteField res;
		res.x = x + rhs.x;
		if (res.x >= p) res.x -= p;
		return res;
	}
	FiniteField operator - (const FiniteField& rhs) const {
		FiniteField res;
		res.x = x - rhs.x;
		if (res.x < 0) res.x += p;
		return res;
	}
	FiniteField operator *= (const T& y) {
		x = mul()(x, normalize(y), p);
		return *this;
	}
	FiniteField operator /= (const T& y) {
		x = dvd()(x, normalize(y), p);
		return *this;
	}
	FiniteField operator * (const T& y) const {
		FiniteField res;
		res.x = mul()(x, normalize(y), p);
		return res;
	}
	FiniteField operator / (const T& y) const {
		FiniteField res;
		res.x = dvd()(x, normalize(y), p);
		return res;
	}
	FiniteField operator * (const FiniteField& rhs) const {
		FiniteField res;
		res.x = mul()(x, rhs.x, p);
		return res;
	}
	FiniteField operator / (const FiniteField& rhs) const {
		FiniteField res;
		res.x = dvd()(x, rhs.x, p);
		return res;
	}
	template<class G> FiniteField operator ^= (G k) {
		if (k == 0) {
			x = 1;
			return *this;
		}
		T t = x; k--;
		while (k > 0) {
			if (k & 1) x = mul()(x, t, p);
			t = mul()(t, t, p);
			k >>= 1;
		}
		return * this;
	}
	template<class G> FiniteField operator ^ (G k) {
		if (k == 0) {
			FiniteField res;
			res.x = 1;
			return res;
		}
		T r = x, t = x; k--;
		while (k > 0) {
			if (k & 1) r = mul()(r, t, p);
			t = mul()(t, t, p);
			k >>= 1;
		}
		FiniteField res;
		res.x = r;
		return res;
	}
	friend ostream& operator << (ostream& os, const FiniteField& rhs) {
		os << rhs.x;
		return os;
	}
	
};
template<class T> class mul {
	public:
	T operator () (const T& x, const T& y, const T& p) {
		return (long long) x * y % p;
	}
};
template<class T> class dvd {
	public:
	T operator () (const T& x, const T& y, const T& p) {
		pair<T, T> r = euclid(y, p);
		return mul<T>()(x, (r.first % p + p) % p, p);
	}
	private:
	pair<T, T> euclid(T a, T b) {
		if (b == 0) return make_pair(1, 0);
		pair<T, T> r = euclid(b, a % b);
		return make_pair(r.second, r.first - a / b * r.second);
	}
};

typedef FiniteField<int, (int) 1e9 + 7, mul<int>, dvd<int> > FF;
const int maxn = 5000 + 5;
const int maxc = 26;
int n;
string s;
int lst[maxc];
FF dp[maxn][maxn];

void solve() {
	cin >> n >> s;
	s = " " + s, n++;
	fill_n(dp[n] + 1, n, 1);
	FORd(i, n, 0) {
		FF tot;
		fill_n(lst, maxc, -1);
		FORd(j, n, 0) {
			if (j) {
				dp[i][j] = dp[i + 1][j];
			}
			dp[i][j] += tot;
			if (j) {
				if (lst[s[j] - 'a'] != -1) {
					int d = lst[s[j] - 'a'];
					dp[i][j] -= dp[i + 1][d];
					tot -= dp[i + 1][d];
				}
				tot += dp[i + 1][j];
				lst[s[j] - 'a'] = j;
			}
		}
	}
	cout << dp[1][0] << "\n";
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
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

template<class T, class mul, class dvd, class mod> struct FiniteField {
	T x;
	template<class G> T normalize(G x) {
		T p = mod().get();
		if (x >= 0 && x < p) return x;
		x %= p;
		if (x < 0) x += p;
		else if (x >= p) x -= p;
		return x;
	}
	FiniteField() : x(0) {}
	template<class G> FiniteField(const G& y) {
		x = normalize(y);
	}
	FiniteField(const FiniteField& rhs) : x(rhs.x) {
	}
	template<class G> FiniteField operator = (const G& y) {
		x = normalize(y);
		return *this;
	}
	int operator == (const FiniteField& rhs) const {
		return x == rhs.x;
	}
	int operator != (const FiniteField& rhs) const {
		return x != rhs.x;
	}
	int operator < (const FiniteField& rhs) const {
		return x < rhs.x;
	}
	FiniteField operator ++(int) {
		T p = mod().get();
		FiniteField res = *this;
		if ((++x) >= p) x -= p;
		return res;
	}
	FiniteField operator ++() {
		T p = mod().get();
		if ((++x) >= p) x -= p;
		return *this;
	}
	FiniteField operator --(int) {
		T p = mod().get();
		FiniteField res = *this;
		if ((--x) < 0) x += p;
		return res;
	}
	FiniteField operator --() {
		T p = mod().get();
		if ((--x) < 0) x += p;
		return *this;
	}
	template<class G> FiniteField operator += (const G& y) {
		T p = mod().get();
		if ((x += normalize(y)) >= p) x -= p;
		return *this;
	}
	template<class G> FiniteField operator -= (const G& y) {
		T p = mod().get();
		if ((x -= normalize(y)) < 0) x += p;
		return *this;
	}
	FiniteField operator += (const FiniteField& rhs) {
		T p = mod().get();
		if ((x += rhs.x) >= p) x -= p;
		return *this;
	}
	FiniteField operator -= (const FiniteField& rhs) {
		T p = mod().get();
		if ((x -= rhs.x) < 0) x += p;
		return *this;
	}
	FiniteField operator + (const FiniteField& rhs) const {
		T p = mod().get();
		FiniteField res;
		res.x = x + rhs.x;
		if (res.x >= p) res.x -= p;
		return res;
	}
	FiniteField operator - (const FiniteField& rhs) const {
		T p = mod().get();
		FiniteField res;
		res.x = x - rhs.x;
		if (res.x < 0) res.x += p;
		return res;
	}
	template<class G> FiniteField operator *= (const G& y) {
		T p = mod().get();
		x = mul()(x, normalize(y), p);
		return *this;
	}
	template<class G> FiniteField operator /= (const G& y) {
		T p = mod().get();
		x = dvd()(x, normalize(y), p);
		return *this;
	}
	FiniteField operator *= (const FiniteField& rhs) {
		T p = mod().get();
		x = mul()(x, rhs.x, p);
		return *this;
	}
	FiniteField operator /= (const FiniteField& rhs) {
		T p = mod().get();
		x = dvd()(x, rhs.x, p);
		return *this;
	}
	template<class G> FiniteField operator * (const G& y) const {
		T p = mod().get();
		FiniteField res;
		res.x = mul()(x, res.normalize(y), p);
		return res;
	}
	template<class G> FiniteField operator / (const G& y) const {
		T p = mod().get();
		FiniteField res;
		res.x = dvd()(x, res.normalize(y), p);
		return res;
	}
	FiniteField operator * (const FiniteField& rhs) const {
		T p = mod().get();
		FiniteField res;
		res.x = mul()(x, rhs.x, p);
		return res;
	}
	FiniteField operator / (const FiniteField& rhs) const {
		T p = mod().get();
		FiniteField res;
		res.x = dvd()(x, rhs.x, p);
		return res;
	}
	template<class G> friend FiniteField operator * (const G& y, const FiniteField& rhs) {
		FiniteField res;
		res.x = res.normalize(y);
		return res * rhs;
	}
	template<class G> friend FiniteField operator / (const G& y, const FiniteField& rhs) {
		FiniteField res;
		res.x = res.normalize(y);
		return res / rhs;
	}
	template<class G> FiniteField operator ^= (G k) {
		T p = mod().get();
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
		return *this;
	}
	template<class G> FiniteField operator ^ (G k) const {
		T p = mod().get();
		if (k == 0) return 1;
		T r = x, t = x; k--;
		while (k > 0) {
			if (k & 1) r = mul()(r, t, p);
			t = mul()(t, t, p);
			k >>= 1;
		}
		return r;
	}
	friend istream& operator >> (istream& is, FiniteField& rhs) {
		is >> rhs.x;
		rhs.x = rhs.normalize(rhs.x);
		return is;
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
template<class T> class mod {
	public:
	T get() {
		return (T) 1e9 + 7;
	}
};
typedef FiniteField<int, mul<int>, dvd<int>, mod<int> > FF;

const int maxn = 1e5 + 5;
long long f, w, h;
FF fac[maxn];
FF ifac[maxn];

FF binom(long long a, long long b) {
	if (a < 0 || a > b) return 0;
	if (!a || a == b) return 1;
	return fac[b] * ifac[a] * ifac[b - a];
}

FF ff(long long k, long long n) {
	if (!k && !n) return 1;
	return binom(k - 1, n - 1);
}

void solve() {
	fac[0] = ifac[0] = 1; FOR(i, 1, maxn) fac[i] = fac[i - 1] * i, ifac[i] = 1 / fac[i];
	cin >> f >> w >> h;
	FF ans = 0, rem = 0;
	FOR(d, 0, maxn - 1) {
		ans += ff(d, f) * ff(d + 1, w - h * (d + 1));
		ans += ff(d + 1, f) * ff(d, w - h * d);
		ans += 2 * ff(d, f) * ff(d, w - h * d);
		rem += ff(d, f) * ff(d + 1, w);
		rem += ff(d + 1, f) * ff(d, w);
		rem += 2 * ff(d, f) * ff(d, w);
	}
	cout << ans / rem << "\n";
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
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
	template<class G> T normalize(G x) {
		if (x >= 0 && x < p) return x;
		x %= p;
		if (x < 0) x += p;
		else if (x >= p) x -= p;
		return x;
	}
	FiniteField() {
		x = 0;
	}
	template<class G> FiniteField(const G& y) {
		x = normalize(y);
	}
	FiniteField(const FiniteField& rhs) {
		x = rhs.x;
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
	template<class G> FiniteField operator += (const G& y) {
		if ((x += normalize(y)) >= p) x -= p;
		return *this;
	}
	template<class G> FiniteField operator -= (const G& y) {
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
	template<class G> FiniteField operator *= (const G& y) {
		x = mul()(x, normalize(y), p);
		return *this;
	}
	template<class G> FiniteField operator /= (const G& y) {
		x = dvd()(x, normalize(y), p);
		return *this;
	}
	template<class G> FiniteField operator * (const G& y) const {
		FiniteField res;
		res.x = mul()(x, res.normalize(y), p);
		return res;
	}
	template<class G> FiniteField operator / (const G& y) const {
		FiniteField res;
		res.x = dvd()(x, res.normalize(y), p);
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
		if (k == 0) return 1;
		T r = x, t = x; k--;
		while (k > 0) {
			if (k & 1) r = mul()(r, t, p);
			t = mul()(t, t, p);
			k >>= 1;
		}
		return r;
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

const int maxn = 1000000 + 10;
const int maxk = 2000 + 10;
const int magic = 22;
int n, m, k, s;
int a[maxk];
int b[maxk];
FF fac[maxn];
FF ifac[maxn];
FF f[maxk][magic];

FF binom(int a, int b) {
	if (!a || a == b) return FF(1);
	return fac[b] * ifac[a] * ifac[b - a];
}

void solve() {
	fac[0] = 1; FOR(i, 1, maxn) fac[i] = fac[i - 1] * i;
	FOR(i, 0, maxn) ifac[i] = 1 / fac[i];
	cin >> n >> m >> k >> s;
	vii vx;
	int tot = 0;
	FOR(i, 0, k) {
		cin >> a[i] >> b[i];
		if (!a[i] && !b[i]) {
			tot++;
		}
		else if (a[i] == n && b[i] == m) {
			tot++;
		}
		else {
			vx.pb(mp(a[i], b[i]));
		}
	}
	vx.pb(mp(1, 1)), vx.pb(mp(n, m));
	sort(all(vx));
	f[0][0] = 1;
	FOR(i, 1, sz(vx)) {
		int u = vx[i].fi;
		int v = vx[i].se;
		f[i][0] = binom(u - 1, u + v - 2);
		FOR(k, 1, magic) {
			FOR(j, 1, i) {
				int p = vx[i].fi - vx[j].fi;
				int q = vx[i].se - vx[j].se;
				if (p >= 0 && q >= 0) {
					f[i][k] += f[j][k - 1] * binom(p, p + q);
					
				}
			}
		}
		FOR(k, 0, magic - 1) {
			f[i][k] -= f[i][k + 1];
		}
	}
	FF ans = 0;
	int t = sz(vx);
	FOR(i, 0, magic) {
		FF k = f[t - 1][i];
		int tmp = s;
		FOR(it, 0, i + tot) tmp = (tmp + 1) / 2;
		ans += tmp * k;
	}
	ans = ans / binom(n - 1, n + m - 2);
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
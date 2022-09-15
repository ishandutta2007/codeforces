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

typedef long double T;
const T oo = (T) 1e18;
struct DynamicConvexhullTrick {
	struct Line {
		T a, b;
		Line(T a = 0, T b = 0) : a(a), b(b) {}
		bool operator < (const Line& rhs) const {
			return make_pair(-a, b) < make_pair(-rhs.a, rhs.b);
		}
		bool operator == (const Line& rhs) const {
			return make_pair(a, b) == make_pair(rhs.a, rhs.b);
		}
		bool operator != (const Line& rhs) const {
			return make_pair(a, b) != make_pair(rhs.a, rhs.b);
		}
	};
	long double intersect(Line ln1, Line ln2) {
		return (long double) (ln2.b - ln1.b) / (ln1.a - ln2.a);
	}
	int bad(Line ln1, Line ln2, Line ln3) {
		return (long double) (ln1.a - ln2.a) * (ln2.b - ln3.b) >= (long double) (ln2.a - ln3.a) * (ln1.b - ln2.b);
	}
	set<Line> hull;
	void add(T a, T b) {
		Line ln(a, b);
		if (hull.find(ln) != hull.end()) return;
		hull.insert(ln);
		set<Line>::iterator it = hull.find(ln);
		if (it == hull.begin()) {
		}
		else {
			Line prv = *(--it); it++;
			if (prv.a == ln.a) {
				hull.erase(ln);
				return;
			}
			if (*it != *hull.rbegin()) {
				Line nxt = *(++it); it--;
				if (bad(prv, ln, nxt)) {
					hull.erase(ln);
					return;
				}
			}
		}
		Line u, v;
		if (it != hull.begin()) {
			v = *(--it);
			while (it != hull.begin()) {
				u = *(--it);
				if (bad(u, v, ln)) {
					hull.erase(v); it = hull.find(v = u);
				}
				else {
					it++;
					break;
				}
			}
			it++;
		}
		if (*it != *hull.rbegin()) {
			u = *(++it);
			while (*it != *hull.rbegin()) {
				v = *(++it);
				if (ln.a == u.a || bad(ln, u, v)) {
					hull.erase(u); it = hull.find(u = v);
				}
				else {
					it--;
					break;
				}
			}
			it--;
		}
	}
	T query(T m, T t) {
		if (sz(hull) == 1) return 0;
		set<Line>::iterator it = hull.lower_bound(Line(m / t, 0));
		if (it->a == 0) {
			it--;
			T x = -it->b / it->a;
			T y = 0;
			return m * x + t * y;
		}
		if (it == hull.begin()) {
			T x = 0;
			T y = -it->b;
			return m * x + t * y;
		}
		Line up = *(it--);
		Line dn = *it;
		T x = intersect(up, dn);
		T y = -(up.a * x + up.b);
		return m * x + t * y;
	}
} dcht;

void solve() {
	dcht.add(0, 0);
	int q; long long m;
	cin >> q >> m;
	int lst = 0;
	FOR(i, 1, q + 1) {
		int op, a, b; cin >> op >> a >> b;
		if (op == 1) {
			int x = (a + lst) % int(1e6) + 1;
			int y = (b + lst) % int(1e6) + 1;
			dcht.add(y, -x);
		}
		else if (op == 2) {
			int t = (a + lst) % int(1e6) + 1;
			int h = (b + lst) % int(1e6) + 1;
			if (sign(dcht.query(m, t), h) >= 0) {
				cout << "YES\n";
				lst = i;
			}
			else {
				cout << "NO\n";
			}
		}
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
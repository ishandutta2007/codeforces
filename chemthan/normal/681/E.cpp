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

#define RL long double
#define EPS 1e-12
struct PT {
	RL x, y;
	PT() {}
	PT(RL x, RL y) : x(x), y(y) {}
	PT(const PT& p) : x(p.x), y(p.y) {}
	bool operator < (const PT& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
	bool operator == (const PT& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
	PT operator + (const PT& p) const {return PT(x + p.x, y + p.y);}
	PT operator - (const PT& p) const {return PT(x - p.x, y - p.y);}
	PT operator * (RL c) const {return PT(x * c, y * c);}
	PT operator / (RL c) const {return PT(x / c, y / c);}
};
RL cross(PT p, PT q) {return p.x * q.y - p.y * q.x;}
RL area(PT a, PT b, PT c) {return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;}
RL area2(PT a, PT b, PT c) {return cross(a, b) + cross(b, c) + cross(c, a);}
RL dot(PT p, PT q) {return p.x * q.x + p.y * q.y;}
RL dist(PT p, PT q) {return sqrt(dot(p - q, p - q));}
RL dist2(PT p, PT q) {return dot(p - q, p - q);}
PT RotateCCW90(PT p) {return PT(-p.y, p.x);}
PT RotateCW90(PT p) {return PT(p.y, -p.x);}
PT RotateCCW(PT p, RL t) {return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));}
int rlcmp(RL x) {return x < -EPS ? -1 : x > EPS;}
int rlcmp(RL x, RL y) {return rlcmp(x - y);}
ostream& operator << (ostream& os, const PT& p) {
  os << "(" << p.x << "," << p.y << ")"; 
}
vector<PT> CircleCircleIntersection(PT a, PT b, RL r, RL R) {
	vector<PT> res;
	RL d = sqrt(dist2(a, b));
	if (d > r + R - EPS || d + min(r, R) < max(r, R) + EPS) return res;
	RL x = (d * d - R * R + r * r) / (2 * d);
	RL y = sqrt(r * r - x * x);
	PT v = (b - a) / d;
	res.push_back(a + v * x + RotateCCW90(v) * y);
	res.push_back(a + v * x - RotateCCW90(v) * y);
	return res;
}
RL Angle(PT a) {
	RL PI = acos((RL) -1);
	if (a.x == 0) {
		if (a.y > 0) return PI / 2;
		return 3 * PI / 2;
	}
	if (a.y == 0) {
		if (a.x > 0) return 0;
		return PI;
	}
	RL res = atan(a.y / a.x);
	if (a.x < 0) return res + PI;
	if (a.y < 0) return res + 2 * PI;
	return res;
}

const int maxn = 100010;
int x, y, v, t;
int n;
int a[maxn];
int b[maxn];
int r[maxn];

ld sqr(ld x) {
	return x * x;
}

void solve() {
	cin>>x>>y>>v>>t>>n;
	ld z = (ld) v * t;
	vector<pair<ld, ld> > vd;
	FOR(i, 0, n) {
		cin>>a[i]>>b[i]>>r[i];
		a[i] -= x; b[i] -= y;
		if (sqrt(sqr(a[i]) + sqr(b[i])) < r[i] + EPS) {
			cout<<prec(9)<<1.0<<"\n";
			return;
		}
		if (sqrt(sqr(a[i]) + sqr(b[i]) - sqr(r[i])) < z + EPS) {
			ld alpha = Angle(PT(a[i], b[i]));
			ld beta = asin(r[i] / sqrt(sqr(a[i]) + sqr(b[i])));
			ld alpha1 = alpha - beta;
			ld alpha2 = alpha + beta;
			if (alpha1 < 0) {
				vd.pb(mp(alpha1 + 2 * PI, 2 * PI));
				alpha1 = 0;
			}
			if (alpha2 > 2 * PI) {
				vd.pb(mp(0, alpha2 - 2 * PI));
				alpha2 = 2 * PI;
			}
			vd.pb(mp(alpha1, alpha2));
		}
		else {
			vector<PT> res = CircleCircleIntersection(PT(0, 0), PT(a[i], b[i]), z, r[i]);
			if (sz(res) == 2) {
				ld alpha1 = Angle(res[0]);
				ld alpha2 = Angle(res[1]);
				if (alpha1 > alpha2) swap(alpha1, alpha2);
				ld median = (alpha1 + alpha2) / 2;
				ld u = z * cos(median);
				ld v = z * sin(median);
				if (sqrt(sqr(u - a[i]) + sqr(v - b[i])) < r[i] + EPS) {
					vd.pb(mp(alpha1, alpha2));
				}
				else {
					vd.pb(mp(0, alpha1));
					vd.pb(mp(alpha2, 2 * PI));
				}
			}
		}
	}
	sort(all(vd));
	ld ans = 0, dmax = 0;
	FOR(i, 0, sz(vd)) {
		if (vd[i].fi > dmax) {
			ans += vd[i].fi - dmax;
		}
		chkmax(dmax, vd[i].se);
	}
	ans += 2 * PI - dmax;
	cout<<prec(9)<<1.0 - ans / 2 / PI<<"\n";
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
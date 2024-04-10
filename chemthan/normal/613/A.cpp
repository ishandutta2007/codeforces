#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

struct Point {
	double x, y;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	Point(const Point& p) : x(p.x), y(p.y) {}
	bool operator < (const Point& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
	bool operator == (const Point& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
	Point operator + (const Point& p) const {return Point(x + p.x, y + p.y);}
	Point operator - (const Point& p) const {return Point(x - p.x, y - p.y);}
	Point operator * (double c) const {return Point(x * c, y * c);}
	Point operator / (double c) const {return Point(x / c, y / c);}
};

double cross(Point p, Point q) {return p.x * q.y - p.y * q.x;}
double area(Point a, Point b, Point c) {return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;}
double area2(Point a, Point b, Point c) {return cross(a, b) + cross(b, c) + cross(c, a);}
double dot(Point p, Point q) {return p.x * q.x + p.y * q.y;}
double dist(Point p, Point q) {return sqrt(dot(p - q, p - q));}
double dist2(Point p, Point q) {return dot(p - q, p - q);}

Point RotateCCW90(Point p) {return Point(-p.y, p.x);}
Point RotateCW90(Point p) {return Point(p.y, -p.x);}
Point RotateCCW(Point p, double t) {return Point(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));}

Point ProjectPointLine(Point a, Point b, Point c) {
	return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
Point ProjectPointSegment(Point a, Point b, Point c) {
	double r = dot(b - a, b - a);
	if (fabs(r) < EPS) return a;
	r = dot(c - a, b - a) / r;
	if (r < 0) return a;
	if (r > 1) return b;
	return a + (b - a) * r;
}
double DistancePointSegment(Point a, Point b, Point c) {
	return dist2(c, ProjectPointSegment(a, b, c));
}

#define PT Point

int n, p, q;
vector<PT> vp;

void solve() {
	scanf("%d%d%d", &n, &p, &q);
	ld dmin = LINF, dmax = 0;
	FOR(i, 0, n) {
		int u, v; scanf("%d%d", &u, &v);
		vp.pb(PT(u, v));
		ld d = (ld) (p - u) * (p - u) + (ld) (q - v) * (q - v);
		dmin = min(dmin, d);
		dmax = max(dmax, d);
	}
	FOR(i, 0, n) {
		PT u = vp[i];
		PT v = vp[(i + 1) % n];
		dmin = min(dmin, (ld) DistancePointSegment(u, v, PT(p, q)));
	}
	cout<<prec(9)<<PI * (dmax - dmin);
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}
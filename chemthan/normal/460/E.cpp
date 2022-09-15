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

#define REMOVE_REDUNDANT
#ifdef REMOVE_REDUNDANT
bool between(const Point& a, const Point& b, const Point& c) {
	return (fabs(area2(a, b, c)) < EPS && (a.x - b.x) * (c.x - b.x) <= 0 && (a.y - b.y) * (c.y - b.y) <= 0);
}
#endif
void ConvexHull(vector<Point>& pts) {
	sort(pts.begin(), pts.end());
	pts.erase(unique(pts.begin(), pts.end()), pts.end());
	vector<Point> up, dn;
	for (int i = 0; i < pts.size(); i++) {
		while (up.size() > 1 && area2(up[up.size() - 2], up.back(), pts[i]) >= 0) up.pop_back();
		while (dn.size() > 1 && area2(dn[dn.size() - 2], dn.back(), pts[i]) <= 0) dn.pop_back();
		up.push_back(pts[i]);
		dn.push_back(pts[i]);
	}
	pts = dn;
	for (int i = up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
#ifdef REMOVE_REDUNDANT
	if (pts.size() <= 2) return;
	dn.clear();
	dn.push_back(pts[0]);
	dn.push_back(pts[1]);
	for (int i = 2; i < pts.size(); i++) {
		if (between(dn[dn.size() - 2], dn[dn.size() - 1], pts[i])) dn.pop_back();
		dn.push_back(pts[i]);
	}
	if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
		dn[0] = dn.back();
		dn.pop_back();
	}
	pts = dn;
#endif
}
#define PT Point

int n, r;
int ans;
vii res;

void go(vii& cur, int tot, vii& vp, int n, int k) {
	if (n == 0) {
		if (ans <= tot) {
			ans = tot;
			res = cur;
		}
		return;
	}
	FOR(i, k, sz(vp)) {
		int t = tot;
		FOR(j, 0, sz(cur)) t += (vp[i].fi - cur[j].fi) * (vp[i].fi - cur[j].fi) + (vp[i].se - cur[j].se) * (vp[i].se - cur[j].se);
		cur.pb(vp[i]);
		go(cur, t, vp, n - 1, i);
		cur.pop_back();
	}
}

void solve() {
	scanf("%d%d", &n, &r);
	vector<PT> vp;
	FOR(i, -r, r + 1) FOR(j, -r, r + 1) {
		if (i * i + j * j <= r * r) vp.pb(PT(i, j));
	}
	ConvexHull(vp);
	vii _vp; FOR(i, 0, sz(vp)) _vp.pb(mp(vp[i].x, vp[i].y));
	vii cur;
	go(cur, 0, _vp, n, 0);
	printf("%d\n", ans);
	FOR(i, 0, sz(res)) printf("%d %d\n", res[i].fi, res[i].se);
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
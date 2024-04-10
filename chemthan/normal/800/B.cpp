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
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "-----\n";

#define RL double
#define EPS 1e-9
struct PT {
	RL x, y;
	PT() : x(0), y(0) {}
	PT(RL x, RL y) : x(x), y(y) {}
	PT(const PT& p) : x(p.x), y(p.y) {}
	int operator < (const PT& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
	int operator == (const PT& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
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
int sign(RL x) {return x < -EPS ? -1 : x > EPS;}
int sign(RL x, RL y) {return sign(x - y);}
ostream& operator << (ostream& os, const PT& p) {
	os << "(" << p.x << "," << p.y << ")";
	return os;
}

//Project c on Line(a, b)
PT ProjectPointLine(PT a, PT b, PT c) {
	return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
PT ProjectPointSegment(PT a, PT b, PT c) {
	RL r = dot(b - a, b - a);
	if (fabs(r) < EPS) return a;
	r = dot(c - a, b - a) / r;
	if (r < 0) return a;
	if (r > 1) return b;
	return a + (b - a) * r;
}
RL DistancePointSegment(PT a, PT b, PT c) {
	return dist(c, ProjectPointSegment(a, b, c));
}
//Compute distance between PT (x, y, z) and plane ax + by + cz = d
RL DistancePointPlane(RL x, RL y, RL z, RL a, RL b, RL c, RL d) {
	return fabs(a * x + b * y + c * z - d) / sqrt(a * a + b * b + c * c);
}
//Determine if lines from a to b and c to d are parallel or collinear
int LinesParallel(PT a, PT b, PT c, PT d) {
	return fabs(cross(b - a, c - d)) < EPS;
}
int LinesCollinear(PT a, PT b, PT c, PT d) {
	return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS && fabs(cross(c - d, c - a)) < EPS;
}
//Determine if line segment from a to b intersects with line segment from c to d
int SegmentsIntersect(PT a, PT b, PT c, PT d) {
	if (LinesCollinear(a, b, c, d)) {
		if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS || dist2(b, d) < EPS) return 1;
		if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0) return 0;
		return 1;
	}
	if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return 0;
	if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return 0;
	return 1;
}
//Compute intersection of line passing through a and b
//with line passing through c and d, assuming that unique
//intersection exists; for segment intersection, check if
//segments intersect first
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
	b = b - a; d = c - d; c = c - a;
	return a + b * cross(c, d) / cross(b, d);
}
//Compute center of circle given three points
PT ComputeCircleCenter(PT a, PT b, PT c) {
	b = (a + b) / 2;
	c = (a + c) / 2;
	return ComputeLineIntersection(b, b + RotateCW90(a - b), c, c + RotateCW90(a - c));
}
//Determine if point is in a possibly non-convex polygon
//returns 1 for strictly interior points, 0 for
//strictly exterior points, and 0 or 1 for the remaining points.
int PointInPolygonSlow(const vector<PT>& p, PT q) {
	int c = 0;
	for (int i = 0; i < p.size(); i++) {
		int j = (i + 1) % p.size();
		if ((p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) && q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y)) c = !c;
	}
	return c;
}
//Strictly inside convex Polygon
#define Det(a, b, c) ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x))
int PointInPolygon(vector<PT>& p, PT q) {
	int a = 1, b = p.size() - 1, c;
	if (Det(p[0], p[a], p[b]) > 0) swap(a, b);
	//Allow on edge --> if (Det... > 0 || Det ... < 0)
	if (Det(p[0], p[a], q) >= 0 || Det(p[0], p[b], q) <= 0) return 0;
	while(abs(a - b) > 1) {
		c = (a + b) / 2;
		if (Det(p[0], p[c], q) > 0) b = c; else a = c;
	}
	//Alow on edge --> return Det... <= 0
	return Det(p[a], p[b], q) < 0;
}
//Determine if point is on the boundary of a polygon
int PointOnPolygon(const vector<PT>& p, PT q) {
	for (int i = 0; i < p.size(); i++) if (dist2(ProjectPointSegment(p[i], p[(i + 1) % p.size()], q), q) < EPS) return 1;
	return 0;
}
//Compute intersection of line through points a and b with circle centered at c with radius r > 0
vector<PT> CircleLineIntersection(PT a, PT b, PT c, RL r) {
	vector<PT> res;
	b = b - a; a = a - c;
	RL A = dot(b, b);
	RL B = dot(a, b);
	RL C = dot(a, a) - r * r;
	RL D = B * B - A * C;
	if (D < -EPS) return res;
	res.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
	if (D > EPS) res.push_back(c + a + b * (-B - sqrt(D)) / A);
	return res;
}
//Compute intersection of circle centered at a with radius r with circle centered at b with radius R
vector<PT> CircleCircleIntersection(PT a, PT b, RL r, RL R) {
	vector<PT> res;
	RL d = sqrt(dist2(a, b));
	if (d > r + R || d + min(r, R) < max(r, R)) return res;
	RL x = (d * d - R * R + r * r) / (2 * d);
	RL y = sqrt(r * r - x * x);
	PT v = (b - a) / d;
	res.push_back(a + v * x + RotateCCW90(v) * y);
	if (y > 0) res.push_back(a + v * x - RotateCCW90(v) * y);
	return res;
}
//This code computes the area or centroid of a (possibly nonconvex)
//polygon, assuming that the coordinates are listed in a clockwise or
//counterclockwise fashion.  Note that the centroid is often known as
//the "center of gravity" or "center of mass".
RL ComputeSignedArea(const vector<PT>& p) {
	RL area = 0;
	for(int i = 0; i < p.size(); i++) {
		int j = (i + 1) % p.size();
		area += p[i].x * p[j].y - p[j].x * p[i].y;
	}
	return area / 2.0;
}
RL ComputeArea(const vector<PT>& p) {
	return fabs(ComputeSignedArea(p));
}
PT ComputeCentroid(const vector<PT>& p) {
	PT c(0, 0);
	RL scale = 6.0 * ComputeSignedArea(p);
	for (int i = 0; i < p.size(); i++) {
		int j = (i + 1) % p.size();
		c = c + (p[i] + p[j]) * (p[i].x * p[j].y - p[j].x * p[i].y);
	}
	return c / scale;
}
//Tests whether or not a given polygon (in CW or CCW order) is simple
int IsSimple(const vector<PT>& p) {
	for (int i = 0; i < p.size(); i++) {
		for (int k = i + 1; k < p.size(); k++) {
			int j = (i + 1) % p.size();
			int l = (k + 1) % p.size();
			if (i == l || j == k) continue;
			if (SegmentsIntersect(p[i], p[j], p[k], p[l])) return 0;
		}
	}
	return 1;
}
RL Angle(PT a) {
	RL PI = acos((RL) - 1);
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

const int maxn = 1e3 + 5;
int n;
PT p[maxn];

void solve() {
	cin >> n;
	FOR(i, 0, n) cin >> p[i].x >> p[i].y;
	RL ans = 1e18;
	FOR(i, 0, n) FOR(j, i + 1, n) {
		int ar[] = {(i + n - 1) % n, (i + 1) % n, (j + n - 1) % n, (j + 1) % n};
		FOR(k, 0, 4) if (ar[k] != i && ar[k] != j) {
			int l = ar[k];
			PT q = ProjectPointLine(p[i], p[j], p[l]);
			chkmin(ans, dist(p[l], q) / 2);
		}
	}
	cout << prec(9) << ans << "\n";
}

int main() {
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
    }
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
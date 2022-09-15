#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define sz(a) (int)(a).size()
#define rep(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define frep(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int inf = 1e9 + 7;
const ll linf  = 1ll * inf * inf;
const int N = 100000 + 7;
const int M = 30;
const int multipleTest = 0;
const double pi = acos(-1);

#define double double
#define EPS 1e-9
struct PT {
	double x, y;
	PT() : x(0), y(0) {}
	PT(double x, double y) : x(x), y(y) {}
	PT(const PT& p) : x(p.x), y(p.y) {}
	int operator < (const PT& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
	int operator == (const PT& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
	PT operator + (const PT& p) const {return PT(x + p.x, y + p.y);}
	PT operator - (const PT& p) const {return PT(x - p.x, y - p.y);}
	PT operator * (double c) const {return PT(x * c, y * c);}
	PT operator / (double c) const {return PT(x / c, y / c);}
};
double cross(PT p, PT q) {return p.x * q.y - p.y * q.x;}
double area(PT a, PT b, PT c) {return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;}
double area2(PT a, PT b, PT c) {return cross(a, b) + cross(b, c) + cross(c, a);}
double dot(PT p, PT q) {return p.x * q.x + p.y * q.y;}
double dist(PT p, PT q) {return sqrt(dot(p - q, p - q));}
double dist2(PT p, PT q) {return dot(p - q, p - q);}
PT RotateCCW90(PT p) {return PT(-p.y, p.x);}
PT RotateCW90(PT p) {return PT(p.y, -p.x);}
PT RotateCCW(PT p, double t) {return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));}
int sign(double x) {return x < -EPS ? -1 : x > EPS;}
int sign(double x, double y) {return sign(x - y);}
ostream& operator << (ostream& os, const PT& p) {
	os << "(" << p.x << "," << p.y << ")";
	return os;
}

//Project c on Line(a, b)
PT ProjectPointLine(PT a, PT b, PT c) {
	return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
PT ProjectPointSegment(PT a, PT b, PT c) {
	double r = dot(b - a, b - a);
	if (fabs(r) < EPS) return a;
	r = dot(c - a, b - a) / r;
	if (r < 0) return a;
	if (r > 1) return b;
	return a + (b - a) * r;
}
double DistancePointSegment(PT a, PT b, PT c) {
	return dist(c, ProjectPointSegment(a, b, c));
}
//Compute distance between PT (x, y, z) and plane ax + by + cz = d
double DistancePointPlane(double x, double y, double z, double a, double b, double c, double d) {
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
vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r) {
	vector<PT> res;
	b = b - a; a = a - c;
	double A = dot(b, b);
	double B = dot(a, b);
	double C = dot(a, a) - r * r;
	double D = B * B - A * C;
	if (D < -EPS) return res;
	res.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
	if (D > EPS) res.push_back(c + a + b * (-B - sqrt(D)) / A);
	return res;
}
//Compute intersection of circle centered at a with radius r with circle centered at b with radius R
vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R) {
	vector<PT> res;
	double d = sqrt(dist2(a, b));
	if (d > r + R || d + min(r, R) < max(r, R)) return res;
	double x = (d * d - R * R + r * r) / (2 * d);
	double y = sqrt(r * r - x * x);
	PT v = (b - a) / d;
	res.push_back(a + v * x + RotateCCW90(v) * y);
	if (y > 0) res.push_back(a + v * x - RotateCCW90(v) * y);
	return res;
}
//This code computes the area or centroid of a (possibly nonconvex)
//polygon, assuming that the coordinates are listed in a clockwise or
//counterclockwise fashion.  Note that the centroid is often known as
//the "center of gravity" or "center of mass".
double ComputeSignedArea(const vector<PT>& p) {
	double area = 0;
	for(int i = 0; i < p.size(); i++) {
		int j = (i + 1) % p.size();
		area += p[i].x * p[j].y - p[j].x * p[i].y;
	}
	return area / 2.0;
}
double ComputeArea(const vector<PT>& p) {
	return fabs(ComputeSignedArea(p));
}
PT ComputeCentroid(const vector<PT>& p) {
	PT c(0, 0);
	double scale = 6.0 * ComputeSignedArea(p);
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
double Angle(PT a) {
	double PI = acos((double) - 1);
	if (a.x == 0) {
		if (a.y > 0) return PI / 2;
		return 3 * PI / 2;
	}
	if (a.y == 0) {
		if (a.x > 0) return 0;
		return PI;
	}
	double res = atan(a.y / a.x);
	if (a.x < 0) return res + PI;
	if (a.y < 0) return res + 2 * PI;
	return res;
}

int n, m;
PT bs[N], shp[N];

void solve() {
	cin >> n >> m;
	if (n != m) {
		puts("No");return;
	}
	rep(i, 0, n) cin >> bs[i].x >> bs[i].y;
	rep(i, 0, n) cin >> shp[i].x >> shp[i].y;
	
	vector<int> p;
	rep(i, 0, n) p.push_back(i);
	do{
		bool check = true;
		rep(i, 0, n) rep(j, i + 1, n) {
			if (::SegmentsIntersect(bs[i], shp[p[i]], bs[j], shp[p[j]])) {
				check = false;
				break;
			}
		}
		if (check) {
			puts("Yes");
			return;
		}
	}while (next_permutation(p.begin(), p.end()));
	puts("No");
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin);
	//    freopen("out.txt", "w", stdout);
#endif
	int Test = 1;
	if (multipleTest) {
		cin >> Test;
	}
	for(int i = 0; i < Test; ++i) {
//		printf("Case #%d: ", i + 1);
		solve();
	}
#ifdef _LOCAL_
	cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
#endif
}
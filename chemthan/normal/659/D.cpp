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
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcount(n)
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
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

#define RL double
#define EPS 1e-9
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
int PointInPolygon(const vector<PT>& p, PT q) {
	int c = 0;
	for (int i = 0; i < p.size(); i++) {
		int j = (i + 1) % p.size();
		if ((p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) && q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y)) c = !c;
	}
	return c;
}

const int maxn = 1010;
int n;
PT pt[maxn];

void solve() {
	cin>>n;
	vector<PT> vp;
	FOR(i, 0, n) cin>>pt[i].x>>pt[i].y, vp.pb(pt[i]);
	int ans = 0;
	FOR(i, 0, n) {
		PT nxt = pt[(i + 1) % n];
		if (pt[i].x == nxt.x) {
			if (pt[i].y < nxt.y) {
				nxt.y += 0.5;
			}
			else {
				nxt.y -= 0.5;
			}
		}
		else {
			if (pt[i].x < nxt.x) {
				nxt.x += 0.5;
			}
			else {
				nxt.x -= 0.5;
			}
		}
		if (PointInPolygon(vp, nxt)) {
			ans++;
		}
	}
	cout<<ans<<"\n";
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
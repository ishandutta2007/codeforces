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
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

#define T long double
struct PT {
	T x, y;
	PT() {}
	PT(T x, T y) : x(x), y(y) {}
	PT(const PT& p) : x(p.x), y(p.y) {}
	bool operator < (const PT& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
	bool operator == (const PT& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
	PT operator + (const PT& p) const {return PT(x + p.x, y + p.y);}
	PT operator - (const PT& p) const {return PT(x - p.x, y - p.y);}
	PT operator * (T c) const {return PT(x * c, y * c);}
	PT operator / (T c) const {return PT(x / c, y / c);}
};

T cross(PT p, PT q) {return p.x * q.y - p.y * q.x;}
T area(PT a, PT b, PT c) {return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;}
T area2(PT a, PT b, PT c) {return cross(a, b) + cross(b, c) + cross(c, a);}
T dot(PT p, PT q) {return p.x * q.x + p.y * q.y;}
T dist(PT p, PT q) {return sqrt(dot(p - q, p - q));}
T dist2(PT p, PT q) {return dot(p - q, p - q);}

PT RotateCCW90(PT p) {return PT(-p.y, p.x);}
PT RotateCW90(PT p) {return PT(p.y, -p.x);}
PT RotateCCW(PT p, T t) {return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));}

PT ProjectPointLine(PT a, PT b, PT c) {
	return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
PT ProjectPointSegment(PT a, PT b, PT c) {
	T r = dot(b - a, b - a);
	if (fabs(r) < EPS) return a;
	r = dot(c - a, b - a) / r;
	if (r < 0) return a;
	if (r > 1) return b;
	return a + (b - a) * r;
}
T DistancePointSegment(PT a, PT b, PT c) {
	return dist(c, ProjectPointSegment(a, b, c));
}
//Compute distance between PT (x, y, z) and plane ax + by + cz = d
T DistancePointPlane(T x, T y, T z, T a, T b, T c, T d) {
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
int PointInPolygon(const vector<PT>& p, PT q) {
	int c = 0;
	for (int i = 0; i < p.size(); i++) {
		int j = (i + 1) % p.size();
		if ((p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) && q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y)) c = !c;
	}
	return c;
}
int PointOnPolygon(const vector<PT>& p, PT q) {
	for (int i = 0; i < p.size(); i++) if (dist2(ProjectPointSegment(p[i], p[(i + 1) % p.size()], q), q) < EPS) return 1;
	return 0;
}

const int maxn = 210;
int n;
PT pt[maxn];
int f[maxn][maxn];
int g[maxn][maxn];

int calc(int u, int v) {
	if (u + 2 == v) {
		return abs(area2(pt[u], pt[u + 1], pt[v])) > EPS;
	}
	int& res = f[u][v];
	if (~res) return res;
	res = 0;
	FOR(i, u + 1, v) {
		if (!g[u][i] && !g[v][i] && abs(area2(pt[u], pt[i], pt[v])) > EPS) {
			int r1 = 1, r2 = 1;
			if (i != u + 1) r1 = calc(u, i);
			if (i != v - 1) r2 = calc(i, v);
			addmod(res, (ll) r1 * r2 % MOD);
		}
	}
	return res;
}

void solve() {
	cin>>n;
	vector<PT> vp;
	FOR(i, 0, n) {
		cin>>pt[i].x>>pt[i].y;
		vp.pb(pt[i]);
	}
	FOR(i, 0, n) FOR(j, i + 1, n) {
		FOR(k, 0, n) {
			int l = (k + 1) % n;
			if (i != k && i != l && j != k && j != l) {
				if (SegmentsIntersect(pt[i], pt[j], pt[k], pt[l])) {
					g[i][j] = g[j][i] = 1;
					break;
				}
			}
		}
		if (!PointOnPolygon(vp, (pt[i] + pt[j]) / 2) && !PointInPolygon(vp, (pt[i] + pt[j]) / 2)) {
			g[i][j] = g[j][i] = 1;
		}
	}
	ms(f, -1);
	cout<<calc(0, n - 1);
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
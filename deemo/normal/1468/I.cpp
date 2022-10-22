#include<bits/stdc++.h>
//#define _USE_MATH_DEFINES
using namespace std;
#define M_PI 3.14
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
#define F first
#define S second
 
const int MOD = 1e9 + 7;//XXX
//const int C = 26;//XXX
 
void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}
 
int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}
 
int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}
 


/*
	---------------------------------------- Points ----------------------------------------
*/

typedef double T;
typedef complex<T> pt;
#define x real()
#define y imag()

// abs(p) = sqrt(x*x + y*y)

T sq(pt p) {return p.x*p.x + p.y*p.y;}

pt translate(pt v, pt p) {
	// Translate a point p by a vector v.
	return p+v;
} 

pt scale(pt c, double factor, pt p) {
	// Scale point p by factor around a center c.
	return c + (p-c)*factor;
}

pt rot(pt p, double a) {
	// Rotate point p by an angle a, counterclockwise.
	return p * polar(1.0, a);
}

pt perp(pt p) {
	// Rotate point p by 90 degrees, good for integer coords.
	return {-p.y, p.x};
}

T dot(pt v, pt w) {
	/* 
		v*w = |v|*|w|*cos(angle)
		Check sign of dot product to see if two vectors are going in the same dir.
			Positive if angle < pi/2, neg if >, 0 if = 
	*/
	return v.x*w.x + v.y*w.y;
}

bool isPerp(pt v, pt w) {return dot(v,w) == 0;}

double angle(pt v, pt w) {
	// Angle between two vectors.
	return acos(clamp(dot(v,w) / abs(v) / abs(w), -1.0, 1.0));
}

T cross(pt v, pt w) {
	/*
		v*w = |v|*|w|*sin(angle)
		Order of v, w matters! Angle is the ORIENTED angle between v and w.
			Positive if  0 < angle < pi, neg if -pi < angle < 0, zero if angle = 0 or pi.
	*/
	return v.x*w.y - v.y*w.x;
}

T orient(pt a, pt b, pt c) {
	// I'll go from a to b to c. If turn left to c, positive. Right negative, straight zero.
	return cross(b-a,c-a);
}

double orientedAngle(pt a, pt b, pt c) {
	// Return the oriented angle between ab and ac, going from b to c.
	if (orient(a,b,c) >= 0)
		return angle(b-a, c-a);
	return 2*M_PI - angle(b-a, c-a);
}

bool inAngle(pt a, pt b, pt c, pt p) {
	// Use this to check if p lies in the angle that ab and ac form.
	assert(orient(a,b,c) != 0);
	if (orient(a,b,c) < 0) swap(b,c);
	return orient(a,b,p) >= 0 && orient(a,c,p) <= 0;
}

bool isConvex(vector<pt> p) {
	// To check if a polygon is convex, the orientation of all three consecutive
	// points should be the same.
	bool hasPos=false, hasNeg=false;
	for (int i=0, n=p.size(); i<n; i++) {
		int o = orient(p[i], p[(i+1)%n], p[(i+2)%n]);
		if (o > 0) hasPos = true;
		if (o < 0) hasNeg = true;
	}
	return !(hasPos && hasNeg);
}

bool half(pt p, pt v = {-1.0, 0.0}) { // true if in blue half
	// Modify v if you want a different starting angle.
	assert(p.x != 0 || p.y != 0); // the argument of (0,0) is undefined
	return cross(v,p) < 0 || (cross(v,p) == 0 && dot(v,p) < 0);
}

void polarSort(vector<pt> &v) {
	/*
		This will sort points according to their angle based on the origin.
		If I want to do the same thing but with a point not the origin, I have
		to subtract that point from all other points.
		If I want to add parameters in the sort such as magnitude, just add terms
		to the tuple.
	*/
	sort(v.begin(), v.end(), [](pt v, pt w) {
		return make_tuple(half(v), 0) < make_tuple(half(w), cross(v,w));
	});
}

/*
	---------------------------------------- Lines ----------------------------------------
*/

struct line {
	pt v; T c;
	// From direction vector v and offset c
	line(pt v, T c) : v(v), c(c) {}
	// From equation ax+by=c
	line(T a, T b, T c) : v(b,-a), c(c) {}
	// From points P and Q
	line(pt p, pt q) : v(q-p), c(cross(v,p)) {}

	// - these work with T = int
	T side(pt p);
	double dist(pt p);
	double sqDist(pt p);
	double slope();
	line perpThrough(pt p);
	bool cmpProj(pt p, pt q);
	line translate(pt t);
	// - these require T = double
	line shiftLeft(double dist);
	pt proj(pt p);
	pt refl(pt p);
};

T line::side(pt p) {
	// This says what side of the line a point is.
	// Positive side is on the left (remember the line has orientation).
	return cross(v,p)-c;
}

double line::dist(pt p) {
	// Dist point -> line
	return abs(side(p)) / abs(v);
}

double line::sqDist(pt p) {
	// Dist point -> line squared.
	return side(p)*side(p) / (double)sq(v);
}

double line::slope(){
	return v.y/v.x;
}

line line::perpThrough(pt p) {
	// Line that is perpendicular to this line, and goes through p.
	return {p, p + perp(v)};
}

bool line::cmpProj(pt p, pt q) {
	// Use this if you want to sort points through a line.
	return dot(v,p) < dot(v,q);
}

line line::translate(pt t) {
	// Translate this line by vector t.
	return {v, c + cross(v,t)};
}

line line::shiftLeft(double dist) {
	// Shift this line to the left by dist. Note: you gotta substitute.
	return {v, c + dist*abs(v)};
}

bool inter(line l1, line l2, pt &out) {
	// Check if l1 and l2 intersect.
	T d = cross(l1.v, l2.v);
	if (d == 0) return false;
	out = (l2.v*l1.c - l1.v*l2.c) / d; // requires floating-point coordinates
	return true;
}

pt line::proj(pt p) {
	// Projects a point into a line.
	return p - perp(v)*side(p)/sq(v);
}
pt line::refl(pt p) {
	// This is the point that is the same distance from line as p, but on the other side.
	return p - perp(v)*2.0*side(p)/sq(v);
}

line bisector(line l1, line l2, bool interior) {
	// This returns the line that is between l1 and l2, dividing the angle in 2.
	assert(cross(l1.v, l2.v) != 0); // l1 and l2 cannot be parallel!
	double sign = interior ? 1 : -1;
	return {l2.v/abs(l2.v) + l1.v/abs(l1.v) * sign, l2.c/abs(l2.v) + l1.c/abs(l1.v) * sign};
}

/*
	---------------------------------------- Segments ----------------------------------------
*/

bool inDisk(pt a, pt b, pt p) {
	// Pts a, b are the diameter of a disk, want to know if point p is inside.
	return dot(a-p, b-p) <= 0;
}

bool onSegment(pt a, pt b, pt p) {
	// Check if point p is in the segment formed by [a, b].
	return orient(a,b,p) == 0 && inDisk(a,b,p);
}

bool properInter(pt a, pt b, pt c, pt d, pt &out) {
	// Check if two segments [a, b], [c, d] incercept.
	// The proper interception is an interception that is a single point, but not an endpoint.
	double oa = orient(c,d,a),
	ob = orient(c,d,b),
	oc = orient(a,b,c),
	od = orient(a,b,d);
	// Proper intersection exists iff opposite signs
	if (oa*ob < 0 && oc*od < 0) {
		out = (a*ob - b*oa) / (ob-oa);
		return true;
	}
	return false;
}


// To create sets of points we need a comparison function
struct cmpX {
	bool operator()(const pt &a, const pt &b) const{
		return make_pair(a.x, a.y) < make_pair(b.x, b.y);
	}
};

set<pt,cmpX> inters(pt a, pt b, pt c, pt d) {
	// If |set| = 0, no interception.
	// If |set| = 1, point interception.
	// If |set| = 2, segment interception.
	pt out;
	if (properInter(a,b,c,d,out)) return {out};
	set<pt,cmpX> s;
	if (onSegment(c,d,a)) s.insert(a);
	if (onSegment(c,d,b)) s.insert(b);
	if (onSegment(a,b,c)) s.insert(c);
	if (onSegment(a,b,d)) s.insert(d);
	return s;
}

double segPoint(pt a, pt b, pt p) {
	// Dist of point p to segment [a, b]
	if (a != b) {
		line l(a,b);
		if (l.cmpProj(a,p) && l.cmpProj(p,b)) // if closest to projection
			return l.dist(p); // output distance to line
	}
	return min(abs(p-a), abs(p-b)); // otherwise distance to A or B
}

double segSeg(pt a, pt b, pt c, pt d) {
	// Dist of seg [a, b] to seg [c, d]
	pt dummy;
	if (properInter(a,b,c,d,dummy))
		return 0;
	return min({segPoint(a,b,c), segPoint(a,b,d), segPoint(c,d,a), segPoint(c,d,b)});
}

/*
	---------------------------------------- Poligons ----------------------------------------
*/

double areaTriangle(pt a, pt b, pt c) {
	return abs(cross(b-a, c-a)) / 2.0;
}

double areaPolygon(vector<pt> p) {
	double area = 0.0;
	for (int i = 0, n = p.size(); i < n; i++) {
		area += cross(p[i], p[(i+1)%n]); // wrap back to 0 if i == n-1
	}
	return abs(area) / 2.0;
}

bool above(pt a, pt p) {
	// True if P at least as high as A (blue part).
	return p.y >= a.y;
}


bool crossesRay(pt a, pt p, pt q) {
	// Check if [PQ] crosses ray from A.
	return (above(a,q) - above(a,p)) * orient(a,p,q) > 0;
}

bool inPolygon(vector<pt>& p, pt a, bool strict = true) {
	// Check if point a is in polygon p.
	// If strict, returns false when A is on the boundary.

	int numCrossings = 0;
	for (int i = 0, n = p.size(); i < n; i++) {
		if (onSegment(p[i], p[(i+1)%n], a)) {
			return !strict;
		}
			
		numCrossings += crossesRay(a, p[i], p[(i+1)%n]);
	}
	return numCrossings & 1; // inside if odd number of crossings
}


vector<pt> poly;
bool ok(int xx, int yy) {
	return inPolygon(poly, pt(xx, yy), false);
}

const int MAXN = 1e7 + 10;
const int INF = 1e6+10;

ll n;

void solve() {
	cin >> n;
	ll dx[2], dy[2];
	cin >> dx[0] >> dy[0] >> dx[1] >> dy[1];
	ll Area = abs(dx[0]-dx[1])*abs(dy[0]-dy[1]);
	for(int i = 0; i < 2; i++) {
		if(dx[i] < 0) {
			dx[i] *= -1;
			dy[i] *= -1;
		}
	}
	
	if(fabs(cross(pt(dx[0], dy[0]), pt(dx[1], dy[1]))) < 1e-9) {
		cout << "NO\n";
		return;
	}
	
	poly.push_back(pt(dx[0], dy[0]));
	poly.push_back(pt(dx[0]+dx[1], dy[0]+dy[1]));
	poly.push_back(pt(dx[1], dy[1]));
	poly.push_back(pt(0, 0));
	//for(auto p : poly) {
		//cerr << p << "\n";
	//}
	
	int Lx = min({0LL, dx[0], dx[1], dx[0]+dx[1]}), Rx = max({0LL, dx[0], dx[1], dx[0]+dx[1]});
	
	pii A = {dx[0], dy[0]}, B = {dx[1], dy[1]};
	double xx = dx[0] == 0 ? dy[0] : 0, yy = dx[1] == 0 ? dy[1] : 0;
	
	const double EPS = 1e-9;
	vector<pii> ans;
	const int MAGIC = 5;
	for(int r = Lx; r <= Rx; r++) {
		int low = min(int(xx-EPS-MAGIC), int(yy-EPS-MAGIC)), high = max(int(xx+EPS+MAGIC), (int) (yy+EPS+MAGIC));
		//cerr << r << ": " << low << " " << high << "\n";
		for(int c = low; c <= high; c++) {
			bool ok = inPolygon(poly, pt(r, c));
			pii me = {r, c};
			if(me != A && onSegment(pt(0, 0), pt(dx[0], dy[0]), pt(r, c)))
				ok = true;
			if(me != B && onSegment(pt(0, 0), pt(dx[1], dy[1]), pt(r, c)))
				ok = true;
				
			if(ok) {
				ans.emplace_back(r, c);
			}
			if((int) ans.size() > n) {
				goto out;
			}
		}
		
		if(r < dx[0]) {
			xx += (ld)dy[0]/dx[0];
		}
		else {
			xx += (ld)dy[1]/dx[1];
		}
		if(r < dx[1]) {
			yy += (ld)dy[1]/dx[1];
		}
		else {
			yy += (ld)dy[0]/dx[0];
		}
	}
	out:;
	if((int) ans.size() != n) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(auto [a, b] : ans) {
		cout << a << " " << b << "\n";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}
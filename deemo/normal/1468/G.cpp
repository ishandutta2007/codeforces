#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef double T;

typedef complex<T> pt;
#define x real()
#define y imag()

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX

const int MAXN = 2e5 + 10;

int n, H;
int xx[MAXN], yy[MAXN];

int crss(pii a, pii b, pii c) {
    a.F -= c.F;
    a.S -= c.S;
    b.F -= c.F;
    b.S -= c.S;
    ll res = 1ll*a.F*b.S - 1ll*a.S*b.F;
    if (res == 0)
        return res;
    return res < 0? -1: 1;
}

ld ln(pii a, pair<ld, ld> b) {
    ld dx = b.F - a.F;
    ld dy = b.S - a.S;
    return sqrt(dx*dx + dy*dy);
}

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

void solve() {
    cin >> n >> H;
    for (int i = 0; i < n; i++) cin >> xx[i] >> yy[i];
    ld ans = 0;
    pair<ld, ld> ang {-1, -1};
    for (int i = n-2; ~i; i--) {
        int c = crss({xx[i+1], yy[i+1]}, {xx[n-1], yy[n-1] + H}, {xx[i], yy[i]});
        //cout << "cross:   " << c << endl;
        if (c >= 0) {
            // update the answer DONE & angle
            pair<ld, ld> right_end;
            if (ang.F == -1)
                right_end = {xx[i+1], yy[i+1]};
            else {
                line l1 {pt{xx[i], yy[i]}, pt{xx[i+1], yy[i+1]}};
                line l2 {pt{ang.F, ang.S}, pt{xx[n-1], yy[n-1] + H}};
                pt out;
                if (!inter(l1, l2, out)) {
                    pt a1 {xx[i], yy[i]};
                    pt a2 {xx[i+1], yy[i+1]};
                    pt a3 = {ang.F, ang.S};
                    if (abs(cross(a2-a1, a3-a1)) < 1e-7)
                        right_end = {xx[i+1], yy[i+1]};
                    else
                        right_end = {xx[i], yy[i]};
                } else {
                    if (out.x < xx[i] || out.x >= xx[n-1] - 1e-7)
                        out = pt {xx[i], yy[i]};
                    else if (out.x > xx[i+1])
                        out = pt {xx[i+1], yy[i+1]};
                    right_end = {out.x, out.y};
                }
            }
            ans += ln({xx[i], yy[i]}, right_end);
            if (ang.F == -1 || right_end.F != xx[i])  // intentional binary eq
                ang = {xx[i], yy[i]};
        } else {
            // update the angle only  DONE
            pt a1 {ang.F, ang.S};
            pt a2 {xx[n-1], yy[n-1] + H};
            pt a3 {xx[i+1], yy[i+1]};
            if (ang.F == -1 || cross(a1 - a3, a2 - a3) > 0)
                ang = {xx[i+1], yy[i+1]};
        }
        //cout << ang.F << "   " << ang.S << "  " << ans << endl;
    }
    cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef complex<ld> pt;

#define X real()
#define Y imag()


//pt rotate(pt p, ld rad, pt o = pt(0, 0)) {return o + (p - o) * polar(1.0, rad);}
pt perp(pt p, pt o = pt(0, 0)) {return o + pt(-(p-o).Y, (p-o).X);}

ld dot(pt a, pt b){return a.X*b.X + a.Y*b.Y;}
ld cross(pt a, pt b){return a.X*b.Y - a.Y*b.X;}
pt products(pt a, pt b){return conj(a)*b;}

//ld angle(pt a, pt b){return acos(clamp(dot(a, b)/ abs(a)/ abs(b), -1., 1.));}
ld orient(pt o, pt a, pt b){return cross(a-o, b-o);}

struct Line {
	pt v;
	ld c;

	Line(ld a, ld b, ld c): v(pt(b, -a)), c(c) {}
	Line(pt v, ld c): v(v), c(c) {}
	Line(pt p, pt q): v(q-p), c(cross(v, p)) {}

	ld side(pt p) {return cross(v, p) - c;} //because cross product is distributive 
	ld dist(pt p) {return abs(side(p))/ abs(v);}
	ld sqDist(pt p) {return side(p)*side(p)/ norm(v);} //XXX can be improved
	Line perpThrough(pt p) {return Line(p, p+perp(v));}
	Line translate(pt t) {return Line(v, c + cross(v, t));}
	Line shiftLeft(ld dist) {return Line(v, c + dist*abs(v));}
	bool cmpProj(pt p, pt q) {return dot(v, p) < dot(v, q);}
	pt proj(pt p) {return p - perp(v)*side(p)/ norm(v);}
	//pt reflection(pt p) {return p - 2*perp(v)*side(p)/ norm(v);}
};

pt inter(Line l1, Line l2){
	ld cr = cross(l1.v, l2.v);
	assert(cr);
	return (l1.c*l2.v - l1.v*l2.c)/ cr;
}

Line intBisector(Line l1, Line l2, bool interior = true) {
	assert(cross(l1.v, l2.v) != 0); // l1 and l2 cannot be parallel!
	ld sign = interior ? 1 : -1;
	return {l2.v/abs(l2.v) + sign * l1.v/abs(l1.v),
		l2.c/abs(l2.v) + sign * l1.c/abs(l1.v)};
}

void readP(pt &p){
	int x, y; cin >> x >> y;
	p = pt(x, y);
}

int main() {
	pt o; readP(o);
	int n; cin >> n;
	ld ans = 1e18;
	while (n--){
		pt p; readP(p);
		int v; cin >> v;
		ans = min<ld>(ans, abs(p-o)/ v);
	}
	cout << fixed << setprecision(12);
	cout << ans << "\n";
	return 0;
}
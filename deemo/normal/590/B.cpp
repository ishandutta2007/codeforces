#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef complex<ld> pt;

#define X real()
#define Y imag()


pt rotate(pt p, ld rad, pt o = pt(0, 0)) {return o + (p - o) * polar((ld)1, rad);}//XXX only floating points
pt perp(pt p, pt o = pt(0, 0)) {return o + pt(-(p-o).Y, (p-o).X);}//rotate 90 degrees

ld dot(pt a, pt b){return a.X*b.X + a.Y*b.Y;}
ld cross(pt a, pt b){return a.X*b.Y - a.Y*b.X;}
pt products(pt a, pt b){return conj(a)*b;} //(dot + i * cross)

ld angle(pt a, pt b){return acos(clamp(dot(a, b)/ abs(a)/ abs(b), -(ld)1., (ld)1.));}//XXX only floating points
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
	ld x, y; cin >> x >> y;
	p = pt(x, y);
}

int main() {
	cout << fixed << setprecision(12);
	pt p1, p2; 
	readP(p1), readP(p2);
	ld vMax, t; cin >> vMax >> t;
	pt v, w;
	readP(v), readP(w);
	
	if (abs(p2-(p1 + v*t)) <= t*vMax){
		pt o = p1;
		ld lo = 0, hi = t;
		for (int i = 0; i < 500; i++){
			ld mid = (hi+lo)/2;
			pt to = o + v*mid;
			ld tr = mid*vMax;
			if (abs(p2-to) <= tr)
				hi = mid;
			else
				lo = mid;
		}
		cout << hi << "\n";
	}
	else{
		pt o(p1 + v*t);
		ld lo = 0, hi = 1e9;
		for (int i = 0; i < 500; i++){
			ld mid = (hi+lo)/2;
			pt to = o + mid*w;
			ld tr = (t+mid)*vMax;
			if (abs(p2-to) <= tr)
				hi = mid;
			else
				lo = mid;
		}
		cout << t+hi << "\n";
	}

	return 0;
}
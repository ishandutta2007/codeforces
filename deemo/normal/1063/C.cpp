#include <bits/stdc++.h>

using namespace std;

typedef long long ld;
typedef complex<ld> pt;

#define X real()
#define Y imag()


pt rotate(pt p, ld rad, pt o = pt(0, 0)) {return o + (p - o) * polar((ld)1, rad);}//XXX only floating points
pt perp(pt p, pt o = pt(0, 0)) {return o + pt(-(p-o).Y, (p-o).X);}//rotate 90 degrees

ld dot(pt a, pt b){return a.X*b.X + a.Y*b.Y;}
ld cross(pt a, pt b){return a.X*b.Y - a.Y*b.X;}
pt products(pt a, pt b){return conj(a)*b;} //(dot + i * cross)

ld angle(pt a, pt b){return acos(clamp(dot(a, b)/ abs(a)/ abs(b), -(ld)1., (ld)1.));}//XXX only floating points
ld orient(pt o, pt a, pt b){
	ld temp = cross(a-o, b-o);
	if (temp == 0) return temp;
	return temp/ abs(temp);
}

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

int findFirst(pt origin, pt p, int f, int x){
	int lo = 0, hi = x;
	while (hi-lo>1){
		int mid = hi+lo>>1;
		if (orient(origin, p, pt(x, mid)) == f){
			if (f == -1)
				lo = mid;
			else
				hi = mid;
		}
		else{
			if (f == -1)
				hi = mid;
			else
				lo = mid;
		}
	}
	return f==-1? lo: hi;
}

int main() {
	int n; cin >> n;
	pt origin(0, 0);
	pt left(0, 1), right(1, 0);
	int curX = 1;
	char c = 'b';
	string s;
	while (n--) {
		int firstY = findFirst(origin, right, 1, curX);
		int lastY = findFirst(origin, left, -1, curX);
		int mid = firstY+lastY>>1;
		if (curX == 1)
			mid = 1;
		//cout << firstY << "  " << lastY << endl;
	
		cout << curX << " " << mid << endl;
		cin >> s;
		if (s[0] == c)
			left = pt(curX, mid);
		else{
			if (curX == 1) {
				left = pt(curX, mid);
				c = 'w';
			}
			else
				right = pt(curX, mid);
		}

		curX <<= 1;
	}
	ld x = left.real(), y = left.imag();
	if (s[0] != c)
		x = right.real(), y = right.imag();
	
	long double tempY = 1e9L/x * y ;//+ (s[0] == c? -1: 1);
	if (floor(tempY) == tempY){
		y = tempY + (s[0]==c?-1:1);
	}
	else{
		if (s[0] == c)
			y = tempY;
		else
			y = tempY + 1;
	}

	x = 1e9;

	cout << "0 0 " << x << " " << y << "\n";
	return 0;
}
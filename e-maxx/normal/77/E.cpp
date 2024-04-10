#pragma comment (linker, "/STACK:60000000")
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;


#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define double long double
const double PI = acos((double)0) * 2;


struct pt {
	double x, y;

	pt() : x(0), y(0)  { }
	pt (double x, double y) : x(x), y(y)  { }

	pt operator+ (const pt & p) const {
		return pt (x+p.x, y+p.y);
	}
	pt operator- (const pt & p) const {
		return pt (x-p.x, y-p.y);
	}
	pt operator* (double p) const {
		return pt (x*p, y*p);
	}
};

inline double dist2 (const pt & a, const pt & b) {
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

inline double dist (const pt & a, const pt & b) {
	return sqrt (dist2 (a, b));
}

struct circle : pt {
	double r;

	circle (double x, double y, double r) : pt(x,y), r(r) { }
};

struct line {
	double a, b, c;

	line() { }
	line (const pt & p, const pt & q) {
		a = p.y - q.y;
		b = q.x - p.x;
		c = -a * p.x - b * p.y;
		norm();
	}

	void norm() {
		double z = sqrt(a*a+b*b);
		a /= z,  b /= z,  c /= z;
	}

	pt covector() {
		return pt (-b, a);
	}
};

pt inverse (const pt & p) {
	double d = dist2 (pt(0,0), p);
	return p * (1. / d);
}

circle inverse_to_circle (const circle & c) {
	pt p1 = inverse (c + pt (-c.r, 0));
	pt p2 = inverse (c + pt (c.r, 0));

	pt cntr = (p1 + p2) * 0.5;
	return circle (cntr.x, cntr.y, dist (p1, p2) / 2);
}

line inverse_to_line (const circle & c) {
	pt p1 = inverse (c + pt (0, c.r));
	pt p2 = inverse (c - pt (0, c.r));
	return line (p1, p2);
}

#define det(a,b,c,d)  (a*d-b*c)

pt intersect (const line & m, const line & n) {
	double zn = det (m.a, m.b, n.a, n.b);
	return pt (
		- det (m.c, m.b, n.c, n.b) / zn,
		- det (m.a, m.c, n.a, n.c) / zn
	);
}

double ang (const pt & a, const pt & b) {
	double x = atan2 (a.y, a.x);
	double y = atan2 (b.y, b.x);
	double res = abs (x - y);
	return min (res, 2*PI - res);
}

double get_new_radius (const circle & c) {
	return c.r / (c.x*c.x + c.y*c.y - c.r*c.r);
}


int R, r, k;


void read() {
	scanf ("%d%d%d", &R, &r, &k);
}


void solve() {
	circle big (R, 0, R);
	circle small (r, 0, r);
	circle med (R+r, 0, R-r);

	line nbig = inverse_to_line (big);
	line nsmall = inverse_to_line (small);
	circle nmed = inverse_to_circle (med);

	circle ans = nmed;
	ans.y += 2 * nmed.r * k;

	double res = get_new_radius (ans);

	cout.precision (20);
	cout.setf (ios::fixed);
	cout << res << '\n';
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int ts;
	cin >> ts;
	forn(tt,ts) {
		read();
		solve();
	}

}
#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a),_E=(b); i<=_E; ++i)
#define per(i,a,b) for (int i=(a),_E=(b); i>=_E; --i)
#define REP(i,n) for (int i=(0),_E=(n); i<_E; ++i)
using namespace std;
typedef long double ld;
 
const int N = 100005;
const ld eps = 1e-12;
struct pt {
	ld x, y; pt (ld _x = 0, ld _y = 0) { x = _x, y = _y; }
	friend bool operator < (pt a, pt b) { return a.x-a.y < b.x-b.y; }
	friend pt operator - (pt a, pt b) { return pt(a.x-b.x, a.y-b.y); }
	friend ld operator * (pt a, pt b) { return a.x*b.y - a.y*b.x; }
} S, p[N], u[N], v[N];
int tim[N], n, w, h;
 
#define sqr(x) ((x) * (x))
inline ld dist(pt a, pt b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
inline bool same(pt a, pt b) {
	return dist(a, b) < eps;
}
inline ld cross(pt a, pt b, pt p) {
	return (a - p) * (b - p);
}
inline bool segCross(pt a, pt b, pt c, pt d, pt &p) {
	ld A, B, s1, s2, s3, s4;
	if (same(c, d)) { swap(a, c), swap(b, d); }
	A = (s1 = cross(a, b, c)) * (s2 = cross(a, b, d));
	B = (s3 = cross(c, d, a)) * (s4 = cross(c, d, b));
	if (!same(a, b)) {
		if (A > eps || B > eps) return 0;
		if (A > -eps && B > -eps) return 0;
		p.x = (c.x * s2 - d.x * s1) / (s2 - s1);
		p.y = (c.y * s2 - d.y * s1) / (s2 - s1);
	}
	else if (same(c, d)) {
		return p = a, same(b, c);
	}
	else {
		return p = a, dist(a, c) + dist(a, d) < dist(c, d) + eps;
	}
	return 1;
}
inline bool inside(pt s, pt t, ld d, pt p) {
	if (fabs(p.x-s.x) < d+eps && fabs(p.y-s.y) < d+eps) return 1;
	if (fabs(p.x-t.x) < d+eps && fabs(p.y-t.y) < d+eps) return 1;
	pt A = pt(p.x - d, p.y - d), B = pt(p.x + d, p.y + d), C;
	return segCross(s, t, A, B, C);
}
 
#define P(A,B,C) pt(A.x + B * delta, A.y + C * delta)
#define DO if (segCross(u[i], v[i], a, b, c)) pp.push_back(c);
int flag;
bool check(ld r) {
	pt s = S, t = S, a, b, c;
	ld delta; vector<pt> pp;
	rep (i, 1, n) {
		delta = r * (tim[i] - tim[i - 1]);
		pp.clear();
		if (inside(s, t, delta, u[i])) pp.push_back(u[i]);
		if (inside(s, t, delta, v[i])) pp.push_back(v[i]);
		a = P(s, -1, -1), b = P(s, -1, 1); DO;
		a = b, b = P(s, 1, 1); DO;
		a = b, b = P(t, 1, 1); DO;
		a = b, b = P(t, 1, -1);	DO;
		a = b, b = P(t, -1, -1); DO;
		a = b, b = P(s, -1, -1); DO;
		if (pp.empty()) return 0;
		sort(pp.begin(), pp.end());
		s = pp[0], t = pp.back();
	}
	return 1;
}
 
pt O, U, R, g;
inline void doit(pt p, pt &u, pt &v) {
	if (fabs(p.x - w) < eps) {
		u = v = pt(w, w);
		return;
	}
	u = pt(0, p.x * h / p.y);
	v = pt(p.x * h / (h - p.y), 0);
	pt uu = u, vv = v;
	if (segCross(O, U, uu, vv, g)) u = g;
	if (segCross(O, R, uu, vv, g)) v = g;
}
 
int main() {
	double x, y;
	scanf("%d%d%d", &n, &w, &h);
	U = pt(0, w), R = pt(w, 0), O = pt(w, w);
	scanf("%lf%lf", &x, &y), S = pt(x, y);
	rep (i, 1, n) {
		scanf("%d%lf%lf", &tim[i], &x, &y), p[i] = pt(x, y);
		doit(p[i], u[i], v[i]);
	}
	if (!check(w + 1)) return puts("-1"), 0;
	ld l = 0, r = w + 1, mid;
	rep (i, 1, 50) {
		mid = (l + r) * 0.5;
		if (check(mid)) r = mid;
		else l = mid;
	}
	printf("%.6lf\n", (double) l);
	return 0;
}
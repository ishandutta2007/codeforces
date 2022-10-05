#include<bits/stdc++.h>
using namespace std;
typedef long double LD;

const LD eps = 1e-10;
struct point { LD x, y; } A, B, C;
LD L1, L2, l, r, mid;

int fcmp(LD x) {
	if (abs(x) <= eps) return 0;
	return x > 0 ? 1 : -1;
}

LD Sqrt(LD x) {
	LD l = 0, r = max(LD(1.0), x), mid; int T = 200;
	while (T--) {
		mid = (l + r) * 0.5;
		if (mid * mid <= x) l = mid;
		else r = mid;
	}
	// printf("     %.5Lf %.5Lf\n", l, x);
	return l;
}

LD dist(point a, point b) {
	return Sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

bool inside(LD x, LD y, point o, LD r) {
	point p; p.x = x; p.y = y;
	// printf("%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", x, y, o.x, o.y, r);
	// printf("%.8Lf\n", (p.x-o.x)*(p.x-o.x)+(p.y-o.y)*(p.y-o.y) - r*r);
	return fcmp(dist(p, o) - r) <= 0;
}

bool solve(point a, LD ra, point b, LD rb, point c, LD rc) {
	LD u = 2*ra*(a.x-b.x), v = 2*ra*(a.y-b.y);
	LD w = rb*rb - ra*ra - (a.x-b.x)*(a.x-b.x) - (a.y-b.y)*(a.y-b.y);
	LD A = u*u + v*v, B = -2*u*w, C = w*w - v*v;
	// printf("%.5Lf  %.5Lf   %.5Lf\n", A, B, C);
	LD delta = Sqrt(B*B - 4*A*C), X1, X2, dx, dy;
	X1 = (-B-delta)/A/2; X2 = (-B+delta)/A/2;
	// printf("x1=%.5Lf   x2=%.5Lf\n", X1, X2);
	dx = a.x + ra*X1; dy = a.y + ra * Sqrt(1 - X1*X1);
	// printf("%.4Lf %.4Lf\n", dx, dy);
	if (inside(dx, dy, b, rb) && inside(dx, dy, c, rc)) return 1;
	dx = a.x + ra*X1; dy = a.y - ra * Sqrt(1 - X1*X1);
	// printf("%.4Lf %.4Lf\n", dx, dy);
	if (inside(dx, dy, b, rb) && inside(dx, dy, c, rc)) return 1;
	dx = a.x + ra*X2; dy = a.y + ra * Sqrt(1 - X2*X2);
	// printf("%.4Lf %.4Lf\n", dx, dy);
	if (inside(dx, dy, b, rb) && inside(dx, dy, c, rc)) return 1;
	dx = a.x + ra*X2; dy = a.y - ra * Sqrt(1 - X2*X2);
	// printf("%.4Lf %.4Lf\n", dx, dy);
	if (inside(dx, dy, b, rb) && inside(dx, dy, c, rc)) return 1;
	return 0;
}

bool judge(point a, LD ra, point b, LD rb, point c, LD rc) {
	if (fcmp(ra) <= 0 || fcmp(rb) <= 0 || fcmp(rc) <= 0) return 0;
	if (fcmp(ra + rb - dist(a, b)) < 0) return 0;
	if (fcmp(ra + rc - dist(a, c)) < 0) return 0;
	if (fcmp(rb + rc - dist(b, c)) < 0) return 0;
	if (fcmp(fabs(ra - rb) - dist(a, b)) >= 0) return 1;
	if (fcmp(fabs(ra - rc) - dist(a, c)) >= 0) return 1;
	if (fcmp(fabs(rb - rc) - dist(b, c)) >= 0) return 1;
	// printf("! %.8Lf\n", ra);
	if (solve(a, ra, b, rb, c, rc)) return 1;
	if (solve(b, rb, c, rc, a, ra)) return 1;
	if (solve(c, rc, a, ra, b, rb)) return 1;
	// puts("-2");
	return 0;
}

bool check(LD x) {
	return judge(A, x, B, L1-x, C, L2-x-dist(B, C));
}

int main() {
	scanf("%Lf%Lf%Lf%Lf%Lf%Lf%Lf%Lf", &L2, &L1, &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);
	L1 += dist(A, B); L2 += dist(A, C) + dist(C, B);
	if (fcmp(dist(A, C) + dist(C, B) - L1) <= 0) {
		printf("%.12Lf\n", min(L1 , L2)); //dist(A, C) + dist(C, B));
		return 0;
	}
	l = 0; r = min(L1, L2);
	while (r-l > eps) {
		mid = (l + r) * 0.5;
		if (check(mid)) l = mid;
		else r = mid;	
	}
	printf("%.12Lf\n", l);
	return 0;
}
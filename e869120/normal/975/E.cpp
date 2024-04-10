#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
#pragma warning (disable: 4996)

const long double PI = 3.14159265358979L;

long double degree(long double x, long double y) {
	long double E = y / sqrtl(x*x + y*y);
	if (x >= 0) {
		long double F = asin(E);
		if (F < 0) return F + 2.0L*PI;
		return F;
	}
	else {
		long double F = asin(E);
		return PI - F;
	}
}
long double dist(long double gx, long double gy, long double hx, long double hy) {
	return sqrtl((gx - hx)*(gx - hx) + (gy - hy)*(gy - hy));
}

long double x[200009], y[200009], vx, vy, VX, VY, R[200009]; int n, q, T = -1;

pair<long double, long double>getpts(int pos) {
	if (T == -1) { return make_pair(x[pos], y[pos]); }
	long double S = R[pos] - R[T] + PI / 2.0L; if (S < 0.0L) S += 2.0L*PI; if (S >= 2.0L*PI) S -= 2.0L*PI;

	long double Y1 = sin(S);
	long double X1 = cos(S);
	long double D = dist(VX, VY, x[pos], y[pos]);
	return make_pair(vx + X1*D, vy + Y1*D);
}

struct Point {
	long double px, py;
};

long double area(Point A, Point B, Point C) {
	long double E1 = (B.px - A.px)*(B.py + A.py);
	long double E2 = (C.px - B.px)*(C.py + B.py);
	long double E3 = (A.px - C.px)*(A.py + C.py);
	return abs(E1 + E2 + E3) / 2.0L;
}

Point gravity(vector<Point>vec) {
	long double Vx = 0, Vy = 0, S = 0;
	for (int i = 1; i < vec.size() - 1; i++) {
		long double U = area(vec[0], vec[i], vec[i + 1]);
		long double Fx = (vec[0].px + vec[i].px + vec[i + 1].px) / 3, Fy = (vec[0].py + vec[i].py + vec[i + 1].py) / 3;
		S += U;
		Vx += Fx*U; Vy += Fy*U;
	}
	Vx /= S; Vy /= S;
	return Point{ Vx,Vy };
}

int G1 = 1, G2 = 2;

int main() {
	cin >> n >> q; vector<Point>vecs;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i]; vecs.push_back(Point{ x[i], y[i] });
	}
	Point gra = gravity(vecs);
	vx = gra.px; vy = gra.py;
	for (int i = 1; i <= n; i++) R[i] = degree(x[i] - vx, y[i] - vy);

	VX = vx; VY = vy;

	for (int i = 1; i <= q; i++) {
		int a1, a2, a3; scanf("%d", &a1);
		if (a1 == 1) {
			scanf("%d%d", &a2, &a3); int keys = 0;
			if (G1 == a2) { G1 = -1; keys = G2; }
			else if (G2 == a2) { G2 = -1; keys = G1; }

			assert(keys != 0);

			pair<long double, long double>I = getpts(keys);
			long double DD = dist(VX, VY, x[keys], y[keys]);

			vx = I.first; vy = I.second - DD;

			if (G1 == -1) { G1 = a3; }
			if (G2 == -1) { G2 = a3; }
			T = keys;
		}
		else {
			scanf("%d", &a2);
			pair<long double, long double>I = getpts(a2);
			printf("%.12Lf %.12Lf\n", I.first, I.second);
		}
	}
	return 0;
}
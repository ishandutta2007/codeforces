#include <bits/stdc++.h>
using namespace std;

const int N = 6060;

int n, svt, c;
double q, A, B, x[N];

double mx[N], ans[N], zans;

struct line {
	double l, r, k, b;

	void move(double t) {
		l += t, r += t;
		b -= k * t;
	}
	double getx() {
		double z = -b / k;
		if (z < l) return l;
		if (l <= z && z <= r) return z;
		if (r < z) return r;
	}
	double get() {
		return k * getx() + b;
	}
} sv[N * 2];

int main() {
	scanf("%d %lf %lf %lf", &n, &q, &A, &B);
	for (int i = 1; i <= n; ++i) {
		scanf("%lf", x + i);
	}
	for (int o = 1; o <= n; ++o) {
		if (o == 1) {
			sv[svt = 1] = (line) {1, q, 2, -x[o] * 2};
		} else {
			svt += 2;
			for (int i = svt; i - 2 > c; --i) {
				sv[i] = sv[i - 2];
				sv[i].move(B);
			}
			sv[c + 2] = sv[c], sv[c + 2].move(B - A);
			sv[c].r = mx[o - 1];
			sv[c + 2].l = mx[o - 1] + B - A;
			sv[c + 1] = (line) {sv[c].r, sv[c + 2].l, 0, 0};
			
			for (int i = 1; i <= c + 2; ++i) {
				sv[i].move(A);
			}
			for (int i = 1; i <= svt; ++i) {
				sv[i].k += 2;
				sv[i].b -= x[o] * 2;
			}

			while (sv[svt].l > q - 1e-7) --svt;
			sv[svt].r = q;
		}

		double best = 1e20;
		c = -1;
		for (int i = 1; i <= svt; ++i) {
			double cur = fabs(sv[i].get());
			if (cur < best) best = cur, c = i;
		}
		mx[o] = sv[c].getx();
	}

	ans[n] = mx[n];
	for (int o = n; o >= 2; --o) {
		double v = ans[o], t = mx[o - 1];
		if (v < A + t) ans[o - 1] = v - A;
		if (A + t <= v && v <= B + t) ans[o - 1] = t;
		if (v > B + t) ans[o - 1] = v - B;
	}

	double zans = 0;
	for (int i = 1; i <= n; ++i) {
		printf("%lf ", ans[i]);
		zans += (ans[i] - x[i]) * (ans[i] - x[i]);
	}
	printf("\n%lf\n", zans);
}
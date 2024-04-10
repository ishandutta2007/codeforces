#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

inline double sqr(double x) { return x * x; }

double dis(double x0, double y0, double x1, double y1) {
	return sqrt(sqr(x0-x1) + sqr(y0-y1));
}

int main() {
	double a, b, c, x[2], y[2];
	cin >> a >> b >> c;
	for (int T : {0, 1}) cin >> x[T] >> y[T];
	double ans = fabs(x[0] - x[1]) + fabs(y[0] - y[1]);
	for (int i : {0, 1}) {
		double _x[2], _y[2];
		if (i) {
			_x[0] = x[0];
			if (fabs(b) > eps) {
				_y[0] = (a * x[0] + c) / -b;
			} else {
				if (fabs(a * x[0] + c) < eps) {
					_y[0] = y[0];
				} else {
					continue;
				}
			}
		} else {
			_y[0] = y[0];
			if (fabs(a) > eps) {
				_x[0] = (b * y[0] + c) / -a;
			} else {
				if (fabs(b * y[0] + c) < eps) {
					_x[0] = x[0];
				} else {
					continue;
				}
			}
		}
		for (int j : {0, 1}) {
			if (j) {
				_x[1] = x[1];
				if (fabs(b) > eps) {
					_y[1] = (a * x[1] + c) / -b;
				} else {
					if (fabs(a * x[1] + c) < eps) {
						_y[1] = y[1];
					} else {
						continue;
					}
				}
			} else {
				_y[1] = y[1];
				if (fabs(a) > eps) {
					_x[1] = (b * y[1] + c) / -a;
				} else {
					if (fabs(b * y[1] + c) < eps) {
						_x[1] = x[1];
					} else {
						continue;
					}
				}
			}
			ans = min(ans, dis(x[0], y[0], _x[0], _y[0]) +
						   dis(_x[0], _y[0], _x[1], _y[1]) +
						   dis(_x[1], _y[1], x[1], y[1]));
		}
	}
	printf("%.10lf\n", ans);
}
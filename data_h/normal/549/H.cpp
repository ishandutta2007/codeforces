#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

double a, b, c, d;

int main() {
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	double l = 0, r = 1e11;

	for (int i = 0; i < 200; i++) {
		double mid = (l + r) / 2;
		double l1 = min(min((a - mid) * (d - mid), (a - mid) * (d + mid)), min((a + mid) * (d - mid), (a + mid) * (d + mid)));
		double r1 = max(max((a - mid) * (d - mid), (a - mid) * (d + mid)), max((a + mid) * (d - mid), (a + mid) * (d + mid)));
		double l2 = min(min((b - mid) * (c - mid), (b - mid) * (c + mid)), min((b + mid) * (c - mid), (b + mid) * (c + mid)));
		double r2 = max(max((b - mid) * (c - mid), (b - mid) * (c + mid)), max((b + mid) * (c - mid), (b + mid) * (c + mid)));
		if (l1 <= r2 && l2 <= r1) {
			r = mid;
		} else {
			l = mid;
		}
	}
	printf("%.10f\n", (l + r) / 2);
	return 0;
}
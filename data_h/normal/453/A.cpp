#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

double power(double a, int b) {
	if (b == 0) {
		return 1;
	}
	double t = power(a, b / 2);
	if (b & 1) {
		return t * t * a;
	} else {
		return t * t;
	}
}

int main() {
	int n, m;
	scanf("%d %d", &m, &n);
	double ans = 0;
	for(int i = 1; i <= m; i++) {
		ans += (power(1.0 * i / m, n) - power(1.0 * (i - 1) / m, n)) * i;
	}
	printf("%.10f\n", ans);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long double LD;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		LD r, R, x, y, r1, r2, d; int K;
		scanf("%Lf%Lf%d", &R, &r, &K);
		x = (R + r) / (4 * R * r);
		y = K * (R - r) / (2 * R * r);
		d = sqrt(x * x + y * y);
		r1 = (R - r) / (4 * R * r);
		r2 = (1 / (d - r1) - 1 / (d + r1)) / 2;
		printf("%.12Lf\n", r2);
	}
	return 0;
}
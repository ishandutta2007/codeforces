#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
long long n, k, c; long double l, a, b;
int main() {
	cin >> n >> l >> a >> b >> k;
	c = (n + k - 1) / k;
	long double L = l / c, R = l, M;
	for (int i = 0; i < 70; i++) {
		M = (L + R) / 2;
		long double I = (M*c - l) / (c - 1);
		long double T = (M + I) / b - (M - I) / a;
		if (T > 0)R = M;
		if (T < 0)L = M;
	}
	printf("%.12Lf\n", (l - M) / a + M / b);
	return 0;
}
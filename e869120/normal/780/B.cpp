#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n; long double x[100000], v[100000];
bool solve(long double p) {
	long double maxl = 0.0L, maxr = 0.0L;
	for (int i = 0; i < n; i++) {
		if (x[i] < p)maxl = max(maxl, (p - x[i]) / v[i]);
		if (x[i] > p)maxr = max(maxr, (x[i] - p) / v[i]);
	}
	if (maxl > maxr)return true;
	return false;
}
int main() {
	cin >> n; for (int i = 0; i < n; i++)cin >> x[i]; for (int i = 0; i < n; i++)cin >> v[i];
	long double L = 0.0L, R = 1e9, M;
	for (int i = 0; i < 200; i++) {
		M = (L + R) / 2;
		if (solve(M) == true)R = M;
		else L = M;
	}
	long double ret = 0;
	for (int i = 0; i < n; i++)ret = max(ret, fabsl(x[i] - M) / v[i]);
	printf("%.13Lf\n", ret);
	return 0;
}
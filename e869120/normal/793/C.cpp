#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#pragma warning(disable: 4996)
int n, a[100009], b[100009], c[100009], d[100009]; long double a1, a2, a3, a4, L = -1000000.0L, R = 1000000.0L;
pair<long double, long double>solve(int r1, int r2, int r3, int r4) {
	if (r3 == 0 && r4 == 0) {
		if (a1 < r1 && r1 < a3 && a2 < r2 && r2 < a4)return make_pair(0.0L, 1000000.0L);
		return make_pair(-1.0L, -1.0L);
	}
	if (r3 == 0) {
		if (!(a1 < r1 && r1 < a3))return make_pair(-1.0L, -1.0L);
	}
	if (r4 == 0) {
		if (!(a2 < r2 && r2 < a4))return make_pair(-1.0L, -1.0L);
	}
	long double p1 = r1, p2 = r2, p3 = r3, p4 = r4;
	long double I1 = (a1 - p1) / p3, I2 = (a3 - p1) / p3; if (I1 > I2)swap(I1, I2); if (I1 < 0)I1 = 0;
	long double I3 = (a2 - p2) / p4, I4 = (a4 - p2) / p4; if (I3 > I4)swap(I3, I4); if (I3 < 0)I3 = 0;
	if (I1 > I4 || I4 - I1 < 1e-14)return make_pair(-1.0L, -1.0L);
	if (I3 > I2 || I2 - I3 < 1e-14)return make_pair(-1.0L, -1.0L);
	if (I1 > I2 || I2 - I1 < 1e-14)return make_pair(-1.0L, -1.0L);
	if (I3 > I4 || I4 - I3 < 1e-14)return make_pair(-1.0L, -1.0L);
	return make_pair(max(I1, I3), min(I2, I4));
}
int main() {
	cin >> n >> a1 >> a2 >> a3 >> a4;
	for (int i = 0; i < n; i++) {
		int p1, p2, p3, p4; scanf("%d%d%d%d", &p1, &p2, &p3, &p4); a[i] = p1; b[i] = p2; c[i] = p3; d[i] = p4;
		pair<long double, long double>C = solve(a[i], b[i], c[i], d[i]);
		if (C.first < -0.5) { cout << "-1" << endl; return 0; }
		L = max(L, C.first); R = min(R, C.second);
	}
	if (L > R || R - L < 1e-14) { cout << "-1" << endl; }
	else { printf("%.12Lf\n", L); }
	return 0;
}
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#pragma warning (disable: 4996)

long double n, x[100009], y[100009];

bool solve(long double E) {
	long double L = -1e12, R = 1e12;
	for (int i = 1; i <= n; i++) {
		if (y[i] >= 2LL * E) return false;
		long double G = E * E - (y[i] - E) * (y[i] - E); G = sqrtl(G);
		L = max(L, x[i] - G); R = min(R, x[i] + G);
	}
	if (L > R) return false;
	return true;
}

int main() {
	cin >> n; int a1 = 0, a2 = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%Lf%Lf", &x[i], &y[i]);
		if (y[i] > 0) a1++; else a2++;
	}
	if (a1 >= 1 && a2 >= 1) { cout << "-1" << endl; return 0; }
	if (a2 >= 1) {
		for (int i = 1; i <= n; i++) y[i] *= -1;
	}

	long double L = 0, R = 0.6e14, M;
	for (int i = 0; i < 130; i++) {
		M = (L + R) / 2;
		bool p1 = solve(M);
		if (p1 == true) R = M;
		else L = M;
	}
	printf("%.12Lf\n", M);
	return 0;
}
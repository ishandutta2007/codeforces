#include <iostream>
#include <cmath>
using namespace std;
#pragma warning (disable: 4996)

const long double PI = 3.14159265358979L;
int N; long double R;

bool solve(long double E) {
	long double x1 = 0, y1 = (R + E);
	long double x2 = (R + E) * sin(360.0L * PI / (180.0L * N));
	long double y2 = (R + E) * cos(360.0L * PI / (180.0L * N));

	long double T = sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (T >= 2.0L * E) return true;
	return false;
}

int main() {
	cin >> N >> R;
	long double L = 0, R = 1000, M;
	for (int i = 0; i < 60; i++) {
		M = (L + R) / 2.0L;
		bool I = solve(M);
		if (I == true) L = M;
		else R = M;
	}
	printf("%.12Lf\n", M);
	return 0;
}
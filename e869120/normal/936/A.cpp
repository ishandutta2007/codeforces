#include <iostream>
using namespace std;

long long K, D, T, A, B;

int main() {
	cin >> K >> D >> T; T *= 2;
	long long C = (K + D - 1) / D;
	C *= D;
	A = K; B = C - A;

	long long E = T / (2LL * A + B);
	long long S = T - E * (2LL * A + B);

	long long score = E*C * 2LL;
	if (S < 2 * A) {
		score += S;
	}
	else {
		score += 2 * A + 2 * (S - 2 * A);
	}
	printf("%.15Lf\n", 0.5L * score);
	return 0;
}
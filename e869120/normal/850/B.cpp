#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = (1 << 20);
long long N, X, Y, A[1 << 21], B1[1 << 21], B2[1 << 21], minx = (1LL << 60);

int main() {
	scanf("%lld%lld%lld", &N, &X, &Y);
	for (int i = 0; i < N; i++) { scanf("%lld", &A[i]); B1[A[i]] += 1; B2[A[i]] += A[i]; }
	for (int i = 1; i < (1 << 21); i++) B1[i] += B1[i - 1];
	for (int i = 1; i < (1 << 21); i++) B2[i] += B2[i - 1];

	int BORDER = (X + Y - 1) / Y;

	for (int i = 2; i < MAX_N; i++) {
		long long ret = 0;
		for (int j = 0; j < MAX_N; j += i) {
			long long E1 = 0; if (i > BORDER) E1 = 1LL * X * (B1[j + i - BORDER] - B1[j]);
			long long E2 = 1LL * (j + i) * (B1[j + i] - B1[max(j, j + i - BORDER)]) - (B2[j + i] - B2[max(j, j + i - BORDER)]); E2 *= Y;
			ret += (E1 + E2);
		}
		minx = min(minx, ret);
	}
	cout << minx << endl;
	return 0;
}
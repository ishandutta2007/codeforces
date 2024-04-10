#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[300009], bits[300009], L1, L2, S, WA;

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		for (int j = 0; j < 60; j++) { if ((A[i] / (1LL << j)) % 2 == 1) bits[i]++; }
	}
	L1 = 1; WA = 0;
	for (int i = 1; i <= N; i++) {
		WA += bits[i]; WA %= 2;
		if (WA == 0) {
			S += L1; L1++;
		}
		if (WA == 1) {
			S += L2; L2++;
		}
	}

	for (int i = 1; i <= N; i++) {
		long long sum = 0, maxn = 0;
		for (int j = i; j <= i + 120; j++) {
			if (j > N) break;
			sum += bits[j]; maxn = max(maxn, bits[j]);
			if (sum < maxn * 2 && (sum & 1) == 0) S--;
		}
	}
	cout << S << endl;
	return 0;
}
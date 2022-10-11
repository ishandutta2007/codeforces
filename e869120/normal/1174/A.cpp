#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 19];

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N * 2; i++) scanf("%lld", &A[i]);
	sort(A, A + N * 2);
	long long S1 = 0, S2 = 0;
	for (int i = 0; i < N; i++) S1 += A[i];
	for (int i = N; i < 2 * N; i++) S2 += A[i];

	if (S1 == S2) {
		cout << "-1" << endl;
	}
	else {
		for (int i = 0; i < N * 2; i++) { if (i) cout << " "; cout << A[i]; } cout << endl;
	}
	return 0;
}
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 19], S;

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) { scanf("%lld", &A[i]); A[i] = abs(A[i]); }
	sort(A, A + N);

	for (int i = 0; i < N; i++) {
		int pos1 = lower_bound(A, A + N, (A[i] + 1LL) / 2LL) - A;
		int pos2 = lower_bound(A, A + N, A[i] * 2LL + 1LL) - A;
		S += 1LL * (pos2 - pos1);
		if (pos1 <= i && i < pos2) S--;
	}
	cout << S / 2LL << endl;
	return 0;
}
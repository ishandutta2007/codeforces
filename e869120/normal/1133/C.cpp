#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 18], maxn = 0;

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
	sort(A, A + N);

	for (int i = 0; i < N; i++) {
		int pos1 = lower_bound(A, A + N, A[i]) - A;
		int pos2 = lower_bound(A, A + N, A[i] + 6LL) - A;
		maxn = max(maxn, 1LL * (pos2 - pos1));
	}
	cout << maxn << endl;
	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, M, K, P, Q, A[1 << 18], B[1 << 18];

int main() {
	scanf("%lld%lld%lld%lld%lld", &N, &M, &P, &Q, &K);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
	for (int i = 0; i < M; i++) scanf("%lld", &B[i]);

	if (N <= K || M <= K) {
		cout << "-1" << endl;
		return 0;
	}

	long long maxn = 0;
	for (int i = 0; i < N; i++) {
		if (i > K) break;
		long long pos1 = A[i] + P;
		long long pos2 = lower_bound(B, B + M, 1LL * pos1) - B; pos2 += (K - i);
		if (pos2 >= M) {
			cout << "-1" << endl;
			return 0;
		}
		long long pos3 = B[pos2] + Q;
		maxn = max(maxn, pos3);
	}
	cout << maxn << endl;
	return 0;
}
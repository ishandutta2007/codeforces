#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, M, A[1 << 19], B[1 << 19], cnts;

int main() {
	scanf("%lld%lld", &N, &M);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
	for (int i = 0; i < M; i++) {
		long long x, l, r; scanf("%lld%lld%lld", &l, &r, &x);
		if (l == 1) { B[cnts] = r; cnts++; }
	}
	sort(A, A + N); A[N] = 1000000000;
	sort(B, B + cnts);

	long long minx = (1LL << 30);
	for (int i = 0; i <= N; i++) {
		int pos1 = lower_bound(B, B + cnts, A[i]) - B;
		minx = min(minx, i + (cnts - pos1));
	}
	cout << minx << endl;
	return 0;
}
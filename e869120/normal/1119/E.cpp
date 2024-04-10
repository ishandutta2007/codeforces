#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 19];

bool solve(long long border) {
	long long cnt = border, c1 = 0;
	for (int i = N - 1; i >= 0; i--) {
		long long max_poss = A[i] / 2;
		if (cnt >= max_poss) { cnt -= max_poss; c1 += max_poss; if (A[i] % 2 == 1 && c1 >= 1) c1--; }
		else {
			long long kosuu = cnt;
			cnt = 0; c1 += kosuu;
			long long rem = A[i] - kosuu * 2;
			c1 -= rem; c1 = max(c1, 0LL);
		}
	}
	if (cnt == 0 && c1 == 0) return true;
	return false;
}

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);

	long long L = 0, R = (1LL << 60), M, maxn = 0;
	for (int i = 0; i < 65; i++) {
		M = (L + R) / 2;
		bool t = solve(M);
		if (t == true) { maxn = max(maxn, M); L = M; }
		else { R = M; }
	}
	cout << maxn << endl;
	return 0;
}
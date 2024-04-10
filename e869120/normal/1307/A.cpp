#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int T;
int N, D, A[1 << 18];

int solve() {
	int rem = D, cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < A[i]; j++) {
			if (rem >= (i - 1)) { rem -= (i - 1); cnt++; }
		}
	}
	return cnt;
}

int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d%d", &N, &D);
		for (int j = 1; j <= N; j++) scanf("%d", &A[j]);
		printf("%d\n", solve());
	}
	return 0;
}
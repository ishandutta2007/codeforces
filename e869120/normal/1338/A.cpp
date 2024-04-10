#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 18];
long long B[1 << 18];

long long solve() {
	B[0] = -(1LL << 60);
	for (int i = 1; i <= N; i++) B[i] = max(B[i - 1], A[i]);

	long long maxv = 0;
	for (int i = 1; i <= N; i++) maxv = max(maxv, B[i] - A[i]);
	for (int i = 0; i <= 60; i++) {
		long long uplim = (1LL << i) - 1;
		if (maxv <= uplim) return i;
	}
	return -1;
}

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		scanf("%lld", &N);
		for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
		printf("%lld\n", solve());
	}
	return 0;
}
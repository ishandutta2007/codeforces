#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long solve(long long a, long long m) {
	long long Answer = 1;
	for (int i = 0; i < 32; i++) {
		long long v = (1LL << i);
		long long w = max(1LL, a - v + 2LL);
		Answer *= min(v + 1LL, w);
		Answer %= m;
	}
	return (Answer + m - 1) % m;
}

int main() {
	long long T, A, M;
	scanf("%lld", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%lld%lld", &A, &M);
		printf("%lld\n", solve(A, M));
	}
	return 0;
}
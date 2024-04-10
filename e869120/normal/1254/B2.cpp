#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 20], B[1 << 20];
long long S;

long long solve(long long r) {
	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		long long p = B[i] % r;
		sum += min(p, r - p);
	}
	return sum;
}

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (int i = 1; i <= N; i++) S += A[i];
	for (int i = 1; i <= N; i++) B[i] = B[i - 1] + A[i];

	vector<long long> R;
	for (long long t = 2; t * t <= S; t++) {
		if (S % t != 0) continue;
		R.push_back(t);
		while (S % t == 0) S /= t;
	}
	if (S >= 2) { R.push_back(S); }

	long long minx = (1LL << 60);
	for (long long i : R) {
		minx = min(minx, solve(i));
	}
	if (minx == (1LL << 60)) minx = -1;
	printf("%lld\n", minx);
	return 0;
}
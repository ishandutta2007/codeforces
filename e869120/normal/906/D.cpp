#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 31; i++) {
		if ((b & (1LL << i)) != 0) {
			p *= q; p %= m;
		}
		q *= q; q %= m;
	}
	return p;
}

long long euler_function(long long x) {
	long long E = 1;
	for (int i = 2; i*i <= x; i++) {
		if (x%i != 0) continue;
		x /= i; E *= (i - 1);
		while (x%i == 0) { x /= i; E *= i; }
	}
	if (x >= 2) { E *= (x - 1); }
	return E;
}

long long N, M, W[1 << 17], Q, L[1 << 17], R[1 << 17];
vector<long long>A;

int main() {
	scanf("%lld%lld", &N, &M);
	for (int i = 1; i <= N; i++) scanf("%lld", &W[i]);

	A.push_back(M);
	while (true) {
		long long B = A[A.size() - 1]; if (B == 1) break;
		A.push_back(euler_function(B));
	}
	A.push_back(1);

	scanf("%lld", &Q);
	for (int i = 1; i <= Q; i++) {
		scanf("%lld%lld", &L[i], &R[i]);
		R[i] = min(L[i] + (long long)A.size() - 2, R[i]);

		long long cx = 1, cy = 1;
		for (int j = R[i]; j >= L[i]; j--) {
			if (cy < 60) cx = modpow(W[j], cy, A[j - L[i]]);
			else cx = modpow(W[j], cx + A[j - L[i] + 1], A[j - L[i]]);

			if (W[j] == 1) cy = 1;
			else if (cy >= 6) cy = (1LL << 60);
			else {
				int t = cy;
				cy = 1;
				for (int k = 0; k < t; k++) {
					cy *= W[j];
					if (cy >= 60) { cy = (1LL << 60); break; }
				}
			}
		}
		printf("%lld\n", cx);
	}
	return 0;
}
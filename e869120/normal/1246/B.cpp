#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, K, A[100009];
long long UPLIMIT;
long long cnt[100009];
map<long long, long long> Map;

void init() {
	if (K >= 35) {
		UPLIMIT = 1;
		Map[1] = 1;
	}
	else {
		for (long long i = 1; i <= 10000000LL; i++) {
			long long r = 1;
			for (int j = 0; j < K; j++) { r *= i; }
			if (r > 100000LL * 100000LL) break;
			Map[r] = 1; if (r <= 100000) UPLIMIT = i;
		}
	}
}

int main() {
	scanf("%lld%lld", &N, &K);
	for (int i = 1; i <= N; i++) { scanf("%lld", &A[i]); cnt[A[i]]++; }
	init();

	long long ans = 0;
	for (int i = 1; i <= 100000; i++) {
		if (Map[1LL * i * i] == 1) { ans += 1LL * cnt[i] * (cnt[i] - 1LL) / 2LL; }
	}

	for (int i = 1; i <= 100000; i++) {
		long long B = 1;

		long long s = i;
		for (int j = 2; j * j <= s; j++) {
			if (s % j != 0) continue;

			// j 
			long long cnts = 0;
			while (s % j == 0) { s /= j; cnts++; }
			cnts %= K;

			if (cnts > 0) {
				for (int t = 0; t < K - cnts; t++) { B *= (1LL * j); B = min(B, 100001LL * 100001LL); }
			}
		}

		// s 
		if (s >= 2) {
			long long cnts = 1;
			for (int j = 0; j < K - cnts; j++) { B *= (1LL * s); B = min(B, 100001LL * 100001LL); }
		}

		if (B <= 100000LL) {
			for (int j = 1; j <= UPLIMIT; j++) {
				long long v = B;
				for (int k = 1; k <= K; k++) { v *= (1LL * j); v = min(v, 100001LL * 100001LL); }
				if (v <= 100000LL && (1LL * i) < v) ans += cnt[i] * cnt[v];
				if (v > 100000LL) break;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
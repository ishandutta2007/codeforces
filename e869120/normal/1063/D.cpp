#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long N, K, L, R, S, maxn = -1;

int main() {
	cin >> N >> L >> R >> K;
	S = (R - L + 1 + N) % N;

	// 1 
	long long B = K / (2LL * N); if (B == 0) B = 1;
	vector<long long>E;
	for (long long i = 2LL * N; i >= 2LL * N - 2000; i--) {
		if (i < N) break;
		for (long long j = 0; j <= 3; j++) E.push_back(K / i + j);
		for (long long j = 0; j <= 3; j++) E.push_back((K + 1) / i + j);
	}
	sort(E.begin(), E.end());
	E.erase(unique(E.begin(), E.end()), E.end());

	for (long long i : E) {
		if (i == 0) continue;
		long long BASE = (1LL * i + 1LL) * S + (1LL * i) * (N - S);
		if (K < BASE) continue;

		long long UPLIMIT_1 = N - S;
		long long UPLIMIT_2 = S;
		long long SA1 = K - BASE;
		long long V1 = SA1 / i;
		long long V2 = SA1 % i; V1 -= V2;
		long long SABUN = V1 - UPLIMIT_1;
		if (SABUN > 0) { long long P = (SABUN + i) / (i + 1); V1 -= 1LL * (i + 1)*P; V2 += 1LL * i*P; }

		if (V1 < 0 || V2 < 0 || V1 > UPLIMIT_1 || V2 > UPLIMIT_2) continue;
		
		long long sum = V1 + V2;
		maxn = max(maxn, sum);
	}

	// 1  K + 1 
	for (long long i : E) {
		if (i == 0) continue;
		long long BASE = (1LL * i + 1LL) * S + (1LL * i) * (N - S);
		if (K + 1 < BASE) continue;

		long long UPLIMIT_1 = N - S;
		long long UPLIMIT_2 = S;
		long long SA1 = K + 1 - BASE;
		long long V1 = SA1 / i;
		long long V2 = SA1 % i; V1 -= V2;
		long long SABUN = V1 - UPLIMIT_1;
		if (SABUN > 0) { long long P = (SABUN + i) / (i + 1); V1 -= 1LL * (i + 1)*P; V2 += 1LL * i*P; }
		if (V2 == 0 && S != 0) { V2 += i; V1 -= (i + 1); }

		if (V1 < 0 || V2 < 0 || V1 > UPLIMIT_1 || V2 > UPLIMIT_2) continue;

		long long sum = V1 + V2;
		maxn = max(maxn, sum);
	}

	// 0 
	if (true) {
		if (K == S) maxn = max(maxn, 1LL + (N - S));
		else if (K > S && K <= 2LL * S) maxn = max(maxn, min(S, K - S + 1) + (N - S));
	}
	cout << maxn << endl;
	return 0;
}
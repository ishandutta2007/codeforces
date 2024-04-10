#include <bits/stdc++.h>
using namespace std;

long long N, dp[1 << 18], prob[1 << 18]; vector<int> X[1 << 18], R[1 << 18];
long long INV = 0, inv[1 << 18], mod = 1000000007;

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 32; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

void init() {
	for (int i = 1; i <= 100000; i++) inv[i] = modpow(i, mod - 2, mod);
	for (int i = 1; i <= 100000; i++) {
		for (int j = i; j <= 100000; j += i) X[j].push_back(i);
	}
	for (int i = 1; i <= 100000; i++) {
		R[i].resize(X[i].size(), 0);
		for (int j = R[i].size() - 1; j >= 0; j--) {
			R[i][j] = N / X[i][j];
			for (int k = j + 1; k < (int)X[i].size(); k++) {
				if (X[i][k] % X[i][j] == 0) R[i][j] -= R[i][k];
			}
		}
	}
}

int main() {
	cin >> N; init(); INV = modpow(N, mod - 2, mod);
	for (int i = 1; i <= N; i++) { dp[i] = INV; prob[i] = INV; }
	for (int i = N; i >= 1; i--) {
		long long S = inv[N - R[i][X[i].size() - 1]]; S *= N; S %= mod;
		//cout << i << " " << S << endl;
		for (int j = 0; j < (int)X[i].size(); j++) {
			if (X[i][j] == i) continue;
			
			long long c1 = N - R[i][X[i].size() - 1], c2 = R[i][j];
			
			long long PROB = prob[i] * (1LL * c2 * inv[c1] % mod) % mod;
			long long AVERAGE = dp[i] * modpow(prob[i], mod - 2, mod) % mod;
			//cout << i << " -> " << X[i][j] << " : prob = " << PROB << ", average = " << AVERAGE << endl;
			prob[X[i][j]] += PROB; prob[X[i][j]] %= mod;
			dp[X[i][j]] += (AVERAGE + S) * PROB; dp[X[i][j]] %= mod;
		}
	}
	//for (int i = 1; i <= N; i++) printf("% 12lld", dp[i]); printf("\n");
	//for (int i = 1; i <= N; i++) printf("% 12lld", prob[i]); printf("\n");
	cout << dp[1] << endl;
	return 0;
}
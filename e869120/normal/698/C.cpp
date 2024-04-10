#include <iostream>
using namespace std;

int N, K; double p[20], dp[1 << 20], ans[1 << 20];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> p[i];

	dp[0] = 1;
	for (int i = 0; i < (1 << N); i++) {
		int bit[20], cnts = 0; for (int j = 0; j < N; j++) { bit[j] = (i / (1 << j)) % 2; cnts += bit[j]; }

		double S = 0; for (int j = 0; j < N; j++) { if (bit[j] == 0) S += p[j]; }

		if (S < 1e-8) S = 1;
		for (int j = 0; j < N; j++) {
			if (bit[j] == 1) continue;
			if (cnts < K) ans[j] += dp[i] * p[j] / S;
			dp[i + (1 << j)] += dp[i] * p[j] / S;
		}
	}
	for (int i = 0; i < N; i++) {
		if (i) cout << " ";
		printf("%.12lf", ans[i]);
	}
	cout << endl;
	return 0;
}
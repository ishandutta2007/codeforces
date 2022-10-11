#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long double C, T, a[1009], dp[109][109][1009], power[1009]; int N, p[1009];

long double maximum_polynomial(double v2, double v1, double v0, double uplim) {
	long double X = -v1 / v2; X /= 2.0L;
	long double E1 = v2 * 0.0L * 0.0L + v1 * 0.0L + v0;
	long double E2 = v2 * uplim * uplim + v1 * uplim + v0;
	long double E3 = -1e9; if (0.0L < X && X < uplim) E3 = v2 * X * X + v1 * X + v0;
	return max({ E1, E2, E3 });
}

int solve() {
	power[0] = 0.9L; for (int i = 1; i <= 100; i++) power[i] = power[i - 1] * 0.9L;
	for (int i = 0; i <= 100; i++) { for (int j = 0; j <= i; j++) { for (int k = 0; k <= i * 10; k++) dp[i][j][k] = 1e16; } }
	
	int SS = 0; dp[0][0][0] = 0.0L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= SS; k++) {
				dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
				dp[i + 1][j + 1][k + p[i + 1]] = min(dp[i + 1][j + 1][k + p[i + 1]], dp[i][j][k] + a[i + 1] / power[j]);
			}
		}
		SS += p[i + 1];
	}

	int ans = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= SS; j++) {
			if (T - 10.0L*i < -1e-9) continue;
			long double V = maximum_polynomial(-C, C*(T - 10.0L * i) + 1.0L, 0.0L, 1.0L * T - 10.0L * i);
			if (dp[N][i][j] <= V) {
				ans = max(ans, j);
			}
		}
	}
	return ans;
}

int main() {
	int TESTCASES; cin >> TESTCASES;
	for (int t = 1; t <= TESTCASES; t++) {
		cin >> N >> C >> T;
		for (int i = 1; i <= N; i++) cin >> a[i] >> p[i];

		vector<pair<int, int>> vec;
		for (int i = 1; i <= N; i++) vec.push_back(make_pair(a[i], p[i]));
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());

		for (int i = 0; i < vec.size(); i++) { a[i + 1] = vec[i].first; p[i + 1] = vec[i].second; }

		cout << solve() << endl;
	}
	return 0;
}
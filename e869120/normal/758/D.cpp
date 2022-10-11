#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long dp[70][70], n, power[70], r; string S;
int main() {
	cin >> n >> S; power[0] = 1; for (int i = 0; i < 4900; i++)dp[i / 70][i % 70] = 1LL << 62; dp[0][S.size()] = 0;
	for (int i = 1; i < S.size(); i++) {
		if (((1LL << 62) / n) < power[i - 1]) { r = i; break; }
		power[i] = power[i - 1] * n;
	}
	if (r == 0)r = S.size();
	for (int i = 0; i < r; i++) {
		for (int j = S.size(); j >= 1; j--) {
			for (int k = 1; k < 10; k++) {
				if (j - k < 0)break;
				long long Y = stoll(S.substr(j - k, k));
				if (S[j - k] == '0' && k >= 2)continue;

				if (((1LL << 62) / power[i]) < Y || Y >= n)continue;
				dp[i + 1][j - k] = min(dp[i + 1][j - k], dp[i][j] + Y*power[i]);
			}
		}
	}
	long long minx = 1LL << 62; for (int i = 0; i <= r; i++) { minx = min(minx, dp[i][0]); }
	cout << minx << endl;
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int dp[77][1 << 19], cnt[77], n, power2[100009], mod = 1000000007;
vector<int>vec = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67 };

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a; cnt[a]++;
	}
	power2[0] = 1; for (int i = 1; i <= 100000; i++) power2[i] = (power2[i - 1] * 2) % mod;

	dp[0][0] = 1;
	for (int i = 1; i <= 70; i++) {
		int S = 0, L = i; for (int j = 0; j < vec.size(); j++) { while (L%vec[j] == 0) { S ^= (1 << j); L /= vec[j]; } }

		int A = 1, B = 0; if (cnt[i] >= 1) { A = power2[cnt[i] - 1]; B = A; }

		for (int k = 0; k < (1 << 19); k++) {
			dp[i][k] += (1LL * dp[i - 1][k] * A) % mod; dp[i][k] %= mod;
			dp[i][k^S] += (1LL * dp[i - 1][k] * B) % mod; dp[i][k^S] %= mod;
		}
	}
	cout << (dp[70][0] + mod - 1) % mod << endl;
	return 0;
}
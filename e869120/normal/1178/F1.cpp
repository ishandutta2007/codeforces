#include <iostream>
#include <algorithm>
using namespace std;

const long long mod = 998244353;
long long N, M, C[1 << 18], dp[509][509];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> C[i];
	for (int i = 1; i <= N + 1; i++) dp[i][i - 1] = 1;

	for (int i = 0; i <= N; i++) {
		for (int j = 1; j <= N - i; j++) {
			int cl = j, cr = j + i;

			pair<int, int> minx = make_pair(1 << 30, -1);
			for (int k = cl; k <= cr; k++) minx = min(minx, make_pair((int)C[k], k));

			int pos = minx.second;

			long long get_left = 0;
			for (int k = cl; k <= pos; k++) {
				get_left += dp[cl][k - 1] * dp[k][pos - 1];
				get_left %= mod;
			}
			long long get_right = 0;
			for (int k = pos; k <= cr; k++) {
				get_right += dp[pos + 1][k] * dp[k + 1][cr];
				get_right %= mod;
			}
			dp[cl][cr] = (get_left * get_right % mod);
		}
	}
	cout << dp[1][N] << endl;
	return 0;
}
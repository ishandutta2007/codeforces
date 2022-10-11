#include <iostream>
#include <string>
using namespace std;

long long dp[2009][2009][2][2], M, D, mod = 1000000007; string A, B;

int main() {
	cin >> M >> D >> A >> B;
	dp[0][0][1][1] = 1;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					for (int m = 0; m < 10; m++) {
						if (i % 2 == 0 && m == D) continue;
						if (i % 2 == 1 && m != D) continue;

						int n1 = 0, n2 = 0;
						if (k == 1 && (A[i] - '0') > m) continue; else if (k == 1 && (A[i] - '0') == m) n1 = 1;
						if (l == 1 && (B[i] - '0') < m) continue; else if (l == 1 && (B[i] - '0') == m) n2 = 1;

						dp[i + 1][(j * 10 + m) % M][n1][n2] += dp[i][j][k][l];
						dp[i + 1][(j * 10 + m) % M][n1][n2] %= mod;
					}
				}
			}
		}
	}
	long long ret = 0; for (int i = 0; i < 4; i++) ret += dp[A.size()][0][i / 2][i % 2];
	cout << ret%mod << endl;
	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

const long long mod = 1000000007;
int N, X[55], A[1 << 20], B[1 << 20], C[1 << 20], D[1 << 20], E[55][55][55][55], cnts;
long long dp[55][316251 + 10], nr[55][55];

void init() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= N; k++) {
				for (int l = 0; l <= N - i - j - k; l++) {
					A[cnts] = i; B[cnts] = j; C[cnts] = k; D[cnts] = l;
					E[i][j][k][l] = cnts;
					cnts++;
				}
			}
		}
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == 0 || j == 0) nr[i][j] = 1;
			else nr[i][j] = (nr[i - 1][j] + nr[i][j - 1]) % mod;
		}
	}
}

long long ncr(int n, int r) {
	if (r < 0 || n < r) return 0;
	return nr[r][n - r];
}

int get_s(int A1, int B1, int C1, int D1) {
	return E[A1][B1][C1][D1];
}

void solve(int pos, int p1, int p2, int p3, int p4) {
	//cout << pos << " " << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
	int id = get_s(p1, p2, p3, p4);

	// 
	if (p1 == 0 && p2 == 0) {
		for (int i = 0; i <= min(p3, X[pos + 1]); i++) {
			for (int j = 0; j <= min(p4, X[pos + 1] - i); j++) {
				if (i + j != 1) continue;
				long long E1 = ncr(p3, i) * ncr(p4, j);
				int deg = X[pos + 1] - i - j;
				if (deg == 0) { dp[pos + 1][get_s(p3 - i + j, p4 - j, 0, 0)] += dp[pos][id] * E1; dp[pos + 1][get_s(p3 - i + j, p4 - j, 0, 0)] %= mod; }
				if (deg == 1) { dp[pos + 1][get_s(p3 - i + j, p4 - j, 1, 0)] += dp[pos][id] * E1; dp[pos + 1][get_s(p3 - i + j, p4 - j, 1, 0)] %= mod; }
				if (deg == 2) { dp[pos + 1][get_s(p3 - i + j, p4 - j, 0, 1)] += dp[pos][id] * E1; dp[pos + 1][get_s(p3 - i + j, p4 - j, 0, 1)] %= mod; }
			}
		}
	}

	// 
	if (p1 >= 1 || p2 >= 1) {
		for (int i = 0; i <= min(p1, X[pos + 1]); i++) {
			for (int j = 0; j <= min(p2, X[pos + 1] - i); j++) {
				if (i + j != 1) continue;
				for (int k = 0; k <= min(p3, X[pos + 1] - i - j); k++) {
					for (int l = 0; l <= min(p4, X[pos + 1] - i - j - k); l++) {
						long long E1 = ncr(p1, i) * ncr(p2, j) * ncr(p3, k) * ncr(p4, l);
						int r1 = p1 - i + j, r2 = p2 - j, r3 = p3 - k + l, r4 = p4 - l, deg = X[pos + 1] - i - j - k - l;
						if (deg == 1) r3++; if (deg == 2) r4++;

						dp[pos + 1][get_s(r1, r2, r3, r4)] += dp[pos][id] * E1;
						dp[pos + 1][get_s(r1, r2, r3, r4)] %= mod;
					}
				}
			}
		}
	}
}

int main() {
	cin >> N; init();
	for (int i = 1; i <= N; i++) cin >> X[i];

	int r1 = 0, r2 = 0, r3 = 0, r4 = 0;
	if (X[1] == 2) r1++; else r2++;
	if (X[2] == 2) r3++; else r4++;
	dp[2][get_s(r1, r2, r3, r4)] = 1;
	for (int i = 2; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= i - j; k++) {
				for (int l = 0; l <= i - j - k; l++) {
					for (int m = 0; m <= i - j - k - l; m++) {
						if (dp[i][get_s(j, k, l, m)] == 0) continue;
						solve(i, j, k, l, m);
					}
				}
			}
		}
	}
	cout << dp[N][get_s(0, 0, 0, 0)] << endl;
	return 0;
}
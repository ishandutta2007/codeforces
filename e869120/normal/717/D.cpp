#include<iostream>
using namespace std;
long double dp[64][130], ret[64][130]; long long n, x;
int main() {
	cin >> n >> x;
	for (int i = 0; i <= x; i++)cin >> dp[0][i];
	for (int i = 1; i < 64; i++) {
		for (int j = 0; j < 128; j++) {
			for (int k = 0; k < 128; k++)dp[i][j^k] += dp[i - 1][j] * dp[i - 1][k];
		}
	}
	ret[0][0] = 1;
	for (int i = 0; i < 60; i++) {
		if ((n / (1LL << i)) % 2 == 0) { for (int j = 0; j < 128; j++)ret[i + 1][j] = ret[i][j]; }
		else {
			for (int j = 0; j < 128; j++) {
				for (int k = 0; k < 128; k++)ret[i + 1][j^k] += ret[i][j] * dp[i][k];
			}
		}
	}
	printf("%.24Lf\n", 1.0L - ret[60][0]);
	return 0;
}
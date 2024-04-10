#include <iostream>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

long long dp[1000009], c[10][1000009];

int main() {
	for (int i = 0; i <= 9; i++) dp[i] = i;
	for (int i = 10; i <= 1000000; i++) {
		string str = to_string(i);
		long long z = 1; for (int j = 0; j < str.size(); j++) { if (str[j] != '0') z *= (str[j] - '0'); }
		dp[i] = dp[z];
	}
	for (int i = 1; i <= 1000000; i++) c[dp[i]][i]++;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 1000000; j++) c[i][j] += c[i][j - 1];
	}

	long long Q, L, R, K;
	scanf("%lld", &Q);
	for (int i = 1; i <= Q; i++) {
		scanf("%lld%lld%lld", &L, &R, &K);
		printf("%lld\n", c[K][R] - c[K][L - 1]);
	}
	return 0;
}
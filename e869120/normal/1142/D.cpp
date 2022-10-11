#include <iostream>
#include <string>
using namespace std;

long long dp[100009][11], L[11] = { 0, 10, 0, 2, 5, 9, 3, 9, 5, 2, 0 };
string S;

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] != '0') dp[i + 1][(S[i] - '0')] += 1;
		for (int j = 1; j < 11; j++) {
			if ((S[i] - '0') >= j || dp[i][j] == 0) continue;
			dp[i + 1][((S[i] - '0') + L[j]) % 11] += dp[i][j];
		}
	}
	long long sum = 0;
	for (int i = 0; i <= S.size(); i++) {
		for (int j = 0; j < 11; j++) sum += dp[i][j];
	}
	cout << sum << endl;
	return 0;
}
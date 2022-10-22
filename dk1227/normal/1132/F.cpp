#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int dp[505][505];
char s[505];

int main() {
	memset(dp, 0x3f, sizeof(dp));
	int len;
	cin >> len;
	scanf("%s", s);
	for (int i = 1; i <= len; i++) 
		dp[i][i] = 1;
	for (int i = 1; i <= len; i++) 
		for (int j = i; j; j--) {
			if(i == j) continue;
			for (int k = j; k < i; k++)
				dp[j][i] = min(dp[j][i], dp[j][k] + dp[k + 1][i] - (s[i - 1] == s[j - 1]));
		}
	cout << dp[1][len];
	return 0;
}
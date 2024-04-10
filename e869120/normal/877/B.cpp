#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<ctime>
using namespace std;
#pragma warning(disable: 4996)

string S; int dp[5009][2];
int main() {
	cin >> S;
	int maxn = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'a') { dp[i + 1][0] = dp[i][0] + 1; dp[i + 1][1] = dp[i][1]; }
		if (S[i] == 'b') { dp[i + 1][0] = dp[i][0]; dp[i + 1][1] = dp[i][1] + 1; }
	}
	for (int i = 0; i <= S.size(); i++) {
		for (int j = i; j <= S.size(); j++)maxn = max(maxn, dp[i][0] + dp[j][1] - dp[i][1] + dp[S.size()][0] - dp[j][0]);
	}
	cout << maxn << endl;
	return 0;
}
#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int dp[1 << 21][5];
int pres[1 << 21][5];

void solve(string S) {
	string T = ""; vector<int> vec;
	for (int i = 0; i <= S.size(); i++) {
		for (int j = 0; j < 5; j++) dp[i][j] = (1 << 30);
	}

	dp[0][0] = 0;
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < 5; j++) {
			if (dp[i + 1][j] > dp[i][j] + 1) {
				dp[i + 1][j] = dp[i][j] + 1;
				pres[i + 1][j] = j;
			}
		}
		for (int j = 0; j < 5; j++) {
			if (j == 2 && S[i] == 'e') continue;
			if (j == 4 && S[i] == 'o') continue;
			int nex = 0;
			if (S[i] == 'o') nex = 1; if (j == 1 && S[i] == 'n') nex = 2;
			if (S[i] == 't') nex = 3; if (j == 3 && S[i] == 'w') nex = 4;
			if (dp[i + 1][nex] > dp[i][j]) {
				dp[i + 1][nex] = dp[i][j];
				pres[i + 1][nex] = j;
			}
		}
	}
	
	int minx = (1 << 30), idx = 0;
	for (int i = 0; i < 5; i++) {
		if (minx > dp[S.size()][i]) {
			minx = dp[S.size()][i];
			idx = i;
		}
	}
	for (int i = S.size() - 1; i >= 0; i--) {
		int cx = pres[i + 1][idx];
		if (dp[i + 1][idx] != dp[i][cx]) vec.push_back(i);
		idx = cx;
	}
	reverse(vec.begin(), vec.end());

	printf("%d\n", (int)vec.size());
	for (int i = 0; i < vec.size(); i++) {
		if (i) printf(" ");
		printf("%d", vec[i] + 1);
	}
	printf("\n");
}

int T;
char c[1 << 22];

int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%s", &c); string S = "";
		for (int j = 0; j < (1 << 22); j++) {
			S += c[j];
			if (c[j] == 0) break;
			c[j] = 0;
		}
		solve(S);
	}
	return 0;
}
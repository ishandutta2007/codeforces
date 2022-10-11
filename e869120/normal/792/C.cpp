#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
string S; pair<int, int> dp[100005][3][2];
int solve(int pos, int rec1, int rec2) {
	if (pos == S.size()) {
		if (rec1 == 0 && rec2 == 1)return 0;
		return 999999999;
	}
	if (dp[pos][rec1][rec2].first >= 0)return dp[pos][rec1][rec2].first;
	int minx = 999999999, minid = 0;
	minx = min(minx, solve(pos + 1, rec1, rec2) + 1);

	if (rec2 == 0 && S[pos] != '0') {
		int U = solve(pos + 1, (rec1 + (S[pos] - '0')) % 3, 1);
		if (minx > U) { minx = U; minid = 1; }
	}
	if (rec2 == 1) {
		int U = solve(pos + 1, (rec1 + (S[pos] - '0')) % 3, 1);
		if (minx > U) { minx = U; minid = 1; }
	}
	dp[pos][rec1][rec2] = make_pair(minx, minid);
	return minx;
}
int main() {
	cin >> S;
	for (int i = 0; i < 100005; i++) { for (int j = 0; j < 3; j++) { for (int k = 0; k < 2; k++)dp[i][j][k].first = -1; } }
	int ret = solve(0, 0, 0);
	if (ret >= 99999999) {
		bool OK = true;
		for (int i = 0; i < S.size(); i++) { if (S[i] == '0')OK = false; }
		if (OK == true)cout << "-1" << endl; else cout << "0" << endl;
	}
	else {
		string Y = ""; int cx = 0, cy = 0;
		for (int i = 0; i < S.size(); i++) {
			if (dp[i][cx][cy].second == 1) {
				cx += S[i] - '0'; cx %= 3; cy = 1; Y += S[i];
			}
		}
		cout << Y << endl;
	}
	return 0;
}
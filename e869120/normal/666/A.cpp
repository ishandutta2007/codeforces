#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string S; int dp[10005][4];
int main() {
	cin >> S;
	dp[S.size() - 2][2] = 1; dp[S.size() - 3][3] = 1;
	for (int i = S.size() - 1; i >= 0; i--) {
		if (dp[i + 3][2] == 1)dp[i][3] = 1;
		if (dp[i + 2][3] == 1)dp[i][2] = 1;
		if (dp[i + 3][3] == 1) { if (S.substr(i, 3) != S.substr(i + 3, 3))dp[i][3] = 1; }
		if (dp[i + 2][2] == 1) { if (S.substr(i, 2) != S.substr(i + 2, 2))dp[i][2] = 1; }
	}
	vector<string>V;
	for (int i = 5; i < S.size(); i++) {
		if (dp[i][2] == 1)V.push_back(S.substr(i, 2));
		if (dp[i][3] == 1)V.push_back(S.substr(i, 3));
	}
	sort(V.begin(), V.end()); V.erase(unique(V.begin(), V.end()), V.end());
	cout << V.size() << endl; for (int i = 0; i < V.size(); i++)cout << V[i] << endl;
	return 0;
}
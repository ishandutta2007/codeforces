#include<iostream>
#include<string>
using namespace std;
int dp[205][205][205];
void solve(int a1, int a2, int a3) {
	if (a1 < 0 || a2 < 0 || a3 < 0)return;
	if (dp[a1][a2][a3] == 1)return;
	dp[a1][a2][a3] = 1;
	solve(a1 + 1, a2 - 1, a3 - 1);
	solve(a1 - 1, a2 + 1, a3 - 1);
	solve(a1 - 1, a2 - 1, a3 + 1);
	if (a1 >= 2)solve(a1 - 1, a2, a3);
	if (a2 >= 2)solve(a1, a2 - 1, a3);
	if (a3 >= 2)solve(a1, a2, a3 - 1);
}
int main() {
	string S; int a1 = 0, a2 = 0, a3 = 0, n;
	cin >> n >> S; for (int i = 0; i < S.size(); i++) { if (S[i] == 'B')a1++; if (S[i] == 'G')a2++; if (S[i] == 'R')a3++; }
	solve(a1, a2, a3);
	if (dp[1][0][0] == 1)cout << "B"; if (dp[0][1][0] == 1)cout << "G"; if (dp[0][0][1] == 1)cout << "R"; cout << endl;
	return 0;
}
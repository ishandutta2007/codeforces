#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
string S; int sz, hush[5003][5003], a[5003], dp[5003][5003]; bool pal[5003][5003];
int dfs(int L, int R) {
	if (pal[L][R] == false) { dp[L][R] = 0; return 0; }
	if (L == R) { dp[L][R] = 1; return 1; }
	if (dp[L][R] >= 0)return dp[L][R];
	dp[L][R] = 0; if (pal[L][R] == true)dp[L][R] = 1;
	int G = (R - L + 1) / 2;
	int v = dfs(L, L + G - 1), w = dfs(R - G + 1, R);
	if (hush[L][L + G - 1] == hush[R - G + 1][R]) { dp[L][R] = min(v, w) + 1; }
}
void pals(int L, int R) {
	if (L < 0 || R >= sz)return;
	if (S[L] == S[R]) { 
		pal[L][R] = true; pals(L - 1, R + 1);
	}
}
int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		long long I = 1, J = 0;
		for (int j = i; j < S.size(); j++) {
			J += 1LL * I*(S[j] - 'a'); hush[i][j] = J; I *= 26;
		}
	}
	sz = S.size();
	for (int i = 0; i < S.size(); i++) {
		pals(i, i); pals(i, i + 1);
	}
	for (int i = 0; i < 5001; i++) { for (int j = 0; j < 5001; j++)dp[i][j] = -1; }
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < S.size(); j++) {
			int F = i + j; if (F < S.size())dfs(j, F);
		}
	}
	for (int i = 0; i < 5001; i++) { for (int j = 0; j < 5001; j++) { if (dp[i][j] >= 0)a[dp[i][j]]++; } }
	for (int i = 5000; i >= 0; i--)a[i] += a[i + 1];
	for (int i = 1; i <= S.size(); i++) { if (i >= 2)cout << ' '; cout << a[i]; }cout << endl;
	return 0;
}
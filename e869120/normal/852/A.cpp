#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<ctime>
#include<random>
using namespace std;
int n, c; string S; __int8 dp[200009][1211];
int main() {
	cin >> n >> S;
	for (int i = 0; i < S.size(); i++) { c += (S[i] - '0'); }
	dp[0][0] = 3;
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j <= 1200; j++) {
			if (dp[i][j] == 0)continue;
			//1: You can do if you don't connect 2: You can do if you connect
			dp[i + 2][j + (S[i] - '0')] = 2; dp[i + 1][j] = 1;
		}
	}
	for (int i = 0; i <= 1200; i++) {
		if (dp[S.size()][i] == 0)continue;
		string U = to_string(c + i * 9);
		for (int j = 0; j < (1 << (U.size() - 1)); j++) {
			vector<string>V; string W = "";
			for (int k = 0; k < U.size(); k++) {
				W += U[k]; if (k == U.size() - 1 || (j / (1 << k)) % 2 == 1) { V.push_back(W); W = ""; }
			}
			int J = 0; for (int k = 0; k < V.size(); k++)J += stoi(V[k]);
			string Y = to_string(J);
			int JJ = 0; for (int k = 0; k < Y.size(); k++)JJ += (Y[k] - '0');
			if (JJ <= 9) {
				//The answer found!
				int cx = S.size(), cy = i; vector<int>F;
				while (cx > 0) {
					if (dp[cx][cy] == 1) { cx--; }
					else {
						cx -= 2; cy -= (S[cx] - '0');
					}
					F.push_back(cx);
				}
				reverse(F.begin(), F.end());
				for (int k = 0; k < F.size(); k++) { if (k)cout << "+"; int E = S.size(); if (k != F.size() - 1)E = F[k + 1]; cout << S.substr(F[k], E - F[k]); }cout << endl;
				for (int k = 0; k < V.size(); k++) { if (k)cout << "+"; cout << V[k]; }cout << endl;
				for (int k = 0; k < Y.size(); k++) { if (k)cout << "+"; cout << Y[k]; }cout << endl;
				return 0;
			}
		}
	}
	cout << "-1" << endl;
	return 0;
}
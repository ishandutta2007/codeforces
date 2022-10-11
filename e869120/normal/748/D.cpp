#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
map<string, vector<pair<int, int>>>M; map<string, int>M2, M3; vector<pair<int, int>>x, y;
int n, m, u[100000]; string S[100000]; bool used[100000];
bool ispalindrome(string S) {
	for (int i = 0; i < S.size() / 2; i++) {
		if (S[i] != S[S.size() - 1 - i])return false;
	}
	return true;
}
string rev(string Y) {
	reverse(Y.begin(), Y.end());
	return Y;
}
int main() {
	cin >> n >> m; int ret = 0, maxn = 0;
	for (int i = 0; i < n; i++) {
		cin >> S[i] >> u[i]; M[S[i]].push_back(make_pair(u[i], i));
	}
	for (int i = 0; i < n; i++) {
		if (M2[S[i]] == 1)continue;
		M2[S[i]] = 1; sort(M[S[i]].begin(), M[S[i]].end(), greater<pair<int, int>>());
	}
	for (int i = 0; i < n; i++) {
		if (M3[S[i]] == 1)continue;
		M3[S[i]] = 1; M3[rev(S[i])] = 1;
		if (S[i] == rev(S[i])) {
			for (int j = 0; j < (int)M[S[i]].size() - 1; j += 2) {
				int R1 = M[S[i]][j].first, S1 = M[S[i]][j].second;
				int R2 = M[S[i]][j + 1].first, S2 = M[S[i]][j + 1].second;
				if (R2 >= 1) { used[S1] = true; used[S2] = true; ret += R1 + R2; }
				else if (R1 >= 1) { y.push_back(make_pair(R1, max(0, R1 + R2))); }
			}
			if (M[S[i]].size() % 2 == 1) {
				int R1 = M[S[i]][M[S[i]].size() - 1].first;
				if (R1 >= 1) { y.push_back(make_pair(R1, 0)); }
			}
		}
		else {
			for (int j = 0; j < min(M[S[i]].size(), M[rev(S[i])].size()); j++) {
				int R1 = M[S[i]][j].first, S1 = M[S[i]][j].second;
				int R2 = M[rev(S[i])][j].first, S2 = M[rev(S[i])][j].second;
				if (R1 + R2 >= 1) { used[S1] = true; used[S2] = true; ret += R1 + R2; }
			}
		}
	}
	for (int i = 0; i < y.size(); i++) ret += y[i].second;
	for (int i = 0; i < y.size(); i++) maxn = max(maxn, y[i].first - y[i].second);
	ret += maxn;
	cout << ret << endl;
	return 0;
}
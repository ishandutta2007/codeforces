#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int T, N, K, A[2009];
string S;

void solve() {
	string T = "";
	for (int i = 0; i < K - 1; i++) T += "()";
	for (int i = 0; i < (N / 2) - (K - 1); i++) T += "(";
	for (int i = 0; i < (N / 2) - (K - 1); i++) T += ")";
	for (int i = 0; i < N; i++) A[i] = -1;

	for (int i = 0; i < T.size(); i++) {
		for (int j = 0; j < S.size(); j++) {
			if (S[j] == T[i] && A[j] == -1) { A[j] = i; break; }
		}
	}

	vector<pair<int, int>> ans;
	for (int i = 0; i < N; i++) {
		int pos = -1;
		for (int j = 0; j < N; j++) {
			if (A[j] == i) pos = j;
		}
		ans.push_back(make_pair(i, pos));
		reverse(A + i, A + pos + 1);
		reverse(S.begin() + i, S.begin() + pos + 1);
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
}

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> K >> S;
		solve();
	}
	return 0;
}
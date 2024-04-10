#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int N, P[1 << 18], C[1 << 18], dp[1 << 18], root;
int Answer[1 << 18];
vector<int> X[1 << 18];

void dfs(int pos) {
	dp[pos] = 1;
	for (int i : X[pos]) {
		dfs(i);
		dp[pos] += dp[i];
	}
}

void dfs2(int pos, vector<int> S) {
	Answer[pos] = S[C[pos]];
	vector<int> SS;
	for (int i = 0; i < S.size(); i++) { if (i != C[pos]) SS.push_back(S[i]); }

	int cnts = 0;
	for (int i : X[pos]) {
		vector<int> U;
		for (int j = 0; j < dp[i]; j++) {
			U.push_back(SS[cnts]);
			cnts++;
		}
		dfs2(i, U);
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i] >> C[i];
		if (P[i] != 0) X[P[i]].push_back(i);
		if (P[i] == 0) root = i;
	}
	dfs(root);
	for (int i = 1; i <= N; i++) {
		if (C[i] >= dp[i]) { cout << "NO" << endl; return 0; }
	}

	vector<int> T; for (int i = 1; i <= N; i++) T.push_back(i);
	dfs2(root, T);

	cout << "YES" << endl;
	for (int i = 1; i <= N; i++) { if (i >= 2) cout << " "; cout << Answer[i]; } cout << endl;
	return 0;
}
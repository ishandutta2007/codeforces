#include <bits/stdc++.h>

using namespace std;

string S[555];
int n, m;

void tc() {
	int i, j;

	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> S[i];
	}

	for (i = 0; i < n; i += 3) {
		for (j = 0; j < m; j++) {
			S[i][j] = 'X';
		}
		if (i) {
			for (j = 0; j < m; j++) {
				if (S[i - 1][j] == 'X' || S[i - 2][j] == 'X') {
					S[i - 1][j] = S[i - 2][j] = 'X';
					break;
				}
			}
			if (j == m) S[i - 1][0] = S[i - 2][0] = 'X';
		}
	}

	if (n % 3 == 0) {
		for (j = 0; j < m; j++) {
			if (S[n - 1][j] == 'X') S[n - 2][j] = 'X';
		}
	}

	for (i = 0; i < n; i++) {
		cout << S[i] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
//*
	cin >> t;
/*/
	t = 1;
//*/
	for (; t--; tc());

	return 0;
}
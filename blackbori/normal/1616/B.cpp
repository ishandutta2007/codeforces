#include <bits/stdc++.h>

using namespace std;

string S;

void tc() {
	int n, i, j;
	cin >> n >> S;
	if (n == 1) {
		cout << S << S << "\n";
		return;
	}
	i = 0;
	if (S[i] > S[i + 1]) {
		for (; i < n; i++) {
			if (i + 1 < n && S[i] < S[i + 1]) break;
		}
	}
	if (i == n) i--;
	for (j = 0; j <= i; j++) cout << S[j];
	for (j = i; j >= 0; j--) cout << S[j];
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}
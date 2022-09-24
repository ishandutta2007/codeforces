#include <bits/stdc++.h>

using namespace std;

void tc() {
	int n, k, i, j;
	cin >> n >> k;
	if (k + k - 1 > n) {
		cout << "-1\n";
		return;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j && (i % 2 == 0) && i < k + k) {
				cout << "R";
			}
			else cout << ".";
		}
		cout << "\n";
	}
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
#include <bits/stdc++.h>

using namespace std;

int A[11], n;

void tc() {
	int i, j, l, c;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (i = 1; i < 1 << n; i++) {
		for (j = i; j; j = j - 1 & i) {
			for (l = c = 0; l < n; l++) {
				if (i & 1 << l) {
					if (j & 1 << l) c -= A[l];
					else c += A[l];
				}
			}
			if (c == 0) {
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; tc());
	
	return 0;
}
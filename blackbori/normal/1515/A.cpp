#include <bits/stdc++.h>

using namespace std;

int A[1010];

void tc() {
	int n, i, x, s;
	cin >> n >> x;

	for (i = 1; i <= n; i++) {
		cin >> A[i];
	}

	for (i = 1, s = 0; i <= n; i++) {
		s += A[i];
		if (x == s) break;
	}

	if (i == n) {
		cout << "NO\n";
		return;
	}

	if (i < n) swap(A[i], A[i + 1]);

	cout << "YES\n";
	for (i = 1; i <= n; i++) {
		cout << A[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; ) tc();

	return 0;
}
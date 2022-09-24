#include <bits/stdc++.h>

using namespace std;

int A[2020];

void tc() {
	int n, i, a;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> A[i];
	}
	a = A[n] - A[1];
	for (i = 1; i <= n; i++) {
		a = max(a, A[i] - A[1]);
		a = max(a, A[n] - A[i]);
	}
	for (i = 2; i <= n; i++) {
		a = max(a, A[i - 1] - A[i]);
	}
	cout << a << "\n";
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
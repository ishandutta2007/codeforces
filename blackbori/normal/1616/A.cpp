#include <bits/stdc++.h>

using namespace std;

int A[111], C[111];

void tc() {
	fill(C, C + 110, 0);
	int n, i, a;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> A[i];
		A[i] = abs(A[i]);
		C[A[i]]++;
	}
	a = !!C[0];
	for (i = 1; i <= 100; i++) {
		a += min(2, C[i]);
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
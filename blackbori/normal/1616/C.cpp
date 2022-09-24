#include <bits/stdc++.h>

using namespace std;

int A[77];

void tc() {
	int n, a, i, j, c, l, v;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> A[i];
	}
	a = n - 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; j < i; j++) {
			c = 0;
			for (l = 1; l <= n; l++) {
				v = A[j] * (l - i) + A[i] * (j - l);
				if (A[l] * (j - i) != v) c++;
			}
			a = min(a, c);
		}
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
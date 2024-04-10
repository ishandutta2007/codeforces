#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll A[101010];

void tc() {
	ll n, k, i, j;
	cin >> n >> k;

	if (n <= 62 && ((1ll << n - 1) < k)) {
		cout << "-1\n";
		return;
	}

	fill(A, A + n + 1, 0);

	k--;

	for (i = 1; i <= n; i++) {
		if (n - i <= 62 && (k & (1ll << n - i))) {
			for (j = i; A[j - 1] > A[j]; j--) {
				A[j] = A[j - 1];
			}
			A[j] = i;
		}
		else A[i] = i;
	}

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
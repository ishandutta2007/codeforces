#include <bits/stdc++.h>

using namespace std;

int A[10101], C[111], D[111], X[111], Y[111];
int n, k;

void tc() {
	int i, j, l, t, c;
	cin >> n >> k;
	for (i = 1; i <= n * k; i++) {
		cin >> A[i];
	}
	t = (n + k - 2) / (k - 1);
	for (i = 1; i <= n * k; i = j) {
		fill(D, D + n + 1, 0);
		for (j = i, c = 0; j <= n * k; j++) {
			if (!C[A[j]]) {
				D[A[j]]++;
				if (D[A[j]] == 1) X[A[j]] = j;
				if (D[A[j]] == 2) Y[A[j]] = j;
			}
			if (D[A[j]] == 2) c++;
			if (c >= t) break;
		}
		for (l = 1; l <= n; l++) {
			if (D[l] >= 2 && !C[l]) {
				C[l] = 1;
			}
		}
	}
	for (i = 1; i <= n; i++) {
		assert(C[i]);
		cout << X[i] << " " << Y[i] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

//	cin >> t;

	for (; t--; tc());
	
	return 0;
}
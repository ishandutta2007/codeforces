#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll D[444][444], C[444][444], K[444];
ll n, m, a;

void tc() {
	ll i, j, k;
	cin >> n >> m;

	for (C[0][0] = i = 1; i <= n + 10; i++) {
		for (C[i][0] = j = 1; j <= i; j++) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % m;
		}
	}

	K[0] = K[1] = 1;
	for (i = 2; i <= n + 1; i++) {
		K[i] = K[i - 1] * 2 % m;
	}

	D[0][0] = 1;
	for (i = 2; i <= n + 1; i++) {
		for (j = 1; j <= i; j++) {
			for (k = 2; k <= j + 1; k++) {
				D[i][j] = (D[i][j] + D[i - k][j - (k - 1)] * K[k - 1] % m * C[j][k - 1]) % m;
			}

			if (i == n + 1) {
				a = (a + D[i][j]) % m;
			}
		}
	}

	cout << a << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

//	cin >> t;

	for (; t--; ) tc();

	return 0;
}
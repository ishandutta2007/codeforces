#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 998244353;

ll D[202020], K[202020], X[202020], Y[202020];
ll n;

void tc() {
	ll i, j, t;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> X[i] >> Y[i] >> t;
		j = lower_bound(X + 1, X + i, Y[i]) - X - 1;
		K[i] = (K[i - 1] + X[i] - X[i - 1] + K[i - 1] - K[j] - Y[i] + X[j] + X[i] - X[i - 1]) % mod;
		if (t) {
			D[i] = (D[i - 1] + X[i] - X[i - 1] + K[i - 1] - K[j] - Y[i] + X[j] + X[i] - X[i - 1]) % mod;
		}
		else D[i] = (D[i - 1] + X[i] - X[i - 1]) % mod;
	}
	cout << (D[n] % mod + 1 + mod) % mod << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

//	cin >> t;

	for (; t--; tc());
	
	return 0;
}
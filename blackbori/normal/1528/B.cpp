#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 998244353;

ll D[1010101], P[1010101], S[1010101];
ll n;

void tc() {
	ll i, j;
	cin >> n;

	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j += i) {
			P[j] ++;
		}
	}

	for (i = 1; i <= n; i++) {
		D[i] = (S[i - 1] + P[i]) % mod;
		S[i] = (S[i - 1] + D[i]) % mod;
	}

	cout << D[n] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

//	cin >> t;

	for (; t--; ) tc();

	return 0;
}
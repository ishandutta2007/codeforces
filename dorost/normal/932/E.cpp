/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 5001, M = 1000 * 1000 * 1000 + 7;
int C[N][N], cN[N], tav[N][N];

int tavan(int x, int n) {
	if (n == 0)
		return 1;
	ll ans = tavan(x, n / 2);
	ans = ans * ans;
	ans %= M;
	if (n % 2) {
		ans *= x;
		ans %= M;
	}
	return ans;
}
 
int inv(int x) {
	return tavan(x, M - 2);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	cN[0] = 1;
	for (int i = 1; i <= min(n, k); i++) {
		cN[i] = ((((ll)cN[i - 1] * (ll)inv(i)) % M) * (ll)(n - i + 1)) % M;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i > j) {
				C[i][j] = 0;
			} else if (i == j) {
				C[i][j] = 1;
			} else if (i == 0) {
				C[i][j] = 1;
			} else {
				C[i][j] = (C[i - 1][j - 1] + C[i][j - 1]) % M;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == 0) {
				tav[i][j] = 0;
			} else if (j == 0) {
				tav[i][j] = 1;
			} else {
				tav[i][j] = ((ll)tav[i][j - 1] * (ll)i) % M;
			}
		}
	}
	for (int i = 1; i <= min(n, k); i++) {
		ll l = 0;
		for (int j = 1; j <= i; j++) {
			ll x = (ll)C[j][i] * (ll)tav[j][k];
			x %= M;
			if ((i - j) % 2) {
				l -= x;
			} else {
				l += x;
			}
			l += M;
			l %= M;
		}
		l *= tavan(2, n - i);
		l %= M;
		l *= cN[i];
		l %= M;
		ans += l;
		ans %= M;
	}
	cout << ans;
}
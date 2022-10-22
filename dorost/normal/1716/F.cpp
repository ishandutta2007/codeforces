/*  * In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll; 
typedef long double ld; 
#define F first
#define S second
const int N = 2001, M = 998244353;
int C[N][N], cN[N], tav[N][N];
int dp[N][N];
int fac[N];

int tavan(ll x, int n) {
	ll ans = 1;
	while (n) {
		if (n & 1)  
			ans = (ans * x) % M;
		n >>= 1;
		x = (x * x) % M;
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
	fac[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = ((ll)fac[i - 1] * i) % M;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j > i) {
				C[i][j] = 0;
			} else if (i == j) {
				C[i][j] = 1;
			} else if (i == 0) {
				C[i][j] = 1;
			} else {
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M;
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
	dp[0][0] = 1;
	for (int k = 1; k < N; k++) {
		for (int i = 1; i <= k; i++) {
			dp[k][i] = ((ll)dp[k - 1][i] * i + dp[k - 1][i - 1]) % M;
		}
	}   
	for (int k = 1; k < N; k++) {
		for (int i = 1; i <= k; i++) {
			dp[k][i] = ((ll)dp[k][i] * fac[i]) % M;
		}
	}   
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		ll ans = 0;
		cN[0] = 1;
		for (int i = 1; i <= min(n, k); i++) {
			cN[i] = ((((ll)cN[i - 1] * (ll)inv(i)) % M) * (ll)(n - i + 1)) % M;
		}
		for (int i = 1; i <= min(n, k); i++) {
			ll l = dp[k][i];
			l *= tavan(m, n - i); 
			l %= M;
			l *= tavan((m + 1) / 2, i); 
			l %= M;
			l *= cN[i];
			l %= M;
			ans += l;
			ans %= M;
		}
		cout << ans << '\n';
	}   
}
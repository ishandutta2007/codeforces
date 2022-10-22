/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 2012, M = 25, K = 200012, MOD = 1000 * 1000 * 1000 + 7;
pair <int, int> a[N];
int dp[N][M], nd[N][N], dp2[N];
int fac[K], finv[K];

int tav(int x, int n) {
	if (n == 0)
		return 1;
	ll ans = tav(x, n / 2);
	ans = ans * ans;
	ans %= MOD;
	if (n % 2) {
		ans *= x;
		ans %= MOD;
	}
	return ans;
}
 
int inv(int x) {
	return tav(x, MOD - 2);
}

int C(int n, int k) {
	return ((((ll)fac[n] * (ll)finv[k]) % MOD) * (ll)finv[n - k]) % MOD;
}

bool ok (int i, int j) {
	return (i != j && a[i].F <= a[j].F && a[i].S <= a[j].S);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	for (int i = 0; i < k; i++) {
		cin >> a[i].F >> a[i].S;
	}
	a[k] = make_pair(1, 1);
	k++;
	sort (a, a + k);
	fac[0] = 1;
	finv[0] = inv(fac[0]);
	for (int i = 1; i < K; i++) {
		fac[i] = (ll)fac[i - 1] * (ll)i;
		fac[i] %= MOD;
		finv[i] = inv(fac[i]);
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (ok(i, j)) {
				int x = a[j].F - a[i].F, y = a[j].S - a[i].S;
				nd[i][j] = C(x + y, x);
			}
		}
	}
	for (int i = k - 1; i >= 0; i--) {
		int x = (n - a[i].F);
		int y = (m - a[i].S);
		dp[i][0] = C(x + y, x);
		dp2[i] = C(x + y, x);
		for (int j = i + 1; j < k; j++) {
			if (ok(i, j)) {
				dp2[i] -= ((ll)nd[i][j] * ((ll)dp2[j])) % MOD;
				dp2[i] += MOD;
				dp2[i] %= MOD;
			}
		}
	}
	for (int i = k - 1; i >= 0; i--) {
		for (int j = 1; j < M; j++) {
			for (int l = 0; l < k; l++) {
				if (ok(i, l)) {
					dp[i][j] += ((ll)nd[i][l] * (ll)(j == 1 ? dp2[l] : (dp[l][j - 1] - (dp[l][j])))) % MOD;
					dp[i][j] += MOD;
					dp[i][j] %= MOD;
				}
			}
		}
	}
	ll sum = 0;
	for (int i = 0; i < M - 1; i++) {
		if (i == 0)
			sum += (ll)dp2[i] * (ll)s;
		else
			sum += ((ll)(dp[0][i] - dp[0][i + 1]) * (ll)s);
		s = (s + 1) / 2;	
		sum %= MOD;
		sum += MOD;
		sum %= MOD;
	}
	sum += dp[0][M - 1];
	sum %= MOD;
	cout << (sum * inv(C(n + m - 2, n - 1))) % MOD << '\n';
}
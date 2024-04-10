#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <vector>
//#include <unordered_set>
//#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 262144;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-11;

ll dp[2][400500];
ll sum[2][400500];
ll getsum(ll t, ll s, ll e) {
	if (s < 0) s = 0;
	if (e > 400000) e = 400000;

	ll rv = sum[t][e];
	if (s != 0) rv -= sum[t][s - 1];
	rv %= MOD;
	rv += MOD;
	rv %= MOD;
	return rv;
}
int main() {
	int A, B, K, T, i, j, k;
	scanf("%d %d %d %d", &A, &B, &K, &T);

	dp[0][200000] = 1;
	for (i = 1; i <= T; i++) {
		int t = i % 2;
		sum[1 - t][0] = dp[1 - t][0];
		for (j = 1; j <= 400000; j++) sum[1 - t][j] = sum[1 - t][j - 1] + dp[1 - t][j];

		ll s = 0;
		for (j = 0; j <= 2 * K; j++) s += (2 * K + 1 - j) * dp[1 - t][j];
		s %= MOD;
		dp[t][0] = s;
		for (j = 1; j <= 200000 + 2000 * i; j++) {
			dp[t][j] = dp[t][j - 1];
			dp[t][j] += getsum(1 - t, j, j + 2 * K);
			dp[t][j] -= getsum(1 - t, j - 2 * K - 1, j - 1);
			dp[t][j] %= MOD;
			dp[t][j] += MOD;
			dp[t][j] %= MOD;
		}
	}

	ll ans = 0;
	for (i = 200001 + B - A; i <= 400000; i++) ans = (ans + dp[T % 2][i]) % MOD;
	return !printf("%lld\n", ans);
}
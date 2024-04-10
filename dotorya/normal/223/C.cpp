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
#include <cmath>
#include <vector>
#include <deque>
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

int IT_MAX = 1<<21;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-10;

ll mul_inv(ll a, ll b = MOD)
{
	ll b0 = b, t, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}
ll minv[2050];
ll C(ll a, ll b) {
	b = a - b;
	
	ll rv = 1, i;
	for (i = a; i > a - b; i--) rv = (rv*i) % MOD;
	for (i = 1; i <= b; i++) rv = (rv*minv[i]) % MOD;
	return rv;
}

ll dp[2050];
ll in[2050];
ll ans[2050];
int main() {
	int N, K, i, j;
	for (i = 1; i <= 2000; i++) minv[i] = mul_inv(i);

	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i]);

	if (K == 0) {
		for (i = 1; i <= N; i++) printf("%lld ", in[i]);
		return !printf("\n");
	}

	K--;
	for (i = 0; i < N; i++) dp[i] = C(K + i, K);
	for (i = 1; i <= N; i++) {
		for (j = i; j <= N; j++) {
			ans[j] += (in[i] * dp[j - i]) % MOD;
			ans[j] %= MOD;
		}
	}
	for (i = 1; i <= N; i++) printf("%lld ", ans[i]);
	return !printf("\n");
}
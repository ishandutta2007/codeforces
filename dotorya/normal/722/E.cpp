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
const db PI = 3.141592653589793238;
const ldb ERR = 1E-11;

ll dp1[25][2050];
ll dp2[25][2050];

ll val[2050][2050];
ll F[200050];
ll Finv[200050];

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
ll C(int a, int b) {
	ll rv = F[a];
	rv = (rv * Finv[b]) % MOD;
	rv = (rv * Finv[a-b]) % MOD;
	return rv;
}
inline ll getv(pii a, pii b) {
	if (a.first > b.first || a.second > b.second) return 0;
	return C(b.first - a.first + b.second - a.second, b.first - a.first);
}
inline ll getmod(ll a) {
	a %= MOD;
	a += MOD;
	return a%MOD;
}

pii in[2050];
int main() {
	int N, M, K, S, i, j, k;
	scanf("%d %d %d %d", &N, &M, &K, &S);
	S--;
	for (i = 1; i <= K; i++) scanf("%d %d", &in[i].first, &in[i].second);
	sort(in + 1, in + K + 1);
	if (in[1] == pii(1, 1)) {
		K--;
		for (i = 1; i <= K; i++) in[i] = in[i + 1];
		S /= 2;
	}
	if (N == 1 && M == 1) return !printf("%d\n", S+1);
	if (in[K] == pii(N, M)) {
		K--;
		S /= 2;
	}
	if (K == 0) return !printf("%d\n", S+1);
	K++;
	in[K] = pii(N, M);
	in[0] = pii(1, 1);

	F[0] = 1;
	for (i = 1; i <= 200000; i++) F[i] = (F[i - 1] * i) % MOD;
	for (i = 0; i <= 200000; i++) Finv[i] = mul_inv(F[i]);

	for (i = 0; i <= K; i++) {
		for (j = i; j <= K; j++) {
			val[i][j] = getv(in[i], in[j]);
		}
	}
	for (i = 1; i <= K; i++) {
		dp2[1][i] = getv(in[0], in[i]);
		for (j = 1; j < i; j++) dp2[1][i] = getmod(dp2[1][i] - dp2[1][j] * val[j][i]);
	}
	for (i = 2; i <= 21; i++) {
		for (j = 1; j <= K; j++) {
			for (k = 1; k < j; k++) dp2[i][j] = (dp2[i][j] + dp2[i - 1][k] * val[k][j])%MOD;
			for (k = 1; k < j; k++) dp2[i][j] = getmod(dp2[i][j] - dp2[i][k] * val[k][j]);
		}
	}
	
	ll ans = 0;
	for (i = 1; i <= 21; i++, S /= 2) ans = getmod(ans + dp2[i][K] * S);
	return !printf("%lld\n", getmod(ans * mul_inv(val[0][K]) + 1));
}
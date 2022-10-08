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
const int MOD = 1000003;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-11;

int main() {
	ll N, K, i, j;
	scanf("%lld %lld", &N, &K);

	if (N <= 62 && (1ll << N) < K) return !printf("1 1\n");

	ll s = 0;
	for (i = 2; i <= K - 1; i *= 2) s += (K - 1) / i;
	s %= MOD - 1;
	ll cnt = (s + N) % (MOD - 1);

	s = (N % (MOD - 1)) * ((K-1) % (MOD - 1)) - s;
	s %= MOD - 1;
	s += MOD - 1;
	s %= MOD - 1;

	ll B = 1;
	while (s--) B = (B * 2) % MOD;

	s = N % (MOD - 1);
	ll x = 1;
	while (s--) x = (x * 2) % MOD;

	ll A = 1;
	for (i = 0; i < K; i++) {
		A = (A * (x - i)) % MOD;
		if (A == 0) break;
	}

	ll po2 = 1;
	for (i = 1; i <= cnt; i++) po2 = (po2 * 2) % MOD;
	for (i = 1; i < MOD; i++) if ((po2 * i) % MOD == 1) break;
	A = (A*i) % MOD;

	A = (B - A + MOD) % MOD;
	return !printf("%lld %lld\n", A, B);
}
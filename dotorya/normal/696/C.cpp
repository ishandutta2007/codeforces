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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-13;

ll getpow(ll a, ll b) {
	ll rv = 1;
	ll mul = a;
	while (b) {
		if (b % 2) rv = (rv*mul) % MOD;
		mul = (mul*mul) % MOD;
		b /= 2;
	}
	return rv;
}
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

int main() {
	ll N = 1, t, i, K;
	scanf("%lld", &K);
	while (K--) {
		scanf("%lld", &t);
		t %= (MOD - 1);
		N = (N*t) % (MOD - 1);
	}

	t = getpow(2, (N + MOD - 2) % (MOD - 1));
	
	ll x = t;
	if (N % 2 == 1) x = (x + MOD - 1) % MOD;
	else x = (x + 1) % MOD;
	x = x * mul_inv(3) % MOD;
	ll y = t;

	printf("%lld/%lld\n", x, y);
	return 0;
}
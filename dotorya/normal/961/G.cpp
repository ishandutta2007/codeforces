#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll mul_inv(ll a, ll b = MOD) {
	ll t1 = a, t2 = b, t3;
	ll v1 = 1, v2 = 0, v3;
	while (t2 != 1) {
		ll x = t1 / t2;
		t3 = t1 - x*t2;
		v3 = v1 - x*v2;
		t1 = t2, t2 = t3;
		v1 = v2, v2 = v3;
	}
	return (v2 + b) % b;
}
ll mypow(ll a, ll b) {
	if (b < 0) return 0;
	ll rv = 1;
	while (b) {
		if (b % 2) rv = (rv*a) % MOD;
		a = a*a%MOD;
		b /= 2;
	}
	return rv;
}

ll F[200050];
ll Finv[200050];

ll in[200050];
int main() {
	ll i, j;
	F[0] = 1;
	for (i = 1; i <= 200000; i++) F[i] = F[i - 1] * i % MOD;
	for (i = 0; i <= 200000; i++) Finv[i] = mul_inv(F[i]);

	int N, K;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i]);

	ll a1 = 0;
	for (i = 0; i < K; i++) {
		ll v1 = F[K - 1];
		v1 = v1 * Finv[i] % MOD;
		v1 = v1 * Finv[K - 1 - i] % MOD;

		ll v2 = mypow(K - i, N - 1);
		v2 += mypow(K - i, N - 2) * (N - 1) % MOD;
		v1 = v1 * v2 % MOD;
		if (i % 2) a1 = (a1 - v1) % MOD;
		else a1 = (a1 + v1) % MOD;
	}
	a1 = (a1 + MOD) % MOD;
	a1 = a1 * Finv[K-1] % MOD;

	ll a2 = 0;
	for (i = 1; i <= N; i++) a2 = (a2 + in[i]) % MOD;
	return !printf("%lld\n", a1*a2%MOD);
}
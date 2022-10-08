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
#include <unordered_set>
#include <unordered_map>

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
const int INF = 534567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-16;

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

ll pow26[100050];
ll pow26inv[100050];
ll pow25[100050];
ll F[100050];
ll Finv[100050];

ll dp[305][100050];
inline ll C(ll a, ll b) {
	ll rv = F[a];
	rv = (rv * Finv[a - b]) % MOD;
	rv = (rv * Finv[b]) % MOD;
	return rv;
}

ll tdp[100050];
char in[100050];
int main() {
	int i, j;
	pow25[0] = pow26[0] = F[0] = 1;
	for (i = 1; i <= 100000; i++) {
		pow26[i] = (pow26[i - 1] * 26) % MOD;
		pow25[i] = (pow25[i - 1] * 25) % MOD;
		F[i] = (F[i - 1] * i) % MOD;
	}
	for (i = 0; i <= 100000; i++) {
		Finv[i] = mul_inv(F[i]);
		pow26inv[i] = mul_inv(pow26[i]);
	}

	for (i = 1; i <= 300; i++) {
		for (j = i; j <= 100000; j++) {
			ll t = C(j - 1, i - 1);
			t = (t*pow26inv[j]) % MOD;
			t = (t*pow25[j - i]) % MOD;
			dp[i][j] = (dp[i][j - 1] + t) % MOD;
		}
	}

	int M, L, t1, t2;
	scanf("%d %s", &M, in);
	L = strlen(in);
	if (L > 300) {
		i = L;
		tdp[i - 1] = 0;
		for (j = i; j <= 100000; j++) {
			ll t = C(j - 1, i - 1);
			t = (t*pow26inv[j]) % MOD;
			t = (t*pow25[j - i]) % MOD;
			tdp[j] = (tdp[j - 1] + t) % MOD;
		}
	}
	while (M--) {
		scanf("%d", &t1);
		if (t1 == 1) {
			scanf("%s", in);
			L = strlen(in);
			if (L > 300) {
				i = L;
				tdp[i - 1] = 0;
				for (j = i; j <= 100000; j++) {
					ll t = C(j - 1, i - 1);
					t = (t*pow26inv[j]) % MOD;
					t = (t*pow25[j - i]) % MOD;
					tdp[j] = (tdp[j - 1] + t) % MOD;
				}
			}
		}
		else {
			scanf("%d", &t2);
			if (L > t2) printf("0\n");
			else if (L <= 300) printf("%lld\n", (dp[L][t2]*pow26[t2])%MOD);
			else printf("%lld\n", (tdp[t2]*pow26[t2])%MOD);
		}
	}
	return 0;
}
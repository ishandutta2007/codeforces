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

int IT_MAX = 1 << 16;
const ll MOD = 998244353;
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

ll po1[2050];
ll po2[2050];

ll F[2050];
ll C[2050][2050];
ll dp1[2050][2050];
ll dp2[2050];
ll dp3[2050];
int main() {
	int N, A, B, i, j;
	scanf("%d", &N);
	scanf("%d %d", &A, &B);
	ll P = A * mul_inv(B) % MOD;
	po1[0] = po2[0] = 1;
	for (i = 1; i <= N + 2; i++) {
		po1[i] = po1[i - 1] * P % MOD;
		po2[i] = po2[i - 1] * (MOD + 1 - P) % MOD;
	}
	F[0] = 1;
	for (i = 1; i <= N + 2; i++) F[i] = F[i - 1] * i %MOD;
	for (i = 0; i <= N + 2; i++) {
		C[i][0] = C[i][i] = 1;
		for (j = 1; j < i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
	}

	dp1[1][0] = 1, dp1[0][1] = 1;
	dp2[1] = 1;
	dp3[1] = 0;
	for (i = 2; i <= N; i++) {
		for (j = 0; j <= i-1; j++) {
			ll t1 = j, t2 = i-1 - j;
			dp1[t1 + 1][t2] = (dp1[t1 + 1][t2] + dp1[t1][t2] * po1[t2]) % MOD;
			dp1[t1][t2 + 1] = (dp1[t1][t2 + 1] + dp1[t1][t2] * po2[t1]) % MOD;
		}

		ll psum = 0;
		for (j = 1; j < i; j++) psum = (psum + dp1[j][i - j] * dp2[j]) % MOD;
		dp2[i] = (MOD + 1 - psum) % MOD;

		for (j = 1; j < i; j++) {
			ll c = j * (i - j) + j * (j - 1) / 2;
			ll x = (c + dp3[j] + dp3[i - j]) * dp1[j][i - j] % MOD;
			x = (x * dp2[j]) % MOD;
			dp3[i] = (dp3[i] + x) % MOD;
		}
		dp3[i] = (dp3[i] + dp2[i] * (i*(i - 1) / 2)) % MOD;
		dp3[i] = dp3[i] * mul_inv(MOD + 1 - dp2[i]) % MOD;
	}
	return !printf("%lld\n", dp3[N]);
}
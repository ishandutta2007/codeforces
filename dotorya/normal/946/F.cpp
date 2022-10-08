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

int IT_MAX = 1 << 17;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first

ll mypow(ll a, ll b) {
	ll rv = 1;
	while (b) {
		if (b % 2) rv = rv*a%MOD;
		a = a*a%MOD;
		b /= 2;
	}
	return rv;
}

ll fibl[105];
char in[105];

ll dp[105];
ll dpl[105][105];
ll dpr[105][105];
ll dpc[105][105][105];
int main() {
	int N, X, i, j, k, l;
	scanf("%d %d %s", &N, &X, in + 1);
	
	fibl[0] = fibl[1] = 1;
	for (i = 2; i <= X; i++) fibl[i] = (fibl[i - 1] + fibl[i - 2]) % (MOD - 1);

	if (N == 1) dp[in[1] - '0'] = 1;
	dpl[in[1] - '0'][1] = 1;
	dpr[in[N] - '0'][N] = 1;
	for (i = 1; i <= N; i++) dpc[in[i] - '0'][i][i] = 1;

	for (i = 2; i <= X; i++) {
		dp[i] = dp[i - 1] * mypow(2, fibl[i - 2]) % MOD;
		dp[i] += dp[i - 2] * mypow(2, fibl[i - 1]) % MOD;
		for (j = 1; j < N; j++) dp[i] += dpl[i - 1][j] * dpr[i - 2][j+1] % MOD;
		dp[i] %= MOD;

		for (j = 1; j <= N; j++) {
			dpl[i][j] = dpl[i - 2][j] * mypow(2, fibl[i - 1]) % MOD;
			dpl[i][j] += dpl[i - 1][j];
			for (k = 1; k < j; k++) dpl[i][j] += dpl[i - 1][k] * dpc[i - 2][k + 1][j] % MOD;
			dpl[i][j] %= MOD;
		}
		for (j = 1; j <= N; j++) {
			dpr[i][j] = dpr[i - 1][j] * mypow(2, fibl[i - 2]) % MOD;
			dpr[i][j] += dpr[i - 2][j];
			for (k = j; k < N; k++) dpr[i][j] += dpc[i - 1][j][k] * dpr[i - 2][k + 1] % MOD;
			dpr[i][j] %= MOD;
		}
		for (j = 1; j <= N; j++) {
			for (k = j; k <= N; k++) {
				dpc[i][j][k] = (dpc[i - 1][j][k] + dpc[i - 2][j][k]) % MOD;
				for (l = j; l < k; l++) dpc[i][j][k] += dpc[i - 1][j][l] * dpc[i - 2][l + 1][k] % MOD;
				dpc[i][j][k] %= MOD;
			}
		}
	}
	return !printf("%lld\n", dp[X]);
}
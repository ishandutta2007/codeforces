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
//#include <unordered_map>
//#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18; // segment tree size
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f; // memset(dp, 0x3f, sizeof(dp)), 2*INF < INT_MAX
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10; // double EPS

ll dp[55][55][55];
ll tdp[55][55][55];

ll C[55][55];
ll F[55];
ll po2[55];

ll cnt[55][2];
int main() {
	int i, j, k, l, m;
	for (i = 0; i <= 50; i++) {
		C[i][0] = C[i][i] = 1;
		for (j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		for (j = 0; j <= i; j++) cnt[i][j % 2] = (cnt[i][j % 2] + C[i][j]) % MOD;
	}
	F[0] = 1;
	for (i = 1; i <= 50; i++) F[i] = F[i - 1] * i % MOD;
	po2[0] = 1;
	for (i = 1; i <= 50; i++) po2[i] = po2[i - 1] * 2 % MOD;

	dp[0][0][0] = 1;
	int N, tus;
	scanf("%d %d", &N, &tus);
	for (i = 1; i <= N; i++) {
		int st = 0, en = 1;
		int t;
		scanf("%d", &t);
		if (t == 1) st = 1;
		if (t == 0) en = 0;

		for (k = 0; k < i; k++) {
			for (l = 0; k + l < i; l++) {
				m = i - 1 - k - l;
				if (st == 0) {
					ll c0 = cnt[l][1] * po2[k + m] % MOD;
					ll c1 = cnt[l][0] * po2[k + m] % MOD;
					dp[k + 1][l][m] += c1 * dp[k][l][m] % MOD;
					dp[k][l][m + 1] += c0 * dp[k][l][m] % MOD;
				}
				if (en == 1) {
					ll c0 = cnt[k][1] * po2[l + m] % MOD;
					ll c1 = cnt[k][0] * po2[l + m] % MOD;
					dp[k][l + 1][m] += c1 * dp[k][l][m] % MOD;
					dp[k][l][m + 1] += c0 * dp[k][l][m] % MOD;
				}
			}
		}
		for (j = 0; j <= i; j++) {
			for (k = 0; j + k <= i; k++) {
				l = i - j - k;
				dp[j][k][l] %= MOD;
			}
		}
	}

	ll ans = 0;
	for (i = 0; i <= N; i++) {
		for (j = 0; i + j <= N; j++) {
			k = N - i - j;
			if ((i+j) % 2 == tus) ans = (ans + dp[i][j][k]) % MOD;
		}
	}
	return !printf("%lld\n", ans);
}
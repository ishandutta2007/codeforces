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

ll dp[105][105][105];

int C[105];
ll P[105][105];
int main() {
	int N, M, K, i, j, k, l;
	scanf("%d %d %d", &N, &M, &K);
	K--;
	for (i = 1; i <= N; i++) scanf("%d", &C[i]);
	for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) scanf("%lld", &P[i][j]);

	for (i = 1; i <= N; i++) for (j = 0; j <= K; j++) for (k = 1; k <= M; k++) dp[i][j][k] = LL_INF;

	if (C[1] == 0) for (i = 1; i <= M; i++) dp[1][0][i] = P[1][i];
	else dp[1][0][C[1]] = 0;

	for (i = 1; i < N; i++) {
		for (j = 0; j <= K; j++) {
			for (k = 1; k <= M; k++) {
				if (dp[i][j][k] == LL_INF) continue;
				if (C[i + 1]) {
					if (k != C[i + 1]) dp[i + 1][j + 1][C[i + 1]] = min(dp[i + 1][j + 1][C[i + 1]], dp[i][j][k]);
					else dp[i + 1][j][C[i + 1]] = min(dp[i + 1][j][C[i + 1]], dp[i][j][k]);
					continue;
				}

				for (l = 1; l <= M; l++) {
					if (k != l) dp[i + 1][j + 1][l] = min(dp[i + 1][j + 1][l], dp[i][j][k] + P[i + 1][l]);
					else dp[i + 1][j][l] = min(dp[i + 1][j][l], dp[i][j][k] + P[i + 1][l]);
				}
			}
		}
	}

	ll ans = LL_INF;
	for (i = 1; i <= M; i++) ans = min(ans, dp[N][K][i]);
	if (ans == LL_INF) ans = -1;
	return !printf("%lld\n", ans);
}
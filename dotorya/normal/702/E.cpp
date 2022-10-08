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

int IT_MAX = 1 << 21;
const int MOD = 1000000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-12;

ll dp[42][100050][3];

int main() {
	int N, i, j;
	ll K;
	scanf("%d %lld", &N, &K);
	for (i = 1; i <= N; i++) scanf("%lld", &dp[0][i][0]), dp[0][i][0]++;
	for (i = 1; i <= N; i++) {
		scanf("%lld", &dp[0][i][1]);
		dp[0][i][2] = dp[0][i][1];
	}
	for (i = 1; i <= 40; i++) {
		for (j = 1; j <= N; j++) {
			int p = dp[i - 1][j][0];
			dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][p][1];
			dp[i][j][2] = min(dp[i - 1][j][2], dp[i - 1][p][2]);
			dp[i][j][0] = dp[i - 1][p][0];
		}
	}

	for (i = 1; i <= N; i++) {
		int v = i;
		ll a1 = 0, a2 = LL_INF;
		for (j = 0; j <= 40; j++) {
			if (K & (1ll << j)) {
				a1 += dp[j][v][1];
				a2 = min(a2, dp[j][v][2]);
				v = dp[j][v][0];
			}
		}
		printf("%lld %lld\n", a1, a2);
	}
	return 0;
}
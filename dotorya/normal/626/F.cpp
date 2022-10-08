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

int IT_MAX = 131072;
const ll MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-6;

ll dp[2][205][1050];
int in[505];

int main() {
	int N, K, i, j, k;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	sort(in + 1, in + N + 1);

	for (i = 0; i <= K; i++) dp[0][0][i] = 1;
	for (i = 1; i <= N; i++) {
		int t1 = i & 1;
		int t2 = 1 - t1;
		for (j = 0; j <= i; j++) {
			for (k = 0; k <= K; k++) {
				dp[t1][j][k] = 0;
				if (j != 0 && k >= (in[i] - in[i - 1]) * (j - 1)) dp[t1][j][k] += dp[t2][j - 1][k - (in[i] - in[i - 1])*(j - 1)];
				if (k >= (in[i] - in[i - 1]) * j) dp[t1][j][k] += (j + 1) * dp[t2][j][k - (in[i] - in[i - 1]) * j];
				if (k >= (in[i] - in[i - 1]) * (j + 1)) dp[t1][j][k] += (j + 1) * dp[t2][j + 1][k - (in[i] - in[i - 1]) * (j + 1)];
				dp[t1][j][k] %= MOD;
			}
		}
	}
	printf("%lld\n", dp[N & 1][0][K]);
	return 0;
}
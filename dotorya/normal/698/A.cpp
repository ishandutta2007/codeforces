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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int in[105];
int dp[105][3];
int main() {
	dp[0][2] = 0;
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	dp[0][0] = dp[0][1] = INF;
	for (i = 1; i <= N; i++) {
		dp[i][0] = dp[i][1] = dp[i][2] = INF;
		if (in[i] & 1) dp[i][0] = min(dp[i][0], min(dp[i - 1][1], dp[i - 1][2]));
		if (in[i] & 2) dp[i][1] = min(dp[i][1], min(dp[i - 1][0], dp[i - 1][2]));
		dp[i][2] = min(dp[i][2], min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) + 1);
	}
	return !printf("%d\n", min(min(dp[N][0], dp[N][1]), dp[N][2]));
}
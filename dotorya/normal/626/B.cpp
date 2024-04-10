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

int dp[205][205][205];
char in[205];
int main() {
	int i, j, k;
	
	dp[0][0][0] = 0;
	dp[1][0][0] = 1;
	dp[0][1][0] = 2;
	dp[0][0][1] = 4;
	for (i = 2; i <= 200; i++) {
		for (j = 0; j <= i; j++) {
			for (k = 0; k <= i - j; k++) {
				int t1 = j, t2 = k, t3 = i - j - k;
				if (t1 >= 2) dp[t1][t2][t3] |= dp[t1 - 1][t2][t3];
				if (t2 >= 2) dp[t1][t2][t3] |= dp[t1][t2 - 1][t3];
				if (t3 >= 2) dp[t1][t2][t3] |= dp[t1][t2][t3 - 1];
				if (t1 != 0 && t2 != 0) dp[t1][t2][t3] |= dp[t1 - 1][t2 - 1][t3 + 1];
				if (t1 != 0 && t3 != 0) dp[t1][t2][t3] |= dp[t1 - 1][t2 + 1][t3 - 1];
				if (t2 != 0 && t3 != 0) dp[t1][t2][t3] |= dp[t1 + 1][t2 - 1][t3 - 1];
			}
		}
	}

	int N;
	scanf("%d %s", &N, in);
	int t1 = 0, t2 = 0, t3 = 0;
	for (i = 0; i < N; i++) {
		if (in[i] == 'B') t1++;
		if (in[i] == 'G') t2++;
		if (in[i] == 'R') t3++;
	}
	t1 = dp[t1][t2][t3];
	if (t1 & 1) printf("B");
	if (t1 & 2) printf("G");
	if (t1 & 4) printf("R");
	printf("\n");
	return 0;
}
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
const int INF = 1034567891;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-12;

char in[2000050];
int dp[2000050];
int sum[2000050];
int pos[26];
int main() {
	int N, M, K, i, j;
	scanf("%d %d", &N, &K);
	scanf("%s", in);
	M = strlen(in);

	for (i = 0; i < K; i++) pos[i] = -1;
	for (i = 0; i < M; i++) pos[in[i] - 'a'] = i;
	for (i = M; i < M + N; i++) {
		int t = 0;
		for (j = 1; j < K; j++) if (pos[j] < pos[t]) t = j;
		in[i] = t + 'a';
		pos[t] = i;
	}

	for (i = M + N; i >= 1; i--) in[i] = in[i - 1];
	for (i = 0; i < K; i++) pos[i] = 0;

	dp[0] = 1;
	sum[0] = 1;
	for (i = 1; i <= M + N; i++) {
		int t = pos[in[i] - 'a'];
		dp[i] = (sum[i - 1] - ((t == 0) ? 0 : sum[t - 1]) + MOD) % MOD;
		sum[i] = (sum[i - 1] + dp[i]) % MOD;

		pos[in[i] - 'a'] = i;
	}
	printf("%d\n", sum[M + N]);
	return 0;
}
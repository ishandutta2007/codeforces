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

int IT_MAX = 1 << 21;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-12;

ll dp[2][5050];

ll X[5050];
ll A[5050];
ll B[5050];
ll C[5050];
ll D[5050];
int main() {
	int N, S, E, i, j;
	scanf("%d %d %d", &N, &S, &E);
	for (i = 1; i <= N; i++) scanf("%lld", &X[i]);
	for (i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		A[i] += X[i];
	}
	for (i = 1; i <= N; i++) {
		scanf("%lld", &B[i]);
		B[i] -= X[i];
	}
	for (i = 1; i <= N; i++) {
		scanf("%lld", &C[i]);
		C[i] += X[i];
	}
	for (i = 1; i <= N; i++) {
		scanf("%lld", &D[i]);
		D[i] -= X[i];
	}

	for (i = 1; i <= N; i++) dp[0][i] = LL_INF;
	dp[0][0] = 0;
	for (i = 1; i <= N; i++) {
		int t = i % 2;
		for (j = 0; j <= N; j++) dp[t][j] = LL_INF;
		for (j = 0; j <= N; j++) {
			int x = j, y = j;
			if (i >= S) y--;
			if (i >= E) y++;
			if (y < 0 || y > N) continue;

			if (i == S) {
				if (x != 0) dp[t][j] = min(dp[t][j], dp[1 - t][j - 1] + D[i]);
				dp[t][j] = min(dp[t][j], dp[1 - t][j] + C[i]);
			}
			else if (i == E) {
				if (x != N) dp[t][j] = min(dp[t][j], dp[1 - t][j + 1] + A[i]);
				dp[t][j] = min(dp[t][j], dp[1 - t][j] + B[i]);
			}
			else {
				if (y != 0) dp[t][j] = min(dp[t][j], dp[1 - t][j] + B[i] + C[i]);
				if (x != 0 && y != 0) dp[t][j] = min(dp[t][j], dp[1 - t][j - 1] + B[i] + D[i]);
				if (x != N && y != N) dp[t][j] = min(dp[t][j], dp[1 - t][j + 1] + A[i] + C[i]);
				if (x != 0) dp[t][j] = min(dp[t][j], dp[1 - t][j] + A[i] + D[i]);
			}
		}
		int x = 0, y = 0;
		if (i >= S) y--;
		if (i >= E) y++;
		if (i != N && y == 0) dp[t][0] = LL_INF;
	}
	printf("%lld\n", dp[N % 2][0]);
}
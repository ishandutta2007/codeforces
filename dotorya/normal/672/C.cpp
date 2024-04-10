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
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-8;

inline ldb sq(int x) {
	return (ldb)x*(ldb)x;
}
ldb getdis(pii a, pii b) {
	ldb t = sq(a.first - b.first) + sq(a.second - b.second);
	if (t < 0) return 0;
	return sqrt(t);
}
pii in[100050];
ldb dp[100050][2][2];

int main() {

	pii A, B, T;
	int N, i, j, k;
	scanf("%d %d %d %d %d %d", &A.first, &A.second, &B.first, &B.second, &T.first, &T.second);
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d %d", &in[i].first, &in[i].second);

	for (i = 0; i <= N; i++) for (j = 0; j < 2; j++) for (k = 0; k < 2; k++) dp[i][j][k] = LL_INF;
	dp[0][0][0] = 0;

	for (i = 1; i <= N; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 2; k++) {
				dp[i][j][k] = min(dp[i - 1][j][k] + getdis(T, in[i]) * 2, dp[i][j][k]);
				if (j == 1) dp[i][j][k] = min(dp[i - 1][0][k] + getdis(T, in[i]) + getdis(A, in[i]), dp[i][j][k]);
				if (k == 1) dp[i][j][k] = min(dp[i - 1][j][0] + getdis(T, in[i]) + getdis(B, in[i]), dp[i][j][k]);
			}
		}
	}
	ldb ans = LL_INF;
	for (j = 0; j < 2; j++) for (k = 0; k < 2; k++) if(j != 0 || k != 0) ans = min(ans, dp[N][j][k]);
	printf("%.20lf\n", (db)ans);
	return 0;
}
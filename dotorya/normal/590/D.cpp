//*
#include <algorithm>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

#define pow10 pasiodfiopsdjviozjxciovjxcviozj
#define pow2 qpowdskopjkcoizxnzoicn

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <char, int> pci;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef pair <db, int> pdi;

int IT_MAX;
const int MOD = 1000000;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;

int dp[155][12050];
int v[155];
int main() {
	int N, K, S, C, i, j, k;
	scanf("%d %d %d", &N, &K, &S);
	C = K*(K + 1) / 2 + S;
	if (C >= 12000) C = 12000;
	for (i = 1; i <= N; i++) scanf("%d", &v[i]);

	for (i = 0; i <= K; i++) for (j = 0; j <= C; j++) dp[i][j] = INF;
	dp[0][0] = 0;

	for (i = 1; i <= N; i++) {
		for (j = K - 1; j >= 0; j--) for (k = C - i; k >= 0; k--) dp[j + 1][k + i] = min(dp[j + 1][k + i], dp[j][k] + v[i]);
	}

	int ans = INF;
	for (i = 0; i <= C; i++) ans = min(ans, dp[K][i]);
	printf("%d", ans);
	return 0;
}
//*/
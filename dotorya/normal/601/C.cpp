//*
#include <algorithm>
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
typedef pair <ldb, int> pdi;
typedef pair <ldb, ll> pdl;

int IT_MAX;
const int MOD = 500500507;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;

db dp[2][200050];
db sum[2][200050];
int in[105];

int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
//	N = 100, M = 1000;
	for (i = 0; i < N; i++) {
		scanf("%d", &in[i]);
//		in[i] = 500;
	}

	if (N == 1 || M == 1) {
		printf("%d\n", in[0]);
		return 0;
	}

	dp[0][100000] = 1;
	sum[0][0] = dp[0][0];
	for (i = 1; i <= 200000; i++) sum[0][i] = sum[0][i - 1] + dp[0][i];

	for (i = 1; i < N; i++) {
		for (j = 100000-i*M; j <= 100000+i*M; j++) {
			int x = max(1, j + in[i] - M);
			int y = min(200000, j + in[i] - 1);
			dp[i%2][j] = (sum[(i-1)%2][y] - sum[(i-1)%2][x - 1] - dp[(i-1)%2][j]) / (M - 1);
		}
		sum[i%2][0] = dp[i%2][0];
		for (j = 1; j <= 200000; j++) sum[i%2][j] = sum[i%2][j - 1] + dp[i%2][j];
	}

	db ans = 1;
	for (i = 1 - in[0]; i <= M - in[0]; i++) {
		if (i == 0) continue;
		ans += sum[(N-1)%2][100000 - i - 1];
	}

	printf("%.20lf\n", ans);
//	printf("%d\n", clock() - st);
	return 0;
}
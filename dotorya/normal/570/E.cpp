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

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef pair <char, int> pci;

const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;

int dp[2][505][505];
char in[505][505];
int main() {
	int N, M, i, j, k;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%s", &in[i][1]);
	if (N == 1 && M == 1) return printf("1"), 0;
	if (in[1][1] != in[N][M]) return printf("0"), 0;
	dp[0][1][N] = 1;
	for (i = 3; i <= (N + M + 2) / 2; i++) {
		int t1 = i, t2 = N + M + 2 - i;
		for (j = 1; j <= N; j++) {
			for (k = 1; k <= N; k++) {
				dp[i % 2][j][k] = 0;
				int x1 = j, x2 = k, y1 = t1 - j, y2 = t2 - k;
				if (y1 <= 0 || y1 > M || y2 <= 0 || y2 > M) continue;
				if (in[x1][y1] != in[x2][y2]) continue;

				ll t = 0;
				t += dp[(i + 1) % 2][j][k];
				t += dp[(i + 1) % 2][j - 1][k];
				t += dp[(i + 1) % 2][j][k + 1];
				t += dp[(i + 1) % 2][j - 1][k + 1];
				dp[i % 2][j][k] = t % MOD;
			}
		}
	}

	int ans = 0;
	if ((N + M) % 2 == 0) for (i = 1; i <= N; i++) ans = (ans+dp[((N + M + 2) / 2) % 2][i][i])%MOD;
	else {
		for (i = 1; i <= N; i++) ans = (ans + dp[((N + M + 1) / 2) % 2][i][i]) % MOD;
		for (i = 1; i <= N; i++) ans = (ans + dp[((N + M + 1) / 2) % 2][i][i+1]) % MOD;
	}
	printf("%d", ans);
	return 0;
}
//*/
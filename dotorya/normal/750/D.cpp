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
#include <cmath>
#include <vector>
#include <deque>
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

int IT_MAX = 1 << 14;
const ll MOD = 1000000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

bool chk[305][305];
bool dp[305][305][8];
bool tdp[305][305][8];
int in[35];

int P[8][2] = { {0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1} };
int main() {
	int N, i, j, k, l, m, n;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	for (i = 150; i < 150 + in[1]; i++) chk[150][i] = true;
	dp[150][150 + in[1] - 1][0] = true;

	for (i = 2; i <= N; i++) {
		memset(tdp, 0, sizeof(tdp));
		for (j = 0; j <= 300; j++) {
			for (k = 0; k <= 300; k++) {
				for (l = 0; l < 8; l++) {
					if (dp[j][k][(l + 1) % 8]) tdp[j][k][l] = true;
					if (dp[j][k][(l + 7) % 8]) tdp[j][k][l] = true;
				}
			}
		}
		for (j = 0; j <= 300; j++) for (k = 0; k <= 300; k++) for (l = 0; l < 8; l++) dp[j][k][l] = tdp[j][k][l];
		for (j = 1; j <= in[i]; j++) {
			memset(tdp, 0, sizeof(tdp));
			for (k = 0; k <= 300; k++) {
				for (l = 0; l <= 300; l++) {
					for (m = 0; m < 8; m++) {
						if (!dp[k][l][m]) continue;
						int x = k + P[m][0];
						int y = l + P[m][1];
						tdp[x][y][m] = true;
						chk[x][y] = true;
					}
				}
			}
			for (k = 0; k <= 300; k++) for (l = 0; l <= 300; l++) for (m = 0; m < 8; m++) dp[k][l][m] = tdp[k][l][m];
		}
	}

	int ans = 0;
	for (i = 0; i <= 300; i++) for (j = 0; j <= 300; j++) if (chk[i][j]) ans++;
	return !printf("%d\n", ans);
}
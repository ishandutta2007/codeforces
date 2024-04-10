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
#pragma comment(linker, "/STACK:336777216")
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
const ll MOD = 999983;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-12;

int totc[3];
int in[80];
char u[80];
int u2[80];
int dp[80][80][80][3];
int main() {
	int N, i, j, k, l, m;
	scanf("%d", &N);
	scanf("%s", u);
	for (i = 0; u[i] != 0; i++) {
		if (u[i] == 'V') in[i] = 0;
		else if (u[i] == 'K') in[i] = 1;
		else in[i] = 2;
		totc[in[i]]++;
	}

	memset(dp, 0x3f, sizeof(dp));
	dp[0][0][0][2] = 0;
	for (i = 0; i <= totc[0]; i++) {
		for (j = 0; j <= totc[1]; j++) {
			for (k = 0; k <= totc[2]; k++) {
				if (!i && !j && !k) continue;
				int c[3] = { i, j, k };
				m = 0;
				for (l = 0; l < N; l++) {
					if (!c[in[l]]) continue;
					u2[m++] = in[l];
					c[in[l]]--;
				}
				
				c[0] = i, c[1] = j, c[2] = k;
				int lst[3] = { -1,-1,-1 };
				for (l = 0; l < 3; l++) {
					for (m = i + j + k - 1; m >= 0; m--) if (u2[m] == l) break;
					lst[l] = m;
				}
				for (l = 0; l < 3; l++) {
					for (m = 0; m < 3; m++) {
						if (l == 1 && m == 0) continue;
						if (!c[l] || lst[l] == -1) continue;
						if (l == 0) dp[i][j][k][l] = min(dp[i][j][k][l], dp[i - 1][j][k][m] + (i + j + k - 1 - lst[l]));
						if (l == 1) dp[i][j][k][l] = min(dp[i][j][k][l], dp[i][j - 1][k][m] + (i + j + k - 1 - lst[l]));
						if (l == 2) dp[i][j][k][l] = min(dp[i][j][k][l], dp[i][j][k-1][m] + (i + j + k - 1 - lst[l]));
					}
				}
			}
		}
	}

	int ans = INF;
	for (i = 0; i < 3; i++) ans = min(ans, dp[totc[0]][totc[1]][totc[2]][i]);
	return !printf("%d\n", ans);
}
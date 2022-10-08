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

int IT_MAX = 1<<19;
const int MOD = 100000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-10;

int in[4050];
int sum[4050];

int dp[4050][95][95];
int main() {
	int N, i, j, k, ii, jj;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	for (i = 1; i <= N; i++) sum[i] = sum[i - 1] + in[i];

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= 93; j++) {
			for (k = 0; k <= 93; k++) {
				if ((N - i + k) % 2) continue;

				int s = (N - i - k) >> 1;
				s++;
				int e = s + i - 1;
				if (s < 1 || e > N) continue;

				dp[i][j][k] = -INF;
				if (j > i) {
					dp[i][j][k] = 0;
					continue;
				}
				if (j == i) {
					dp[i][j][k] = sum[s + j - 1] - sum[s - 1];
					continue;
				}
				for (ii = 0; ii <= 1; ii++) {
					int tx = INF;
					int k1 = j + ii;
					if (i - k1 < k1) {
						dp[i][j][k] = max(dp[i][j][k], sum[s + k1 - 1] - sum[s - 1]);
						continue;
					}
					if (i - k1 == k1) {
						dp[i][j][k] = max(dp[i][j][k], sum[s + k1 - 1] - sum[s - 1] - sum[e] + sum[e - k1]);
						continue;
					}
					for (jj = 0; jj <= 1; jj++) {
						int k2 = k1 + jj;
						tx = min(tx, dp[i - k1 - k2][k2][k+jj] - sum[e] + sum[e - k2]);
					}
					dp[i][j][k] = max(dp[i][j][k], sum[s + k1 - 1] - sum[s - 1] + tx);
				}
			}
		}
	}
	return !printf("%d\n", dp[N][1][0]);
}
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
const ll MOD = 987654321;
const int INF = 1034567891;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

char in[105][105][105];
int P[3][3] = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };
int main() {
	int N, M, K, i, j, k, l, m;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 0; i < N; i++) for (j = 0; j < M; j++) scanf("%s", in[i][j]);

	int ans = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			for (k = 0; k < K; k++) {
				if (in[i][j][k] == '0') continue;
				in[i][j][k] = '0';
				for (l = 0; l < 3; l++) {
					int sx = i - P[l][0], sy = j - P[l][1], sz = k - P[l][2];
					if (sx < 0 || sy < 0 || sz < 0 || in[sx][sy][sz] == '0') continue;
					for (m = 0; m < 3; m++) {
						int ex = i + P[m][0], ey = j + P[m][1], ez = k + P[m][2];
						if (ex >= N || ey >= M || ez >= K || in[ex][ey][ez] == '0') continue;

						if (l == m) break;
						int tx = sx + P[m][0], ty = sy + P[m][1], tz = sz + P[m][2];
						if (in[tx][ty][tz] == '0') break;
					}
					if (m < 3) break;
				}
				if (l < 3) ans++;
				in[i][j][k] = '1';
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
//*/
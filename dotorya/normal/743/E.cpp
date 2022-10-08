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
const ll MOD = 5000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-11;

int in[1050];
int pos[1050][130][8];
int cnt[8];

int len[8];

int dp[256];
int main() {
	int N, i, j, k, l;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		in[i]--;
	}
	for (i = 0; i <= N; i++) for (j = 0; j <= 125; j++) for (k = 0; k < 8; k++) pos[i][j][k] = INF;
	for (i = 0; i <= N; i++) {
		for (j = 0; j < 8; j++) {
			cnt[j] = 0;
			pos[i][0][j] = i;
		}
		for (j = i + 1; j <= N; j++) {
			cnt[in[j]]++;
			if (cnt[in[j]] <= 125) pos[i][cnt[in[j]]][in[j]] = j;
		}
	}
	
	int ans = 0;
	for (i = 0; i <= 124; i++) {
		for (j = 0; j < 256; j++) {
			for (k = 0; k < 8; k++) {
				len[k] = i;
				if (j & (1 << k)) len[k]++;
			}

			for (k = 1; k < 256; k++) dp[k] = INF;
			dp[0] = 0;
			for (k = 0; k < 255; k++) {
				if (dp[k] == INF) continue;
				for (l = 0; l < 8; l++) {
					if (k & (1 << l)) continue;
					dp[k | (1 << l)] = min(dp[k | (1 << l)], pos[dp[k]][len[l]][l]);
				}
			}
			if (dp[255] != INF) {
				int s = 0;
				for (k = 0; k < 8; k++) s += len[k];
				ans = max(ans, s);
			}
		}
	}
	return !printf("%d\n", ans);
}
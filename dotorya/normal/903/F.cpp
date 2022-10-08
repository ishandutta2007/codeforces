#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 20;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-9;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int A[5];
int val[5];
char in[4][1050];

int nxt[65536][120];
int cost[120];

int dp[1050][4096];
int main() {
	int N, i, j, k, l, m;
	scanf("%d", &N);
	for (i = 1; i <= 4; i++) scanf("%d", &A[i]);
	for (i = 0; i < 4; i++) scanf("%s", in[i]);
	for (i = 1; i <= 4; i++) {
		for (j = 0; j < i; j++) for (k = 0; k < i; k++) val[i] |= 1 << (4 * j + k);
	}

	int p = 0;
	for (i = 0; i <= 1; i++) {
		for (j = 0; j <= 2; j++) {
			for (k = 0; k <= 3; k++) {
				for (l = 0; l <= 4; l++) {
					int totc = A[i] + A[j] + A[k] + A[l];
					cost[p] = totc;
					int v = (val[i] << 3) | (val[j] << 2) | (val[k] << 1) | val[l];
					for (m = 0; m < 65536; m++) nxt[m][p] = m & ~v;
					p++;
				}
			}
		}
	}

	memset(dp, 0x3f, sizeof(dp));
	int st = 0;
	for (i = 0; i < 1; i++) {
		for (j = 0; j < 4; j++) {
			st = st * 2;
			if (in[j][i] == '*') st++;
		}
	}
	for (i = 0; i < 120; i++) dp[0][nxt[st][i]] = min(dp[0][nxt[st][i]], cost[i]);
	for (i = 1; i < N; i++) {
		int v = 0;
		for (j = 0; j < 4; j++) v = v * 2 + (int)(in[j][i] == '*');
		for (j = 0; j < 4096; j++) {
			if (dp[i-1][j] > 1000000) continue;

			l = j * 16 + v;
			for (k = 0; k < 120; k++) {
				int x = nxt[l][k];
				if (x < 4096) dp[i][x] = min(dp[i][x], dp[i - 1][j] + cost[k]);
			}
		}
	}

	return !printf("%d\n", dp[N - 1][0]);
}
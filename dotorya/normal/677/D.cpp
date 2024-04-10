//*
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

int IT_MAX = 4096;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int bit[4][1000][1000];
void init(int n, int x, int y) {
	for (; x <= IT_MAX; x += x & (-x)) for (int t = y; t <= IT_MAX; t += t & (-t)) bit[n][x][t] = INF;
}
void update(int n, int x, int y, int v) {
	for (; x <= IT_MAX; x += x & (-x)) for (int t = y; t <= IT_MAX; t += t & (-t)) bit[n][x][t] = min(bit[n][x][t], v);
}
int getmn(int n, int x, int y) {
	int rv = INF;
	for (; x; x -= x & (-x)) for (int t = y; t; t -= t & (-t)) rv = min(rv, bit[n][x][t]);
	return rv;
}

int in[305][305];
int dp[305][305];

vector <pii> V[90000];
int main() {
	int N, M, P, i, j, t;

	scanf("%d %d %d", &N, &M, &P);
	for (IT_MAX = 2; IT_MAX < max(N, M); IT_MAX *= 2);
	V[0].push_back(pii(1, 1));
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			scanf("%d", &t);
			V[t].push_back(pii(i, j));
		}
	}
	for (t = 0; t < 4; t++) for (i = 1; i <= IT_MAX; i++) for (j = 1; j <= IT_MAX; j++) bit[t][i][j] = INF;
	for (i = 1; i <= P; i++) {
		for (auto it : V[i - 1]) {
			update(0, it.first, it.second, -it.first - it.second + dp[it.first][it.second]);
			update(1, it.first, M + 1 - it.second, -it.first + it.second + dp[it.first][it.second]);
			update(2, N + 1 - it.first, M + 1 - it.second, it.first + it.second + dp[it.first][it.second]);
			update(3, N + 1 - it.first, it.second, it.first - it.second + dp[it.first][it.second]);
		}
		for (auto it : V[i]) {
			dp[it.first][it.second] = INF;
			dp[it.first][it.second] = min(dp[it.first][it.second], getmn(0, it.first, it.second) + it.first + it.second);
			dp[it.first][it.second] = min(dp[it.first][it.second], getmn(1, it.first, M+1-it.second) + it.first - it.second);
			dp[it.first][it.second] = min(dp[it.first][it.second], getmn(2, N+1-it.first, M+1-it.second) - it.first - it.second);
			dp[it.first][it.second] = min(dp[it.first][it.second], getmn(3, N+1-it.first, it.second) - it.first + it.second);
		}
		for (auto it : V[i - 1]) {
			init(0, it.first, it.second);
			init(1, it.first, M + 1 - it.second);
			init(2, N + 1 - it.first, M + 1 - it.second);
			init(3, N + 1 - it.first, it.second);
		}
	}

	return !printf("%d\n", dp[V[P][0].first][V[P][0].second]);
}
//*/
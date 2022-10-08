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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

bool dp[2][505][505];
int in[505];
vector <int> ans;
int main() {
	int N, K, i, j, k;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	dp[0][0][0] = true;
	for (i = 1; i <= N; i++) {
		int t = i % 2;
		for (j = 0; j <= K; j++) for (k = 0; k <= K; k++) dp[t][j][k] = false;
		for (j = 0; j <= K; j++) {
			for (k = 0; k <= j; k++) {
				if (dp[t ^ 1][j][k]) dp[t][j][k] = true;
				if (j >= in[i] && dp[t ^ 1][j - in[i]][k]) dp[t][j][k] = true;
				if (j >= in[i] && k >= in[i] && dp[t ^ 1][j - in[i]][k - in[i]]) dp[t][j][k] = true;
			}
		}
	}

	for (i = 0; i <= K; i++) if (dp[N % 2][K][i]) ans.push_back(i);
	printf("%d\n", ans.size());
	for (auto it : ans) printf("%d ", it);
	return !printf("\n");
}
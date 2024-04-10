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

int IT_MAX = 131072;
const ll MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

int ans[505][505];
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	int v = N*N;
	for (i = 1; i <= N; i++) for (j = N; j >= K; j--) ans[i][j] = v--;
	for (i = 1; i <= N; i++) for (j = K - 1; j >= 1; j--) ans[i][j] = v--;

	int s = 0;
	for (i = 1; i <= N; i++) s += ans[i][K];

	printf("%d\n", s);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}
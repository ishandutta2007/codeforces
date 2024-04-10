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
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int ans[105][105];

int in[105][105];
int main() {
	int N, M, Q, i, j, k, t1, t2, t3, t4, t5;
	scanf("%d %d %d", &N, &M, &Q);
	for (i = 0; i < N; i++) for (j = 0; j < M; j++) in[i][j] = i*M + j;

	while (Q--) {
		scanf("%d", &t1);
		if (t1 == 1) {
			scanf("%d", &t2);
			t2--;
			t3 = in[t2][0];
			for (j = 1; j < M; j++) in[t2][j - 1] = in[t2][j];
			in[t2][M - 1] = t3;
		}
		if (t1 == 2) {
			scanf("%d", &t2);
			t2--;
			t3 = in[0][t2];
			for (i = 1; i < N; i++) in[i - 1][t2] = in[i][t2];
			in[N - 1][t2] = t3;
		}
		if (t1 == 3) {
			scanf("%d %d %d", &t2, &t3, &t4);
			t2--, t3--;

			t5 = in[t2][t3];
			ans[t5 / M][t5%M] = t4;
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}
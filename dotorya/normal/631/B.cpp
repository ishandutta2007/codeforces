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
const ll MOD = 1000000009;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

pii R[5050];
pii C[5050];
int main() {
	int N, M, K, i, j, t1, t2, t3;
	scanf("%d %d %d", &N, &M, &K);
	for(i = 1; i <= K; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);
		if (t1 == 1) R[t2] = pii(t3, i);
		else C[t2] = pii(t3, i);
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if (R[i].second > C[j].second) printf("%d ", R[i].first);
			else printf("%d ", C[j].first);
		}
		printf("\n");
	}
	return 0;
}
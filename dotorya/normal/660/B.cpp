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
const ldb ERR = 1E-8;

int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);

	for (i = 1; i <= 2 * N; i += 2) {
		int t1 = i;
		int t2 = i + 1;
		int t3 = t1 + 2 * N;
		int t4 = t2 + 2 * N;

		if (t3 <= M) printf("%d ", t3);
		if (t1 <= M) printf("%d ", t1);
		if (t4 <= M) printf("%d ", t4);
		if (t2 <= M) printf("%d ", t2);
		
		
	}
	printf("\n");
	return 0;
}
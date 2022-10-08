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
const ldb ERR = 1E-16;

ldb A[100050];
ldb B[100050];

ldb in1[100050];
ldb in2[100050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		db t1;
		scanf("%lf", &t1);
		in1[i] = t1 + in1[i - 1];
	}
	for (i = 1; i <= N; i++) {
		db t1;
		scanf("%lf", &t1);
		in2[i] = t1;
	}
	for (i = N - 1; i >= 1; i--) in2[i] += in2[i + 1];

	for (i = 1; i < N; i++) {
		ldb b = in1[i];
		ldb a = 1 + in1[i] - in2[i + 1];

		A[i] = (a - sqrt(a*a - 4 * b + ERR)) / 2;
		B[i] = (a + sqrt(a*a - 4 * b + ERR)) / 2;
	}
	A[N] = B[N] = 1;

	for (i = 1; i <= N; i++) {
		db ans = (db)(A[i] - A[i - 1]);
		if (ans < 0) ans = 0;
		if (ans > 1) ans = 1;
		printf("%.10lf ", ans);
	}
	printf("\n");
	for (i = 1; i <= N; i++) {
		db ans = (db)(B[i] - B[i - 1]);
		if (ans < 0) ans = 0;
		if (ans > 1) ans = 1;
		printf("%.10lf ", ans);
	}
	return !printf("\n");
}
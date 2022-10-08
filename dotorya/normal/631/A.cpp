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

int A[1050];
int B[1050];
int mx = 0;
int main() {
	int N, i, j, ans = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &A[i]);
	for (i = 1; i <= N; i++) scanf("%d", &B[i]);
	for (i = 1; i <= N; i++) {
		int a = 0, b = 0;
		for (j = i; j <= N; j++) {
			a |= A[j];
			b |= B[j];
			ans = max(ans, a + b);
		}
	}
	printf("%d\n", ans);
	return 0;
}
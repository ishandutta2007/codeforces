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

int IT_MAX = 262144;
const int MOD = 1000003;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-11;

ll in[505][505];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) scanf("%lld", &in[i][j]);

	if (N == 1) return !printf("1\n");

	int x = 0, y = 0;
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) if (in[i][j] == 0) x = i, y = j;

	ll s1 = 0, s2 = 0;
	int t = 1;
	if (x == 1) t = 2;
	for (j = 1; j <= N; j++) s1 += in[t][j];
	for (j = 1; j <= N; j++) s2 += in[x][j];

	if (s1 <= s2) return !printf("-1\n");
	in[x][y] = s1 - s2;

	for (i = 1; i <= N; i++) {
		s2 = 0;
		for (j = 1; j <= N; j++) s2 += in[i][j];
		if (s1 != s2) return !printf("-1\n");
	}
	for (i = 1; i <= N; i++) {
		s2 = 0;
		for (j = 1; j <= N; j++) s2 += in[j][i];
		if (s1 != s2) return !printf("-1\n");
	}
	s2 = 0;
	for (i = 1; i <= N; i++) s2 += in[i][i];
	if (s1 != s2) return !printf("-1\n");
	s2 = 0;
	for (i = 1; i <= N; i++) s2 += in[i][N + 1 - i];
	if (s1 != s2) return !printf("-1\n");

	return !printf("%lld\n", in[x][y]);
}
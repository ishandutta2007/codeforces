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
const int INF = 1034567891;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

char in[1050][6];
int main() {
	int N, i, j, k;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%s", in[i]);

	int ans = 6;
	for (i = 1; i <= N; i++) {
		for (j = i + 1; j <= N; j++) {
			int c = 0;
			for (k = 0; k < 6; k++) if (in[i][k] != in[j][k]) c++;
			ans = min(ans, (c - 1) / 2);
		}
	}
	printf("%d\n", ans);
	return 0;
}
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
const ll MOD = 987654321;
const int INF = 1034567891;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int main() {
	int N, D, H, i;
	scanf("%d %d %d", &N, &D, &H);

	if (N == 2) return !printf("1 2\n");
	if (D == 1) return !printf("-1\n");
	if (H*2 < D) return !printf("-1\n");

	if (H == D) {
		for (i = 1; i <= H; i++) printf("%d %d\n", i, i + 1);
		for (i = H + 2; i <= N; i++) printf("%d %d\n", H, i);
		return 0;
	}

	for (i = 1; i <= H; i++) printf("%d %d\n", i, i + 1);
	printf("1 %d\n", H + 2);
	for (i = H + 3; i <= D + 1; i++) printf("%d %d\n", i - 1, i);
	for (i = D + 2; i <= N; i++) printf("1 %d\n", i);
	return 0;
}
//*/
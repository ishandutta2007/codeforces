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

int sum[300050];
int in[300050];
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		scanf("%d", &j);
		j = 1 - j;
		sum[i] = sum[i - 1] + j;
		in[i] = 1 - j;
	}

	int ans = 0, p1 = 1, p2 = 0;
	for (i = 1; i <= N; i++) {
		int st = i, en = N, mi, rv = i-1;
		while (st <= en) {
			mi = (st + en) / 2;
			if (sum[mi] - sum[i - 1] <= K) {
				rv = mi;
				st = mi + 1;
			}
			else en = mi - 1;
		}
		if (ans < rv - i + 1) {
			p1 = i;
			p2 = rv;
			ans = rv - i + 1;
		}
	}
	printf("%d\n", ans);
	for (i = p1; i <= p2; i++) in[i] = 1;
	for (i = 1; i <= N; i++) printf("%d ", in[i]);
	printf("\n");
	return 0;
}
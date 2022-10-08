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
const ldb ERR = 1E-12;

char in[100050];
int sum[100050];
int prv[100050];
int rsum[100050];
int main() {
	int N, K, i, j;
	scanf("%d %d %s", &N, &K, in+1);
	int p = 0;
	for (i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + '1' - in[i];
		rsum[sum[i]] = i;
		if (in[i] == '0') {
			prv[i] = p;
			p = i;
		}
	}

	int ans = N + 1;
	for (i = 1; i < N; i++) {
		if (in[i] == '1') continue;
		int st = i + 1, en = N, mi, rv = N + 1;
		while (st <= en) {
			mi = (st + en) / 2;
			if (sum[mi] <= K) {
				st = mi + 1;
				continue;
			}

			int p = rsum[sum[mi]-K-1];
			if (i - p - 1 <= mi - i) {
				rv = mi;
				en = mi - 1;
			}
			else st = mi + 1;
		}

		if (rv != N + 1) ans = min(ans, rv - i);
	}

	reverse(in + 1, in + N + 1);
	for (i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + '1' - in[i];
		rsum[sum[i]] = i;
		if (in[i] == '0') {
			prv[i] = p;
			p = i;
		}
	}
	for (i = 1; i < N; i++) {
		if (in[i] == '1') continue;
		int st = i + 1, en = N, mi, rv = N + 1;
		while (st <= en) {
			mi = (st + en) / 2;
			if (sum[mi] <= K) {
				st = mi + 1;
				continue;
			}

			int p = rsum[sum[mi]-K-1];
			if (i - p - 1 <= mi - i) {
				rv = mi;
				en = mi - 1;
			}
			else st = mi + 1;
		}

		if (rv != N + 1) ans = min(ans, rv - i);
	}

	printf("%d\n", ans);
	return 0;
}
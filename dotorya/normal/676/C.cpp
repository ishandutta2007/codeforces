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
const int MOD = 10007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

char in[100050];
int sum[100050];

int main() {
	int N, K, i, ans = 0;
	scanf("%d %d", &N, &K);
	scanf("%s", in + 1);
	for (i = 1; i <= N; i++) sum[i] = sum[i - 1] + in[i] - 'a';

	for (i = 1; i <= N; i++) {
		int st = i, en = N, mi, rv = i;
		while (st <= en) {
			mi = (st + en) / 2;
			int t = sum[mi] - sum[i - 1];
			if (t <= K || t >= (mi - i + 1) - K) {
				rv = mi;
				st = mi + 1;
			}
			else en = mi - 1;
		}
		ans = max(ans, rv - i + 1);
	}
	return !printf("%d\n", ans);
}
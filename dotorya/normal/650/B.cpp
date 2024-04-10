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
const ll MOD = 1000000009;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

char in[500050];
ll sum[500050];
int main() {
	ll A, B, T;
	int N, i;
	scanf("%d %lld %lld %lld", &N, &A, &B, &T);
	scanf("%s", in + 1);

	for (i = 1; i <= N; i++) sum[i] = sum[i - 1] + ((in[i] == 'w') ? (B + 1) : 1);

	int ans = 0;
	for (i = 1; i <= N; i++) {
		if (sum[i] + (i - 1)*A > T) break;
		ans = max(ans, i);

		int st = i + 1, en = N, mi, rv = N + 1;
		while (st <= en) {
			mi = (st + en) / 2;
			ll t = sum[N] - sum[mi - 1] + sum[i] + (i - 1 + N + 1 - mi + min(i - 1, N + 1 - mi)) * A;
			if (t <= T) {
				rv = mi;
				en = mi - 1;
			}
			else st = mi + 1;
		}
		ans = max(ans, i + N + 1 - rv);
	}
	return !printf("%d\n", ans);
}
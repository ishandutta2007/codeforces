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
const ll MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-6;

ll in[200050];
ll sum[200050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i]);
	sort(in + 1, in + N + 1);
	for (i = 1; i <= N; i++) sum[i] = sum[i - 1] + in[i];

	ll mxa = 0, mxb = 1, ans1 = 1, ans2 = 0;
	for (i = 2; i <= N; i++) {
		int st = 1, en = min(i - 1, N - i), mi, rv = 0;
		while (st <= en) {
			mi = (st + en) / 2;
			
			ll a1 = sum[N] - sum[N - mi] + sum[i] - sum[i - 1 - mi], b1 = 2 * mi + 1;
			a1 -= in[i] * b1;
			ll a2 = sum[N] - sum[N - mi + 1] + sum[i] - sum[i - mi], b2 = 2 * mi - 1;
			a2 -= in[i] * b2;
			if (a1 > 0 && a1*b2 > b1*a2) {
				rv = mi;
				st = mi + 1;
			}
			else en = mi - 1;
		}
		
		ll a = sum[N] - sum[N - rv] + sum[i] - sum[i - 1 - rv], b = 2 * rv + 1;
		a -= b * in[i];
		if (mxa * b < mxb * a) {
			ans1 = i, ans2 = rv;
			mxa = a, mxb = b;
		}
	}
	printf("%lld\n", ans2 * 2 + 1);
	for (i = ans1 - ans2; i <= ans1; i++) printf("%lld ", in[i]);
	for (i = N - ans2 + 1; i <= N; i++) printf("%lld ", in[i]);
	printf("\n");
	return 0;
}
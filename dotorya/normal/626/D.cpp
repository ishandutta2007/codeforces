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

int in[2050];
int cnt[5050];
int rsum[5050];

int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	sort(in + 1, in + N + 1);
	for (i = 1; i <= N; i++) for (j = i + 1; j <= N; j++) cnt[in[j] - in[i]]++;

	for (i = 5000; i >= 1; i--) rsum[i] = rsum[i + 1] + cnt[i];

	ll ans = 0;
	for (i = 1; i <= 5000; i++) {
		for (j = 1; j <= 5000 - i; j++) {
			ans += (ll)cnt[i] * cnt[j] * rsum[i + j + 1];
		}
	}

	ldb rv = ans;
	rv /= rsum[1];
	rv /= rsum[1];
	rv /= rsum[1];

	printf("%.20lf\n", (db)rv);
	return 0;
}
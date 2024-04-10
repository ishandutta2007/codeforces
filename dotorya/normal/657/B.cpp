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

ll in[200050];
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);

	for (i = 0; i <= N; i++) scanf("%lld", &in[i]);

	ll v = 0;
	for (i = 0; i <= N; i++) {
		v += in[i];
		if (v % 2) break;
		v /= 2;
	}
	if (i == N + 1) {
		v *= 2;
		i = N;
	}

	ll v2 = 0;
	for (j = N; j > i; j--) {
		v2 = v2 * 2 + in[j];
		if (abs(v2) >= LL_INF) v2 = LL_INF;
	}

	v += 2 * v2;
	if (abs(v) >= LL_INF) v = LL_INF;

	int ans = 0;
	for (j = i; j >= 0; j--) {
		ll t = in[j] - v;
		if (abs(t) <= K) ans++;
		if (j == N && t == 0) ans--;
		v *= 2;

		if (abs(v) >= LL_INF) v = LL_INF;
	}
	printf("%d\n", ans);
	return 0;
}
//*/
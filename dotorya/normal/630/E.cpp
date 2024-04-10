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
const int MOD = 100;
const int INF = 1034567890;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-6;

int main() {
	ll x1, x2, y1, y2;
	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);

	x1 += INF;
	x2 += INF;
	y1 += INF;
	y2 += INF;

	assert(x1 > 0 && x2 > 0 && y1 > 0 && y2 > 0);
	assert(x1 <= x2 && y1 <= y2);
	ll ans = (x2 - x1 + 1) * (y2 - y1 + 1);

	if (ans % 2 == 1) ans++;
	printf("%lld\n", ans/2);
	return 0;
}
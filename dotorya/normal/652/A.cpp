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
const int INF = 1034567890;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int main() {
	ll h1, h2, a, b;
	scanf("%lld %lld %lld %lld", &h1, &h2, &a, &b);

	h1 += 8 * a;
	if (h1 >= h2) return !printf("0\n");

	int i;
	for (i = 1; i <= 200000; i++) {
		h1 -= 12 * b;
		h1 += 12 * a;
		if (h1 >= h2) return !printf("%d\n", i);
	}
	return !printf("-1\n");
}
//*/
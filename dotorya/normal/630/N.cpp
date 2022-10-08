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
const int INF = 534567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-6;

int main() {
	ldb a, b, c;
	cin >> a >> b >> c;
	if (a < 0) {
		a *= -1;
		b *= -1;
		c *= -1;
	}
	ldb ans1 = (-b + sqrt(b*b - 4 * a*c)) / (2 * a);
	ldb ans2 = (-b - sqrt(b*b - 4 * a*c)) / (2 * a);

	printf("%.20lf\n%.20lf\n", (db)ans1, (db)ans2);
	return 0;
}
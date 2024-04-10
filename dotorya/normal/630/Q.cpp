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
const int MOD = 100000;
const int INF = 1034567890;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-6;

int main() {
	ldb l3, l4, l5;
	cin >> l3 >> l4 >> l5;

	ldb S3 = (sqrt(6) / 18) * l3 * l3 * l3 * sin(60 * PI / 180);
	ldb S4 = sqrt(2) / 6 * l4 * l4 * l4;
	
	ldb t = sin(54 * PI / 180) / sin(72 * PI / 180);
	ldb h = l5 * sqrt(1 - t*t);

	ldb S5 = 2.5 * l5 * l5 * sin(72 * PI / 180) * t * t;
	S5 *= h / 3;

	ldb ans = S3 + S4 + S5;
	printf("%.20lf\n", (db)ans);
	return 0;
}
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
#include <string>
#include <time.h>
#include <cmath>
#include <vector>
#include <deque>
//#include <unordered_set>
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
const ll MOD = 5000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-11;

int main() {
	int s, x1, x2, t1, t2, p, d;
	cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;

	if (x1 > x2) {
		x1 = s - x1;
		x2 = s - x2;
		p = s - p;
		d *= -1;
	}

	int ans = (x2 - x1)*t2;

	int t;
	if (d == -1) t = p + x1;
	else if (p <= x1) t = x1 - p;
	else t = 2 * s - (p - x1);
	ans = min(ans, (t + x2 - x1)*t1);
	return !printf("%d\n", ans);
}
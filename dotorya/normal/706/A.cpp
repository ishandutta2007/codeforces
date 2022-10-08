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
#include <vector>
//#include <unordered_set>
//#include <unordered_map>

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

int IT_MAX = 262144;
const int MOD = 1000003;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-11;

ldb sq(ldb a) {
	return a*a;
}
int main() {
	ldb a, b;
	cin >> a >> b;

	ldb ans = INF;
	int N, i;
	scanf("%d", &N);
	while (N--) {
		int x, y, v;
		scanf("%d %d %d", &x, &y, &v);
		ans = min(ans, sqrt(sq(x - a) + sq(y - b)) / v);
	}
	return !printf("%.20lf\n", (db)ans);
}
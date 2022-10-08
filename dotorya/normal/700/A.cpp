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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int main() {
	int N, L, v1, v2, K;
	scanf("%d %d %d %d %d", &N, &L, &v1, &v2, &K);

	ldb st = 0, en = L, mi;
	for (int i = 1; i <= 200; i++) {
		mi = (st + en) / 2;
		int c = (N + K - 1) / K;
		c--;
		
		ldb u = c * ((mi - 1.0 * v1 / v2 * mi) / (v1 + v2) + mi/v2) * v1;
		if (u + mi <= L) st = mi;
		else en = mi;
	}
	printf("%.20lf\n", (db)((L - mi) / v1 + mi / v2));
	return 0;
}
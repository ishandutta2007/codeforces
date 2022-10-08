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

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int st = 1, en = INF, mi, rv = INF + 1;
	while (st <= en) {
		mi = (st + en) / 2;
		int x3 = mi / 6;
		int x1 = mi / 2 - x3;
		int x2 = mi / 3 - x3;
		if (x1 + x3 >= N && x2 + x3 >= M && x1 + x2 + x3 >= N + M) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
	}
	printf("%d\n", rv);
	return 0;
}
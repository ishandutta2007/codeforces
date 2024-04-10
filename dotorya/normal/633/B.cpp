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
const ll MOD = 1000000009;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

const int NMX = 1000 + 50;
const int MMX = 500000 + 50;

vector <int> ans;
int main() {
	int M, i, j;
	scanf("%d", &M);

	int st = 1, en = INF, mi, rv = INF + 1;
	while (st <= en) {
		mi = (st + en) / 2;
		int v = 0;
		for (i = 5; i <= mi; i *= 5) v += mi / i;
		if (v >= M) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
	}

	for (i = rv;; i++) {
		int v = 0;
		for (j = 5; j <= i; j *= 5) v += i / j;
		if (v != M) break;
		ans.push_back(i);
	}

	printf("%d\n", ans.size());
	for (auto it : ans) printf("%d ", it);
	printf("\n");
	return 0;
}
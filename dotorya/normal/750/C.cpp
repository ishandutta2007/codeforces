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

int IT_MAX = 1 << 14;
const ll MOD = 1000000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

int main() {
	int mn = -INF, mx = INF, s = 0;
	
	int N, i, t1, t2;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &t1, &t2);
		if (t2 == 1) mn = max(mn, 1900 - s);
		else mx = min(mx, 1899 - s);
		s += t1;
	}
	if (mn > mx) return !printf("Impossible\n");
	else if (mx == INF) return !printf("Infinity\n");
	else printf("%d\n", mx + s);
}
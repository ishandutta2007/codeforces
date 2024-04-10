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
const ldb ERR = 1E-13;

int main() {
	int N, M, t1, t2;
	scanf("%d %d", &N, &M);

	int mn = 1, mx = N - 1;
	while (M--) {
		scanf("%d %d", &t1, &t2);
		if (t1 > t2) swap(t1, t2);
		mn = max(mn, t1);
		mx = min(mx, t2 - 1);
	}
	if (mn > mx) return !printf("0\n");
	return !printf("%d\n", mx - mn + 1);
}
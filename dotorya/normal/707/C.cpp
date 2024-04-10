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
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-11;

int main() {
	ll N, i, v = 1;
	scanf("%lld", &N);

	if (N == 1 || N == 2) return !printf("-1\n");

	while (N % 2 == 0) {
		N /= 2;
		v *= 2;
	}
	if (N != 1) {
		ll K = (N*N - 1) / 2;
		return !printf("%lld %lld\n", K*v, (K + 1)*v);
	}
	else {
		v /= 4;
		return !printf("%lld %lld\n", 3 * v, 5 * v);
	}
	return 0;
}
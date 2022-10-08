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

int IT_MAX = 1 << 21;
const int MOD = 1000000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-12;

int main() {
	ll D, K, A, B, T;
	scanf("%lld %lld %lld %lld %lld", &D, &K, &A, &B, &T);

	if (D <= K) return !printf("%lld\n", A*D);

	ll ans = A*K;
	D -= K;
	if (B*K <= A*K + T) return !printf("%lld\n", ans + B*D);
	ans += (D / K) * (A*K + T);
	D %= K;
	ans += min(B*D, A*D + T);
	return !printf("%lld\n", ans);
}
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
const int MOD = 100;
const int INF = 534567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-6;

int main() {
	ll ans = 0, N;
	scanf("%lld", &N);
	ans = N;
	ans -= N / 2;
	ans -= N / 3;
	ans -= N / 5;
	ans -= N / 7;
	ans += N / 6;
	ans += N / 10;
	ans += N / 14;
	ans += N / 15;
	ans += N / 21;
	ans += N / 35;
	ans -= N / 30;
	ans -= N / 42;
	ans -= N / 105;
	ans -= N / 70;
	ans += N / 210;
	printf("%lld\n", ans);
	return 0;
}
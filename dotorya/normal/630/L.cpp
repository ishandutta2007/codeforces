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
const int MOD = 100000;
const int INF = 1034567890;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-6;

char in[6];
int main() {
	scanf("%s", in);

	int i, j;
	ll v = (in[0] - '0') * 10000 + (in[2] - '0') * 1000 + (in[4] - '0') * 100 + (in[3] - '0') * 10 + (in[1] - '0');

	ll ans = 1;
	for (i = 1; i <= 5; i++) ans = (ans*v) % MOD;
	printf("%05lld\n", ans);
	return 0;
}
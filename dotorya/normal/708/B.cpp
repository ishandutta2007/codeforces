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

ll getval(ll x) {
	ll st = 1, en = 1000000, mi, rv = 0;
	while (st <= en) {
		mi = (st + en) / 2;
		if (mi*(mi-1)/2 <= x) {
			rv = mi;
			st = mi + 1;
		}
		else en = mi - 1;
	}
	if (rv*(rv - 1) / 2 != x) return -1;
	return rv;
}
int main() {
	ll a, b, c, d;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

	if (a == 0 && b == 0 && c == 0 && getval(d) != -1) {
		ll x = getval(d);
		for(int i = 1; i <= x; i++) printf("1");
		return !printf("\n");
	}
	if (b == 0 && c == 0 && d == 0 && getval(a) != -1) {
		ll x = getval(a);
		for (int i = 1; i <= x; i++) printf("0");
		return !printf("\n");
	}
	
	ll c0 = getval(a);
	ll c1 = getval(d);
	if (c0 == -1 || c1 == -1) return !printf("Impossible\n");

	if (b + c != c0*c1) return !printf("Impossible\n");

	ll N = c0 + c1, i;
	for (i = 1; i <= N; i++) {
		if (b >= c1 && c0 != 0) {
			printf("0");
			b -= c1;
			c0--;
		}
		else {
			printf("1");
			c1--;
		}
	}
	return !printf("\n");
}
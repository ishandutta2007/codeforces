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
const ll MOD = 5000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-11;

map <int, ll> Mx;

int main() {
	int N, X, i, t;
	scanf("%d %d", &N, &X);
	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		Mx[t]++;
	}
	
	if (X == 0) {
		ll ans = 0;
		for (auto it : Mx) ans += it.second * (it.second - 1) / 2;
		return !printf("%lld\n", ans);
	}

	ll ans = 0;
	for (auto it : Mx) {
		int v = it.first ^ X;
		if (Mx.count(v)) ans += Mx[v] * it.second;
	}
	return !printf("%lld\n", ans / 2);
}
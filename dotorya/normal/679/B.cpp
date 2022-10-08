//*
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

int IT_MAX = 4096;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

ll v[1050];
ll ans = 0;
void aa(ll x, int lvl) {
	ll st = 1, en = 1000000, mi, rv = 0;
	while (st <= en) {
		mi = (st + en) / 2;
		if (mi*mi*mi <= x) {
			rv = mi;
			st = mi + 1;
		}
		else en = mi - 1;
	}
	if (lvl == 1) {
		ans += rv*rv*rv;
		return;
	}

	if (v[lvl - 1] <= x - rv*rv*rv) {
		ans += rv*rv*rv;
		aa(x - rv*rv*rv, lvl - 1);
	}
	else {
		ans += (rv - 1)*(rv - 1)*(rv - 1);
		aa(3 * (rv - 1)*rv, lvl - 1);
	}
}
int main() {
	v[1] = 1;
	int i, j;
	for (i = 2; i <= 18; i++) {
		ll st = 1, en = 100000000, mi, rv = en + 1;
		while (st <= en) {
			mi = (st + en) / 2;
			if (v[i - 1] < 3 * mi * mi + 3 * mi + 1) {
				rv = mi;
				en = mi - 1;
			}
			else st = mi + 1;
		}
		if (rv >= 1000000) break;
		v[i] = v[i - 1] + rv * rv * rv;
	}

	ll N;
	scanf("%lld", &N);
	for (i = 1; i <= 18; i++) if (v[i] > N) break;
	printf("%d ", i - 1);
	aa(N, i - 1);
	return !printf("%lld\n", ans);
}
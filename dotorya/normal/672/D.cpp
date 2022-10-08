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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-8;

int in[500050];
int main() {
	int N, K, i;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	int ans = 0;

	int st = 1, en = 1000000000, mi, rv = 0;
	while (st <= en) {
		mi = (st + en) / 2;
		ll s = 0;
		for (i = 1; i <= N; i++) s += max(mi - in[i], 0);
		if (K >= s) {
			rv = mi;
			st = mi + 1;
		}
		else en = mi - 1;
	}
	ans -= rv;

	st = 1, en = 1000000000, rv = en + 1;
	while (st <= en) {
		mi = (st + en) / 2;
		ll s = 0;
		for (i = 1; i <= N; i++) s += max(in[i] - mi, 0);
		if (K >= s) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
	}
	ans += rv;
	
	int t = 1;
	ll sum = 0;
	for (i = 1; i <= N; i++) sum += in[i];
	if (sum % N == 0) t = 0;
	return !printf("%d\n", max(ans, t));
}
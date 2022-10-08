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
const ll MOD = 97654321;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-13;

int it[2][600000];
void update(int x, int p, int v) {
	p += IT_MAX - 1;
	if (x == 0) {
		it[x][p] = v;
		for (p /= 2; p; p /= 2) it[x][p] = max(it[x][2 * p], it[x][2 * p + 1]);
	}
	else {
		it[x][p] = v;
		for (p /= 2; p; p /= 2) it[x][p] = min(it[x][2 * p], it[x][2 * p + 1]);
	}
}
int getval(int x, int p1, int p2) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;
	if (x == 0) {
		int rv = -INF;
		while (p1 <= p2) {
			if (p1 % 2 == 1) rv = max(rv, it[x][p1++]);
			if (p2 % 2 == 0) rv = max(rv, it[x][p2--]);
			p1 /= 2, p2 /= 2;
		}
		return rv;
	}
	else {
		int rv = INF;
		while (p1 <= p2) {
			if (p1 % 2 == 1) rv = min(rv, it[x][p1++]);
			if (p2 % 2 == 0) rv = min(rv, it[x][p2--]);
			p1 /= 2, p2 /= 2;
		}
		return rv;
	}
}

int main() {
	int N, i, t;
	scanf("%d", &N);
	for (IT_MAX = 2; IT_MAX < N; IT_MAX *= 2);
	fill(it[0] + 1, it[0] + IT_MAX * 2, -INF);
	fill(it[1] + 1, it[1] + IT_MAX * 2, INF);
	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		update(0, i, t);
	}
	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		update(1, i, t);
	}

	ll ans = 0;
	for (i = 1; i <= N; i++) {
		ans += N - i + 1;
		int st = i, en = N, mi, rv = i - 1;
		while (st <= en) {
			mi = (st + en) / 2;
			if (getval(0, i, mi) < getval(1, i, mi)) {
				rv = mi;
				st = mi + 1;
			}
			else en = mi - 1;
		}
		ans -= rv - i + 1;

		st = i, en = N, mi, rv = N + 1;
		while (st <= en) {
			mi = (st + en) / 2;
			if (getval(0, i, mi) > getval(1, i, mi)) {
				rv = mi;
				en = mi - 1;
			}
			else st = mi + 1;
		}
		ans -= N + 1 - rv;
	}
	return !printf("%lld\n", ans);
}
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
const ll MOD = 1000000009;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

const int NMX = 1048576 + 50;
pii it[NMX * 2];
void update(int p, pii u) {
	p += IT_MAX - 1;
	it[p] = u;
	for (p = p / 2; p > 0; p /= 2) {
		it[p].first = max(it[2 * p].first, it[2 * p + 1].first);
		it[p].second = min(it[2 * p].second, it[2 * p + 1].second);
	}
}
pii getrv(int p1, int p2) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;

	pii rv = pii(-1, INF);
	while (p1 <= p2) {
		if (p1 % 2 == 1) {
			rv.first = max(rv.first, it[p1].first);
			rv.second = min(rv.second, it[p1].second);
			p1++;
		}
		if (p2 % 2 == 0) {
			rv.first = max(rv.first, it[p2].first);
			rv.second = min(rv.second, it[p2].second);
			p2--;
		}
		p1 /= 2, p2 /= 2;
	}
	return rv;
}

int V[NMX];
int C[NMX];

int v[NMX];
int main() {
	int N, K, i;
	scanf("%d %d", &N, &K);
	for (IT_MAX = 2; IT_MAX < N; IT_MAX *= 2);
	for (i = 1; i < 2 * IT_MAX; i++) it[i] = pii(-1, INF);
	for (i = 1; i <= N; i++) scanf("%d", &V[i]);
	for (i = 1; i <= N; i++) scanf("%d", &C[i]);
	for (i = 1; i <= N; i++) update(i, pii(V[i] * 100, C[i]));

	for (i = 1; i <= N; i++) {
		int st = i, en = N, mi, rv = N + 1;
		while (st <= en) {
			mi = (st + en) / 2;
			pii u = getrv(i, mi);
			if (u.first >= u.second) {
				rv = mi;
				en = mi - 1;
			}
			else st = mi + 1;
		}

		v[i] = -1;
		if (rv != N + 1) {
			pii u = getrv(i, rv);
			v[i] = max(v[i], min(u.first, u.second));
		}
		if (rv != i) {
			pii u = getrv(i, rv - 1);
			v[i] = max(v[i], min(u.first, u.second));
		}
	}

	sort(v + 1, v + N + 1);
	ldb u = 1.0 * K / N;
	ldb ans = 0;
	for (i = 1; i <= N-K+1; i++) {
		ans += u * v[i];
		u *= 1.0 * (N + 1 - i - K) / (N - i);
	}
	printf("%.20lf\n", (db)ans);
	return 0;
}
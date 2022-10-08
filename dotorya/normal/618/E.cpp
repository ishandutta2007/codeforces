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

int IT_MAX = 131072;
const ll MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

typedef pair<db, db> pdd;

pdd operator + (const pdd& a, const pdd& b) {
	return pdd(a.first + b.first, a.second + b.second);
}

class datax {
public:
	pdd v;
	int d;
} it[1300000];

void init(int N) {
	for (int i = IT_MAX; i < IT_MAX + N; i++) it[i].v = pdd(1, 0);
	for (int i = IT_MAX - 1; i >= 1; i--) it[i].v = it[2 * i].v + it[2 * i + 1].v;
}

pdd rotate(pdd u, int d) {
	pdd rv;
	db cv = cos(d*PI / 180);
	db sv = sin(d*PI / 180);
	rv.first = u.first * cv - u.second * sv;
	rv.second = u.first * sv + u.second * cv;
	return rv;
}
void update1(int st, int en, int S, int E, int n, int x) {
	if (st == S && en == E) {
		db k = sqrt(it[n].v.first * it[n].v.first + it[n].v.second * it[n].v.second);
		db u = (k + x) / k;
		it[n].v.first *= u;
		it[n].v.second *= u;
		return;
	}

	if (it[n].d != 0) {
		it[2 * n].d += it[n].d;
		it[2 * n].v = rotate(it[2 * n].v, it[n].d);
		it[2 * n + 1].d += it[n].d;
		it[2 * n + 1].v = rotate(it[2 * n + 1].v, it[n].d);
		it[n].d = 0;
	}

	int M = (S + E) / 2;
	if (en <= M) update1(st, en, S, M, 2 * n, x);
	else if (st > M) update1(st, en, M + 1, E, 2 * n + 1, x);
	else {
		update1(st, M, S, M, 2 * n, x);
		update1(M + 1, en, M + 1, E, 2 * n + 1, x);
	}

	it[n].v = it[2 * n].v + it[2 * n + 1].v;
}

void update2(int st, int en, int S, int E, int n, int x) {
	if (st == S && en == E) {
		it[n].v = rotate(it[n].v, x);
		it[n].d += x;
		return;
	}

	if (it[n].d != 0) {
		it[2 * n].d += it[n].d;
		it[2 * n].v = rotate(it[2 * n].v, it[n].d);
		it[2 * n + 1].d += it[n].d;
		it[2 * n + 1].v = rotate(it[2 * n + 1].v, it[n].d);
		it[n].d = 0;
	}

	int M = (S + E) / 2;
	if (en <= M) update2(st, en, S, M, 2 * n, x);
	else if (st > M) update2(st, en, M + 1, E, 2 * n + 1, x);
	else {
		update2(st, M, S, M, 2 * n, x);
		update2(M + 1, en, M + 1, E, 2 * n + 1, x);
	}

	it[n].v = it[2 * n].v + it[2 * n + 1].v;
}
int main() {
	int N, M, i;
	scanf("%d %d", &N, &M);
	for (IT_MAX = 2; IT_MAX < N; IT_MAX *= 2);
	init(N);

	for (i = 1; i <= M; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		if (t1 == 1) update1(t2, t2, 1, IT_MAX, 1, t3);
		else update2(t2, N, 1, IT_MAX, 1, -t3);

		printf("%.20lf %.20lf\n", it[1].v.first, it[1].v.second);
	}
	return 0;
}
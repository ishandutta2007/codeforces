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
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-11;

pdd it[300050];
void update(int p, ldb v) {
	p += IT_MAX - 1;
	it[p].first = log(v), it[p].second = log(v);
	for (p /= 2; p; p /= 2) {
		it[p].first = it[2 * p].first + it[2 * p + 1].first;

		ldb u = exp(it[2 * p].second) + exp(it[2 * p].first + it[2 * p + 1].second);
		it[p].second = log(u);
	}
}
pdd getval(int st, int en, int S, int E, int n) {
	if (st == S && en == E) return it[n];
	
	int M = (S + E) / 2;
	if (en <= M) return getval(st, en, S, M, 2 * n);
	else if (st > M) return getval(st, en, M + 1, E, 2 * n + 1);
	else {
		pdd u1 = getval(st, M, S, M, 2 * n);
		pdd u2 = getval(M + 1, en, M + 1, E, 2 * n + 1);
		
		pdd rv;
		rv.first = u1.first + u2.first;
		ldb u = exp(u1.second) + exp(u1.first + u2.second);
		rv.second = log(u);
		return rv;
	}
}
int main() {
	int N, Q, i, t1, t2, t3, t4;
	scanf("%d %d", &N, &Q);
	for (IT_MAX = 2; IT_MAX < N; IT_MAX *= 2);
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &t1, &t2);
		update(i, 1.0*(t2-t1)/t1);
	}
	while (Q--) {
		scanf("%d", &t1);
		if (t1 == 1) {
			scanf("%d %d %d", &t2, &t3, &t4);
			update(t2, 1.0*(t4-t3)/t3);
		}
		else {
			scanf("%d %d", &t2, &t3);
			ldb u = exp(getval(t2, t3, 1, IT_MAX, 1).second) + 1;
			printf("%.20lf\n", (db)(1.0 / u));
		}
	}
	return 0;
}
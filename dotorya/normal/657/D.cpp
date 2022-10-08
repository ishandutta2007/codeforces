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
const ll MOD = 987654321;
const int INF = 1034567890;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

pll in[200000];
int lr[200000][2];
ll sumt[200000];
ll cmp(pll a, pll b) {
	return a.first * b.second > a.second * b.first;
}

pll u[200050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i].first);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i].second);
	sort(in + 1, in + N + 1, cmp);

	int st = 1;
	for (i = 1; i <= N; i++) {
		if (i == N || cmp(in[st], in[i + 1])) {
			for (j = st; j <= i; j++) lr[j][0] = st, lr[j][1] = i;
			st = i + 1;
		}
		sumt[i] = sumt[i - 1] + in[i].second;
	}

	for (i = 1; i <= N; i++) u[i] = pll(in[i].first, -i);
	sort(u + 1, u + N + 1);

	ldb ans = 1;
	for (i = 1; i < N; i++) {
		if (u[i].first == u[i + 1].first) continue;

		ll t1 = -u[i].second;
		ll t2 = -u[i + 1].second;

		ldb v1 = 1.0 * (sumt[lr[t1][0] - 1] + in[t1].second) / sumt[N];
		ldb v2 = 1.0 * (sumt[lr[t2][1]]) / sumt[N];
		ldb v3 = u[i + 1].first * v2 - u[i].first * v1;
		if (v3 < ERR) continue;

		ans = min(ans, (u[i + 1].first - u[i].first) / v3);
	}

	printf("%.20lf\n", (db)ans);
	return 0;
}
//*/
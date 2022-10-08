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

class Node {
public:
	int v;
	ll sum;
	Node() {
		v = -1, sum = 0;
	}
};
Node it[600000];
void update(int st, int en, int S, int E, int n, int val) {
	if (st > en) return;
	if (st == S && en == E) {
		it[n].v = val;
		it[n].sum = (ll)(E - S + 1) * val;
		return;
	}

	if (it[n].v != -1) {
		it[2 * n].v = it[n].v;
		it[2 * n].sum = (ll)(E - S + 1) / 2 * it[n].v;
		it[2 * n + 1].v = it[n].v;
		it[2 * n + 1].sum = it[2 * n].sum;
		it[n].v = -1;
	}
	
	int M = (S + E) / 2;
	if (en <= M) update(st, en, S, M, 2 * n, val);
	else if (st > M) update(st, en, M + 1, E, 2 * n + 1, val);
	else {
		update(st, M, S, M, 2 * n, val);
		update(M + 1, en, M + 1, E, 2 * n + 1, val);
	}
	it[n].sum = it[2 * n].sum + it[2 * n + 1].sum;
}
ll getsum(int st, int en, int S, int E, int n) {
	if (st > en) return 0;
	if (st == S && en == E) return it[n].sum;
	if (it[n].v != -1) {
		it[2 * n].v = it[n].v;
		it[2 * n].sum = (ll)(E - S + 1) / 2 * it[n].v;
		it[2 * n + 1].v = it[n].v;
		it[2 * n + 1].sum = it[2 * n].sum;
		it[n].v = -1;
	}

	int M = (S + E) / 2;
	if (en <= M) return getsum(st, en, S, M, 2 * n);
	else if (st > M) return getsum(st, en, M + 1, E, 2 * n + 1);
	else return getsum(st, M, S, M, 2 * n) + getsum(M + 1, en, M + 1, E, 2 * n + 1);
}
void tupdate(int s, int e, int val) {
	int st = s, en = e, mi, rv = s - 1;
	while (st <= en) {
		mi = (st + en) / 2;
		if (getsum(mi, mi, 1, IT_MAX, 1) < val) {
			rv = mi;
			st = mi + 1;
		}
		else en = mi - 1;
	}
	update(s, rv, 1, IT_MAX, 1, val);
}
vector <int> V[200050];
ll cs = 0;
int main() {
	int N, i, t, j;
	scanf("%d", &N);
	for (IT_MAX = 2; IT_MAX < N; IT_MAX *= 2);
	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		for (j = 1; j*j <= t; j++) {
			if (t % j != 0) continue;
			V[j].push_back(i);
			if (j*j != t) V[t / j].push_back(i);
		}
	}

	for (i = 1; i <= N; i++) update(i, i, 1, IT_MAX, 1, i);
	cs = getsum(1, N, 1, IT_MAX, 1);

	ll ans = 0;
	for (i = 200000; i >= 1; i--) {
		if (V[i].size() < 2) continue;
		if (V[i].size() == 2) {
			tupdate(V[i][1] + 1, N, N + 1);
			tupdate(V[i][0] + 1, V[i][1], V[i][1]);
			tupdate(1, V[i][0], V[i][0]);
		}
		else {
			tupdate(V[i][1] + 1, N, N + 1);
			tupdate(V[i][0] + 1, V[i][1], V[i].back());
			tupdate(1, V[i][0], V[i][V[i].size() - 2]);
		}

		ll tcs = getsum(1, N, 1, IT_MAX, 1);
		ans += (tcs - cs) * i;
		cs = tcs;
	}
	printf("%lld\n", ans);
}
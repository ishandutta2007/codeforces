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
const db PI = 3.141592653589793238;
const ldb ERR = 1E-11;

class Matrixx {
public:
	ll v[2][2];
	Matrixx() {
		*this = Matrixx(0, 0, 0, 0);
	}
	Matrixx(ll a, ll b, ll c, ll d) {
		v[0][0] = a;
		v[0][1] = b;
		v[1][0] = c;
		v[1][1] = d;
	}
	Matrixx operator * (Matrixx l) {
		Matrixx rv = Matrixx();
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) rv.v[i][j] += v[i][k] * l.v[k][j];
				rv.v[i][j] %= MOD;
			}
		}
		return rv;
	}
};
class Node {
public:
	pll v;
	Matrixx x;
	Node() {
		*this = Node(pll(0, 0), Matrixx(1, 0, 0, 1));
	}
	Node(pll v, Matrixx x) : v(v), x(x) {}
};

Matrixx getpow(ll x) {
	Matrixx mul = Matrixx(1, 1, 1, 0);
	Matrixx rv = Matrixx(1, 0, 0, 1);
	while (x) {
		if (x % 2) rv = rv*mul;
		mul = mul*mul;
		x /= 2;
	}
	return rv;
}

pll operator + (pll a, pll b) {
	return pll((a.first + b.first) % MOD, (a.second + b.second) % MOD);
}

Node it[300050];
void update(int st, int en, int S, int E, int p, Matrixx x) {
	if (st == S && en == E) {
		Matrixx ux = x;
		pll u = it[p].v;
		it[p].v.first = (u.first * ux.v[0][0] + u.second * ux.v[0][1]) % MOD;
		it[p].v.second = (u.first * ux.v[1][0] + u.second * ux.v[1][1]) % MOD;
		it[p].x = it[p].x * x;
		return;
	}

	Matrixx ux = it[p].x;
	pll u = it[2 * p].v;
	it[2 * p].v.first = (u.first * ux.v[0][0] + u.second * ux.v[0][1]) % MOD;
	it[2 * p].v.second = (u.first * ux.v[1][0] + u.second * ux.v[1][1]) % MOD;
	it[2 * p].x = it[2*p].x * it[p].x;

	u = it[2 * p + 1].v;
	it[2 * p + 1].v.first = (u.first * ux.v[0][0] + u.second * ux.v[0][1]) % MOD;
	it[2 * p + 1].v.second = (u.first * ux.v[1][0] + u.second * ux.v[1][1]) % MOD;
	it[2 * p + 1].x = it[2*p+1].x * it[p].x;

	it[p].x = Matrixx(1, 0, 0, 1);

	int M = (S + E) / 2;
	if (en <= M) update(st, en, S, M, 2 * p, x);
	else if (st > M) update(st, en, M + 1, E, 2 * p + 1, x);
	else {
		update(st, M, S, M, 2 * p, x);
		update(M + 1, en, M + 1, E, 2 * p + 1, x);
	}
	it[p].v = it[2 * p].v + it[2 * p + 1].v;
}
pll getval(int st, int en, int S, int E, int p) {
	if (st == S && en == E) return it[p].v;

	Matrixx ux = it[p].x;
	pll u = it[2 * p].v;
	it[2 * p].v.first = (u.first * ux.v[0][0] + u.second * ux.v[0][1]) % MOD;
	it[2 * p].v.second = (u.first * ux.v[1][0] + u.second * ux.v[1][1]) % MOD;
	it[2 * p].x = it[2 * p].x * it[p].x;

	u = it[2 * p + 1].v;
	it[2 * p + 1].v.first = (u.first * ux.v[0][0] + u.second * ux.v[0][1]) % MOD;
	it[2 * p + 1].v.second = (u.first * ux.v[1][0] + u.second * ux.v[1][1]) % MOD;
	it[2 * p + 1].x = it[2 * p + 1].x * it[p].x;

	it[p].x = Matrixx(1, 0, 0, 1);

	int M = (S + E) / 2;
	if (en <= M) return getval(st, en, S, M, 2 * p);
	else if (st > M) return getval(st, en, M + 1, E, 2 * p + 1);
	else return getval(st, M, S, M, 2 * p) + getval(M + 1, en, M + 1, E, 2 * p + 1);
}

int main() {
	int N, M, i, j, t1, t2, t3, t4;
	scanf("%d %d", &N, &M);
	for (IT_MAX = 2; IT_MAX < N; IT_MAX *= 2);
	for (i = IT_MAX; i < IT_MAX + N; i++) it[i].v = pll(1, 1);
	for (i = IT_MAX - 1; i >= 1; i--) it[i].v = it[2 * i].v + it[2 * i + 1].v;

	for (i = 1; i <= N; i++) {
		scanf("%d", &j);
		if (j != 1) update(i, i, 1, IT_MAX, 1, getpow(j-1));
	}

	while (M--) {
		scanf("%d", &t1);
		if (t1 == 1) {
			scanf("%d %d %d", &t2, &t3, &t4);
			update(t2, t3, 1, IT_MAX, 1, getpow(t4));
		}
		else {
			scanf("%d %d", &t2, &t3);
			pll u = getval(t2, t3, 1, IT_MAX, 1);
			printf("%lld\n", u.second);
		}
	}
	return 0;
}
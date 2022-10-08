#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:1048576")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const db EPS = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

pll operator + (pll a, pll b) {
	return pll(a.first + b.first, a.second + b.second);
}

int nc = 1;
int son[6000000][2];
pll val[6000000];
int update(int st, int en, int p, int n, pll v) {
	if (st == en) {
		nc++;
		val[nc] = v;
		return nc;
	}
	int nn = ++nc;
	son[nn][0] = son[n][0], son[nn][1] = son[n][1];
	int mi = (st + en) / 2;
	if (p <= mi) son[nn][0] = update(st, mi, p, son[n][0], v);
	else son[nn][1] = update(mi + 1, en, p, son[n][1], v);
	val[nn] = val[son[nn][0]] + val[son[nn][1]];
	return nn;
}
pll getsum(int st, int en, int S, int E, int n) {
	if (n == 0) return pll(0, 0);
	if (st > en) return pll(0, 0);
	if (st == S && en == E) return val[n];

	int M = (S + E) / 2;
	return getsum(st, min(en, M), S, M, son[n][0]) + getsum(max(st, M + 1), en, M + 1, E, son[n][1]);
}

ll in[300050][3];
int u[300050];
int R[300050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		int x1, x2, y1, a, b, y2;
		scanf("%d %d %d %d %d %d", &x1, &x2, &y1, &a, &b, &y2);
		in[3 * i - 2][0] = 0, in[3 * i - 2][1] = 0, in[3 * i - 2][2] = y1;
		in[3 * i - 1][0] = x1 + 1, in[3 * i - 1][1] = a, in[3 * i - 1][2] = b - y1;
		in[3 * i][0] = x2 + 1, in[3 * i][1] = -a, in[3 * i][2] = -b + y2;
	}
	for (i = 1; i <= 3 * N; i++) u[i] = i;
	sort(u + 1, u + 3 * N + 1, [](int a, int b) {
		return in[a][0] < in[b][0];
	});

	int p = 1;
	for (i = 0; i <= 300000; i++) {
		R[i] = 1;
		if (i) R[i] = R[i - 1];
		while (p <= 3 * N) {
			int t = u[p];
			if (in[t][0] > i) break;
			R[i] = update(1, IT_MAX, t, R[i], pll(in[t][1], in[t][2]));
			p++;
		}
	}

	int Q;
	ll last = 0;
	scanf("%d", &Q);
	while (Q--) {
		int l, r;
		ll x;
		scanf("%d %d %lld", &l, &r, &x);
		x = (x + last) % 1000000000;

		ll nx = min(x, 300000ll);
		pll u = getsum(3 * l - 2, 3 * r, 1, IT_MAX, R[nx]);
		last = u.first * x + u.second;
		printf("%lld\n", last);
	}
	return 0;
}
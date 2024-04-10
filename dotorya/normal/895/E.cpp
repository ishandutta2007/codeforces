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
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-9;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

pdd mymerge(pdd a, pdd b) {
	return pdd(a.first*b.first, a.second*b.first + b.second);
}
class Node {
public:
	pdd v;
	db s;
	Node() {
		v = pdd(1, 0);
		s = 0;
	}
};
Node indt[300000];
void propagate(int n, int c) {
	pdd v = indt[n].v;
	indt[2 * n].v = mymerge(indt[2 * n].v, v);
	indt[2 * n].s = indt[2 * n].s * v.first + v.second * c;
	indt[2 * n + 1].v = mymerge(indt[2 * n + 1].v, v);
	indt[2 * n + 1].s = indt[2 * n + 1].s * v.first + v.second * c;
	indt[n].v = pdd(1, 0);
}
void update(int st, int en, int S, int E, int n, pdd v) {
	if (en < S || E < st) return;
	if (st <= S && E <= en) {
		indt[n].v = mymerge(indt[n].v, v);
		indt[n].s = v.first * indt[n].s + v.second * (E-S+1);
		return;
	}
	propagate(n, (E-S+1)/2);

	int M = (S + E) / 2;
	update(st, en, S, M, 2 * n, v);
	update(st, en, M + 1, E, 2 * n + 1, v);
	indt[n].s = indt[2 * n].s + indt[2 * n + 1].s;
}
db getsum(int st, int en, int S, int E, int n) {
	if (en < S || E < st) return 0;
	if (st <= S && E <= en) return indt[n].s;

	propagate(n, (E-S+1)/2);
	int M = (S + E) / 2;
	return getsum(st, en, S, M, 2 * n) + getsum(st, en, M + 1, E, 2 * n + 1);
}
int main() {
	int N, Q, i, j;
	scanf("%d %d", &N, &Q);
	for (i = 1; i <= N; i++) scanf("%lf", &indt[IT_MAX + i - 1].s);
	for (i = IT_MAX - 1; i >= 1; i--) indt[i].s = indt[2 * i].s + indt[2 * i + 1].s;

	while (Q--) {
		int t1;
		scanf("%d", &t1);
		if (t1 == 1) {
			int t2, t3, t4;
			scanf("%d %d %d %d", &t1, &t2, &t3, &t4);

			db s1 = getsum(t1, t2, 1, IT_MAX, 1);
			db s2 = getsum(t3, t4, 1, IT_MAX, 1);

			update(t1, t2, 1, IT_MAX, 1, pdd((db)(t2 - t1) / (t2 - t1 + 1), (db)s2 / (t2 - t1 + 1) / (t4 - t3 + 1)));
			update(t3, t4, 1, IT_MAX, 1, pdd((db)(t4 - t3) / (t4 - t3 + 1), (db)s1 / (t4 - t3 + 1) / (t2 - t1 + 1)));
		}
		else {
			int t2, t3;
			scanf("%d %d", &t2, &t3);
			printf("%.20lf\n", getsum(t2, t3, 1, IT_MAX, 1));
		}
	}
	return 0;
}
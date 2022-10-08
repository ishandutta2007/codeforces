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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-9;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

class Node {
public:
	ll mn, v;
	Node() {
		mn = v = 0;
	}
};
Node indt[600000];
void propagate(int n) {
	ll v = indt[n].v;
	indt[2 * n].mn += v;
	indt[2 * n].v += v;
	indt[2 * n + 1].mn += v;
	indt[2 * n + 1].v += v;
	indt[n].v = 0;
}
void update(int st, int en, int S, int E, int n, ll v) {
	if (en < S || E < st) return;
	if (st <= S && E <= en) {
		indt[n].v += v;
		indt[n].mn += v;
		return;
	}
	propagate(n);

	int M = (S + E) / 2;
	update(st, en, S, M, 2 * n, v);
	update(st, en, M + 1, E, 2 * n + 1, v);
	indt[n].mn = min(indt[2 * n].mn, indt[2 * n + 1].mn);
}
ll getmn(int st, int en, int S, int E, int n) {
	if (en < S || E < st) return LL_INF;
	if (st <= S && E <= en) return indt[n].mn;
	propagate(n);

	int M = (S + E) / 2;
	return min(getmn(st, en, S, M, 2 * n), getmn(st, en, M + 1, E, 2 * n + 1));
}

ll X[200050];
ll Y[200050];
vector <pll> Ve[200050];

ll ans[200050];
multiset <ll> Sa;
int main() {
	int N, M, Q, i, j;
	scanf("%d %d %d", &N, &M, &Q);
	for (i = 1; i < N; i++) scanf("%lld %lld", &X[i], &Y[i]);

	for (i = 1; i < N; i++) update(i, i, 0, IT_MAX - 1, 1, Y[i]);
	while (M--) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		Ve[t1].emplace_back(t3, t2);
	}

	for (i = 1; i <= N; i++) {
		for (auto it : Ve[i]) update(0, it.second - 1, 0, IT_MAX - 1, 1, it.first);
		ans[i] = getmn(0, N - 1, 0, IT_MAX - 1, 1);
	}
	for (i = 1; i <= N; i++) {
		ans[i] += X[i];
		Sa.insert(ans[i]);
	}
	printf("%lld\n", *(Sa.begin()));
	while (Q--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		Sa.erase(Sa.lower_bound(ans[t1]));
		ans[t1] -= X[t1];
		X[t1] = t2;
		ans[t1] += X[t1];
		Sa.insert(ans[t1]);
		printf("%lld\n", *(Sa.begin()));
	}
	return 0;
}
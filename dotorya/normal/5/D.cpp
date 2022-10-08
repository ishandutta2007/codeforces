#include <stdio.h>
#include <algorithm>
#include <assert.h>
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
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
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

int IT_MAX = 1 << 21;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1034567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

int main() {
	ll A, V, L, D, W;
	scanf("%lld %lld %lld %lld %lld", &A, &V, &L, &D, &W);

	if (V <= W || 2 * A*D <= W*W) {
		if (V*V >= 2 * A*L) return !printf("%.20lf\n", sqrt(2.0 * L / A));
		else return !printf("%.20lf\n", 1.0 * V / (2 * A) + 1.0 * L / V);
	}

	db st = W, en = V, mi;
	for (int i = 1; i <= 100; i++) {
		mi = (st + en) / 2;
		db u = (2 * mi*mi - W*W) / (2 * A);
		if (u <= D) st = mi;
		else en = mi;
	}

	db a1 = (2 * mi - W) / A;
	a1 += (D - (2 * mi*mi - W*W) / (2 * A)) / mi;

	L -= D;

	st = 0, en = INF, mi;
	for (int i = 1; i <= 100; i++) {
		mi = (st + en) / 2;

		db d = 0;
		db u = 1.0 * (V - W) / A;
		if (mi <= u) d = W*mi + 0.5*A*mi*mi;
		else d = W*u + 0.5*A*u*u + V * (mi - u);

		if (d <= L) st = mi;
		else en = mi;
	}
	return !printf("%.20lf\n", a1 + mi);
}
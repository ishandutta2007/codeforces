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

int IT_MAX = 1 << 21;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-12;

ll in[10050][2];

map <ll, int> Mx;
ll Mv[100050];
int main() {
	int N, i, j;
	ll w, v, u;

	scanf("%d %lld %lld %lld", &N, &w, &v, &u);
	for (i = 0; i < N; i++) scanf("%lld %lld", &in[i][0], &in[i][1]);

	for (i = 0; i < N; i++) if (-u*in[i][0] + in[i][1]*v > 0) break;
	if (i >= N) return !printf("%.20lf\n", 1.0 * w / u);

	ldb t = 0;
	for (i = 0; i < N; i++) {
		ll x = in[i][0], y = in[i][1];
		ldb t1 = max(1.0*x / v, 1.0*y / u);
		ldb t2 = 1.0 * (w - y) / u;
		t = max(t, t1 + t2);
	}
	return !printf("%.20lf\n", (db)t);
}
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
#include <cmath>
#include <vector>
#include <deque>
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

int IT_MAX = 1<<19;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-10;

ll N, M, K, X, S;
ll A[200050];
ll B[200050];
ll C[200050];
ll D[200050];
ll getval(ll c, ll m, ll x) {
	int st = 1, en = K, mi, rv = 0;
	while (st <= en) {
		mi = (st + en) / 2;
		if (D[mi] <= m) {
			rv = mi;
			st = mi + 1;
		}
		else en = mi - 1;
	}
	return max(0ll, c - C[rv]) * x;
}
int main() {
	ll i, j;
	scanf("%lld %lld %lld", &N, &M, &K);
	scanf("%lld %lld", &X, &S);
	for (i = 1; i <= M; i++) scanf("%lld", A + i);
	for (i = 1; i <= M; i++) scanf("%lld", B + i);
	for (i = 1; i <= K; i++) scanf("%lld", C + i);
	for (i = 1; i <= K; i++) scanf("%lld", D + i);

	ll ans = getval(N, S, X);
	for (i = 1; i <= M; i++) {
		if (B[i] > S) continue;
		
		ans = min(ans, getval(N, S - B[i], A[i]));
	}
	return !printf("%lld\n", ans);
}
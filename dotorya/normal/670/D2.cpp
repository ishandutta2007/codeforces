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
const int INF = 2034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

ll A[100050];
ll B[100050];
int main() {
	int N, K, i;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (i = 1; i <= N; i++) scanf("%lld", &B[i]);
	ll st = 1, en = INF, mi, rv = 0;
	while (st <= en) {
		mi = (st + en) / 2;
		ll t = K;
		for (i = 1; i <= N; i++) {
			t -= max(0ll, A[i] * mi - B[i]);
			if (t < 0) break;
		}
		if (i > N) {
			rv = mi;
			st = mi + 1;
		}
		else en = mi - 1;
	}
	printf("%lld\n", rv);
	return 0;
}
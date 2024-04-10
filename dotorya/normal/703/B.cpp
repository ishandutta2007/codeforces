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

bool chk[100050];
ll C[100050];
ll sum[100050];
ll csum[100050];
int main() {
	int N, K, t, i;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		scanf("%lld", &C[i]);
		sum[i] = sum[i - 1] + C[i];
	}
	for (i = 1; i <= K; i++) {
		scanf("%d", &t);
		chk[t] = true;
	}
	for (i = N; i >= 1; i--) {
		csum[i] = csum[i + 1];
		if (chk[i]) csum[i] += C[i];
	}

	ll ans = 0;
	for (i = 1; i < N; i++) {
		if (!chk[i]) {
			ll t = C[i + 1] + csum[i + 2];
			ans += C[i] * t;
		}
		else ans += C[i] * (sum[N] - sum[i]);
	}
	if (!chk[1] && !chk[N]) ans += C[1] * C[N];
	return !printf("%lld\n", ans);
}
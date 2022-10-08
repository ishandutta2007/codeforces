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
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

ll in[1000050];
ll L[1000050];
ll R[1000050];
ll LR[1000050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i]), in[i]--;

	L[1] = in[1];
	for (i = 2; i <= N; i++) {
		L[i] = max(1ll, in[i] - in[i - 1] + 1);
		L[i] = in[i] - L[i] + 1;
	}
	R[N] = in[N];
	for (i = 1; i < N; i++) {
		R[i] = max(1ll, in[i] - in[i + 1] + 1);
		R[i] = in[i] - R[i] + 1;
	}
	for (i = 1; i <= N; i++) LR[i] = min(L[i], R[i]);
	for (i = 1; i <= N; i++) swap(L[i], R[i]);

	ll ans = 0, v = 0;
	for (i = 2; i <= N; i++) {
		v = (v * LR[i - 1] + L[i - 1]) % MOD;
		ans = (ans + R[i] * v) % MOD;
	}

	for (i = 1; i <= N; i++) ans = (ans + in[i]) % MOD;
	printf("%lld\n", ans);
	return 0;
}
//*/
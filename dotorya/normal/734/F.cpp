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

ll B[200050];
ll C[200050];
ll A[200050];

ll cnt[32];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld", &B[i]);
	for (i = 1; i <= N; i++) scanf("%lld", &C[i]);

	if (N == 1) {
		if (B[1] != C[1]) return !printf("-1\n");
		else return !printf("%lld\n", B[1]);
	}

	ll s = 0;
	for (i = 1; i <= N; i++) s += B[i] + C[i];

	if (s % (2*N)) return !printf("-1\n");
	s /= 2 * N;

	for (i = 1; i <= N; i++) {
		ll v = B[i] + C[i] - s;
		if (v % N || v < 0) return !printf("-1\n");
		A[i] = v / N;
		if (A[i] > INF) return !printf("-1\n");
	}
	for (i = 1; i <= N; i++) for (j = 0; j <= 30; j++) if (A[i] & (1 << j)) cnt[j]++;

	for (i = 1; i <= N; i++) {
		ll s = 0;
		for (j = 0; j <= 30; j++) {
			if (A[i] & (1 << j)) s += cnt[j] * (1 << j);
		}
		if (s != B[i]) return !printf("-1\n");
	}
	for (i = 1; i <= N; i++) {
		ll s = 0;
		for (j = 0; j <= 30; j++) {
			if (A[i] & (1 << j)) s += N * (1 << j);
			else s += cnt[j] * (1 << j);
		}
		if (s != C[i]) return !printf("-1\n");
	}
	for (i = 1; i <= N; i++) printf("%lld ", A[i]);
	return !printf("\n");
}
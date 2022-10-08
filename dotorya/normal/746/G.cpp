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
const ll MOD = 5000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-11;

int in[200050];
int lr[200050][2];
int v[200050];

int main() {
	int N, T, K, i, j;
	scanf("%d %d %d", &N, &T, &K);
	for (i = 1; i <= T; i++) scanf("%d", &in[i]);
	in[0] = 1;

	for (i = 1; i < T; i++) {
		lr[i][1] = in[i] - 1;
		lr[i][0] = max(0, in[i] - in[i + 1]);
	}
	lr[T][0] = lr[T][1] = in[T];

	int mn = 0, mx = 0;
	for (i = 1; i <= T; i++) mn += lr[i][0], mx += lr[i][1];
	if (K < mn || mx < K) return !printf("-1\n");

	int t = K - mn;
	for (i = 1; i <= T; i++) {
		int t2 = min(t, lr[i][1] - lr[i][0]);
		t -= t2;
		v[i] = in[i] - (lr[i][0] + t2);
	}
	v[0] = 1;

	printf("%d\n", N);

	int pst = 1;
	for (i = 1; i <= T; i++) {
		int st = pst + in[i-1];
		for (j = 0; j < v[i - 1]; j++) printf("%d %d\n", pst + j, st + j);
		for (j = v[i - 1]; j < in[i]; j++) printf("%d %d\n", pst, st + j);
		pst = st;
	}
	return 0;
}
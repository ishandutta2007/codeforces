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
const int MOD = 1000000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-12;

int A[100050];
int B[100050];

int main() {
	int N, M, i;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%d", A + i);
	for (i = 1; i <= M; i++) scanf("%d", B + i);

	int ans = 0;
	for (i = 1; i <= N; i++) {
		int d = INF * 2;
		int st = 1, en = M, mi, rv = 0;
		while (st <= en) {
			mi = (st + en) / 2;
			if (B[mi] <= A[i]) {
				rv = mi;
				st = mi + 1;
			}
			else en = mi - 1;
		}
		if (rv != 0) d = min(d, A[i] - B[rv]);
		if (rv != M) d = min(d, B[rv + 1] - A[i]);
		ans = max(ans, d);
	}
	return !printf("%d\n", ans);
}
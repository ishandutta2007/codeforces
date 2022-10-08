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

int IT_MAX = 524288;
const int MOD = 100000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-12;

ll sum[200050];
int in[200050];
bool chk[200050];
int main() {
	int N, i, j, t;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		sum[in[i]]++;
	}
	for (i = 1; i <= 200000; i++) sum[i] += sum[i - 1];

	ll mx = 0;
	for (i = 1; i <= N; i++) {
		if (chk[in[i]]) continue;
		chk[in[i]] = true;
		ll s = 0;
		for (j = in[i]; j <= 200000; j += in[i]) s += j * (sum[min(j + in[i] - 1, 200000)] - sum[j - 1]);
		mx = max(mx, s);
	}
	return !printf("%lld\n", mx);
}
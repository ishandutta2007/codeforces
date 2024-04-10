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
const ldb ERR = 1E-8;

ll po1[1000050];
ll po2[1000050];
int main() {
	int N, M, i;
	scanf("%d %d", &N, &M);

	po1[0] = po2[0] = 1;
	for (i = 1; i <= N; i++) {
		po1[i] = (po1[i - 1] * M) % MOD;
		po2[i] = (po2[i - 1] * (2 * M - 1)) % MOD;
	}

	ll ans = po1[N];
	for (i = 0; i < N; i++) ans = (ans + po1[N - i] * po2[i]) % MOD;
	printf("%lld\n", ans);
	return 0;
}
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
const int MOD = 100000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-10;

pll in[200050];
ll G[200050];
int main() {
	ll N, K, S, T, i;
	scanf("%lld %lld %lld %lld", &N, &K, &S, &T);
	for (i = 1; i <= N; i++) scanf("%lld %lld", &in[i].first, &in[i].second);
	for (i = 1; i <= K; i++) scanf("%lld", &G[i]);

	sort(in + 1, in + N + 1);
	G[0] = 0;
	sort(G + 1, G + K + 1);
	G[K + 1] = S;

	for (i = 2; i <= N; i++) in[i].second = max(in[i].second, in[i - 1].second);

	int st = 1, en = N, mi, rv = N + 1;
	while (st <= en) {
		mi = (st + en) / 2;
		
		ll v = in[mi].second;

		ll s = 0;
		for (i = 0; i <= K; i++) {
			ll d = G[i+1] - G[i];
			if (d > v) break;

			if (2 * d <= v) s += d;
			else s += 3 * d - v;
		}
		if (s <= T && i > K) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
	}
	if (rv == N + 1) return !printf("-1\n");
	else return !printf("%d\n", in[rv].first);
	return 0;
}
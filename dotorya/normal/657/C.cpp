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
const ll MOD = 987654321;
const int INF = 1034567890;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

ll in[200050];

priority_queue <ll> H[5];
ll sum[5];

int main() {
	int N, K, i, j;
	ll B, C;

	scanf("%d %d %lld %lld", &N, &K, &B, &C);
	B = min(5 * C, B);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i]);
	sort(in + 1, in + N + 1);

	for (i = 1; i < K; i++) {
		for (j = 0; j < 5; j++) {
			ll t = INF + j - in[i];
			ll t2 = (t / 5)*B + (t % 5)*C;
			H[j].push(t2);
			sum[j] += t2;
		}
	}

	ll ans = LL_INF;
	for (i = K; i <= N; i++) {
		for (j = 0; j < 5; j++) {
			ll t = INF + j - in[i];
			ll t2 = (t / 5)*B + (t % 5)*C;
			H[j].push(t2);
			sum[j] += t2;
			if (H[j].size() > K) {
				sum[j] -= H[j].top();
				H[j].pop();
			}
		}
		for (j = 0; j < 5; j++) {
			ll t = in[i] + j;
			ll t2 = (t % 5 + 5) % 5;

			ll v = sum[t2] - (INF + t2 - t) / 5 * (B * K);
			ans = min(ans, v);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
//*/
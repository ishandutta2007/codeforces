#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first

ll mul_inv(ll a, ll b = MOD) {
	ll t1 = a, t2 = b, t3;
	ll v1 = 1, v2 = 0, v3;
	while (t2 != 1) {
		ll x = t1 / t2;
		t3 = t1 - x*t2;
		v3 = v1 - x*v2;
		t1 = t2, t2 = t3;
		v1 = v2, v2 = v3;
	}
	return (v2 + b) % b;
}

ll ans[10050];

ll A[5050];
ll mul[5050];
ll minv[5050];

ll sum[5050];
int main() {
	int N, i;
	scanf("%d", &N);
	mul[0] = 1;
	for (i = 1; i < N; i++) {
		scanf("%lld", &A[i]);
		mul[i] = mul[i - 1] * A[i] % MOD;
	}
	for (i = 0; i < N; i++) minv[i] = mul_inv(mul[i]);

	ll m2 = mul_inv(2);
	for (int qr = 4; qr <= 2 * N; qr++) {
		for (int q = 1; q <= N; q++) {
			sum[q] = sum[q - 1];
			int r = qr - q;
			if (r < 1 || r > N) continue;

			sum[q] = (sum[q] + mul[q - 1] * mul[r - 1]) % MOD;
		}
		for (int p = 1; p < N; p++) {
			int st = p + 1;
			int en = min(N, qr - p - 1);
			if (st > en) continue;

			ll v = (sum[en] - sum[st - 1]);
			v = v * minv[p] % MOD;
			v = v * (A[p] - 1) % MOD;
			v = v * m2 % MOD;

			ans[qr - 2 * p] = (ans[qr - 2 * p] + v) % MOD;
		}
	}
	for (int i = 1; i <= N; i++) {
		ll c = mul[i - 1];
		for (int j = i + 1; j <= N; j++) {
			c *= A[j - 1];
			c %= MOD;
			ans[j - i] = (ans[j - i] + c) % MOD;
		}
	}
	for (i = 1; i <= 2 * N - 2; i++) printf("%lld ", ans[i]);
	return !printf("\n");
}
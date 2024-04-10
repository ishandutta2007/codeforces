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
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

ll mul_inv(ll a, ll b = MOD)
{
	ll b0 = b, t, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

ll F[300050];
ll Finv[300050];
inline ll Comb(int a, int b) {
	if (b < 0 || b > a) return 0;
	ll rv = F[a];
	rv = (rv*Finv[b]) % MOD;
	rv = (rv*Finv[a - b]) % MOD;
	return rv;
}

ll po2[300050];
ll sum[300050];
ll sum2[300050];
ll sum3[300050];
ll sum4[300050];
ll sum5[300050];

bool pchk[300050];
vector <int> plist;
int cnt[300050][20];
int main() {
	int i, j, t;
	pchk[1] = true;
	for (i = 2; i <= 300000; i++) {
		if (pchk[i]) continue;
		plist.push_back(i);
		for (j = 2 * i; j <= 300000; j += i) pchk[j] = true;
	}

	int N;
	scanf("%d", &N);
	if (N == 1) return !printf("0\n");

	for (i = 0; i < N; i++) {
		scanf("%d", &t);
		for (auto it : plist) {
			if (it*it > t) break;
			if (t % it) continue;
			int t2 = 0;
			while (t % it == 0) {
				t2++;
				t /= it;
			}
			cnt[it][t2]++;
		}
		if (t != 1) cnt[t][1]++;
	}

	po2[0] = 1;
	for (i = 1; i <= N; i++) po2[i] = (po2[i - 1] * 2) % MOD;
	F[0] = 1;
	for (i = 1; i <= N; i++) F[i] = (F[i - 1] * i) % MOD;
	for (i = 0; i <= N; i++) Finv[i] = mul_inv(F[i]);
	
	sum[0] = 1;
	for (i = 1; i <= N; i++) {
		sum[i] = F[N];
		sum[i] = (sum[i] * mul_inv(F[i])) % MOD;
		sum[i] = (sum[i] * mul_inv(F[N - i])) % MOD;
		sum[i] = (sum[i] + sum[i - 1]) % MOD;
	}

	sum2[N] = 0;
	for (i = N - 1; i >= 1; i--) sum2[i] = (sum2[i + 1] + Comb(N - 1, i)) % MOD;
	for (i = 1; i <= N; i++) sum3[i] = (sum3[i - 1] + sum2[i]) % MOD;
	for (i = 1; i <= N; i++) sum4[i] = (po2[N - 1] - sum2[i] - Comb(N - 1, i - 1) + 2 * MOD) % MOD;
	for (i = 1; i <= N; i++) sum5[i] = (sum5[i - 1] + sum4[i]) % MOD;

	ll ans = 0;
	for (i = 2; i <= 300000; i++) {
		t = N;
		for (j = 1; j <= 19; j++) t -= cnt[i][j];

		for (j = 1; j <= 19; j++) {
			int t2 = t + cnt[i][j];
			ans += j * (sum5[t2] - sum5[t] - sum3[t2] + sum3[t] + 2*MOD) % MOD;
			ans %= MOD;
			t = t2;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
//*/
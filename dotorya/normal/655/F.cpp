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
const int INF = 1034567891;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-12;

ll mul_inv(ll a, ll b)
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

ll F[2000050];
ll Finv[2000050];

inline ll C(int x, int y) {
	ll rv = F[x];
	rv = (rv * Finv[y]) % MOD;
	rv = (rv * Finv[x-y]) % MOD;
	return rv;
}

int pchk[1000050];
int pi[1000050];

int cnt[1000050];

vector <int> D[1000050];
int main() {
	int i, j;
	for (i = 1; i <= 1000000; i++) pi[i] = i;
	for (i = 2; i <= 1000000; i++) {
		if (pchk[i]) continue;
		for (j = i; j <= 1000000; j += i) {
			pi[j] /= i;
			pi[j] *= i - 1;
			pchk[j] = true;
		}
		pchk[i] = false;
	}

	F[0] = 1;
	for (i = 1; i <= 2000000; i++) F[i] = (F[i - 1] * i) % MOD;
	for (i = 0; i <= 2000000; i++) Finv[i] = mul_inv(F[i], MOD);
	for (i = 1; i <= 1000000; i++) for (j = i; j <= 1000000; j += i) D[j].push_back(i);

	int N, K, Q, t;
	scanf("%d %d %d", &N, &K, &Q);

	ll ans = 0;
	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		for (auto it : D[t]) {
			cnt[it]++;
			if (cnt[it] >= K) ans += C(cnt[it] - 1, K - 1) * pi[it];
			ans %= MOD;
		}
	}

	for (i = 1; i <= Q; i++) {
		scanf("%d", &t);
		for (auto it : D[t]) {
			cnt[it]++;
			if (cnt[it] >= K) ans += C(cnt[it] - 1, K - 1) * pi[it];
			ans %= MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
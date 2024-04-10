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

int IT_MAX = 1 << 19;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll mypow(ll a, ll b) {
	ll rv = 1;
	while (b) {
		if (b % 2) rv = rv*a%MOD;
		a = a*a %MOD;
		b /= 2;
	}
	return rv;
}

int Co[5050][5050];

ll dp[5050];
ll val[5050];
ll tval[5050];
int main() {
	int N, K, i, j, k;
	scanf("%d %d", &N, &K);
	if (N <= K) {
		for (i = 0; i <= 5000; i++) {
			Co[i][0] = Co[i][i] = 1;
			for (j = 1; j < i; j++) Co[i][j] = (Co[i - 1][j - 1] + Co[i - 1][j]) % MOD;
		}

		ll ans = 0;
		for (i = 1; i <= N; i++) {
			ll v = Co[N][i] * mypow(i, K) % MOD;
			ans = (ans + v) % MOD;
		}
		return !printf("%lld\n", ans);
	}

	dp[0] = mypow(2, N);
	val[0] = 1;
	for (i = 1; i <= K; i++) {
		for (j = 0; j <= K; j++) tval[j] = 0;
		for (j = 0; j <= K; j++) {
			tval[j] += val[j] * (-i + 1);
			if (j) tval[j] += val[j - 1];
		}
		for (j = 0; j <= K; j++) val[j] = (tval[j] % MOD + MOD) % MOD;

		dp[i] = 1;
		for (j = N; j > N - i; j--) dp[i] = dp[i] * j % MOD;
		dp[i] = dp[i] * mypow(2, N - i) % MOD;
		for (j = i - 1; j >= 0; j--) dp[i] = (dp[i] - val[j] * dp[j]) % MOD;
		dp[i] = (dp[i] + MOD) % MOD;
	}
	return !printf("%lld\n", dp[K]);
}
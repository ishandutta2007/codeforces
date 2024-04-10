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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
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

int K;
ll dp[1050][1050];
ll getdp(int a, int b) {
	if (b >= K) return b;
	return dp[a][b];
}
int main() {
	int Pa, Pb, i, j;
	scanf("%d %d %d", &K, &Pa, &Pb);
	for (i = 0; i < K; i++) {
		dp[K][i] = (i + K + Pa * mul_inv(Pb)) % MOD;
	}
	for (i = K - 1; i >= 1; i--) {
		for (j = K - 1; j >= 0; j--) {
			dp[i][j] = Pa * getdp(i + 1, j) + Pb * getdp(i, i + j);
			dp[i][j] %= MOD;
			dp[i][j] = (dp[i][j] * mul_inv(Pa + Pb)) % MOD;
		}
	}
	return !printf("%lld\n", dp[1][0]);
}
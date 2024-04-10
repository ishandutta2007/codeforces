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

int IT_MAX = 1 << 20;
ll MOD = 1000000007;
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
		if (b % 2) rv = (rv*a) % MOD;
		a = a*a%MOD;
		b /= 2;
	}
	return rv;
}

bool pchk[2000050];
int v1[2000050];
ll v2[2000050];
ll del[2000050];
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);

	for (i = 1; i <= 2000000; i++) v1[i] = 1;
	for (i = 2; i <= 2000000; i++) {
		if (pchk[i]) continue;
		for (j = 2 * i; j <= 2000000; j += i) pchk[j] = true;
		for (j = i; j <= 2000000; j += i) v1[j] *= -1;
		if (i <= 10000) for (j = i*i; j <= 2000000; j += i*i) v1[j] = 0;
	}
	for (i = 1; i <= 2000000; i++) v2[i] = mypow(i, N);

	for (i = 1; i <= K; i++) {
		for (j = 1;; j++) {
			int st = i*j, en = i*(j + 1) - 1;
			if (st > K) break;
			en = min(en, K);
			del[st] = (del[st] + v1[i] * v2[j] % MOD + MOD) % MOD;
			del[en + 1] = (del[en+1] - v1[i] * v2[j] % MOD + MOD) % MOD;
		}
	}

	ll ans = 0;
	for (i = 1; i <= K; i++) {
		del[i] = (del[i] + del[i - 1]) % MOD;
		ans = (ans + (del[i] ^ i)) % MOD;
	}
	return !printf("%lld\n", ans);
}

//*/
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
#pragma comment(linker, "/STACK:33554432")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

map <int, int> Mx;
int ch(int x) {
	if (Mx.count(x)) return Mx[x];
	int t = Mx.size() + 1;
	return Mx[x] = t;
}

int cnt[305];
ll F[605];
ll C[605][605];

ll dp[305];
ll tdp[305];
int main() {
	int N, i, j, k, l;
	scanf("%d", &N);

	F[0] = 1;
	for (i = 1; i <= 600; i++) F[i] = F[i - 1] * i % MOD;
	for (i = 0; i <= 600; i++) {
		C[i][0] = C[i][i] = 1;
		for (j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}

	for (i = 1; i <= N; i++) {
		int t, v = 1;
		scanf("%d", &t);
		for (j = 2; j * j <= t; j++) {
			if (t%j) continue;

			int c = 0;
			while (t%j == 0) {
				t /= j;
				c++;
			}
			if (c % 2) v *= j;
		}
		if (t != 1) v *= t;
		cnt[ch(v)]++;
	}
	N = Mx.size();

	dp[1] = 1;
	for (i = 1; i <= N; i++) {
		for (j = 0; j <= 300; j++) tdp[j] = 0;
		int x = cnt[i];
		for (j = 1; j <= 300; j++) {
			for (k = 1; k <= x && k <= j; k++) {
				ll v = C[x - 1][x - k] * C[j][k] % MOD;
				for (l = 0; l <= 2 * k; l++) {
					ll v2 = v * C[2 * k][l] % MOD;
					int t = j + l - k + (x - k);
					if (t >= 0 && t <= 300) tdp[t] = (tdp[t] + dp[j] * v2) % MOD;
				}
			}
		}
		for (j = 0; j <= 300; j++) dp[j] = tdp[j];
	}

	ll ans = dp[0];
	for (i = 1; i <= N; i++) ans = ans * F[cnt[i]] % MOD;
	return !printf("%lld\n", ans);
}
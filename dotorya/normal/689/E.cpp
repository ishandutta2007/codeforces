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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-13;

map <int, int> Mx;
int Mv[500050];
pii in[200050];

int del[500050];

ll F[500050];
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
ll C(ll a, ll b) {
	if (a < b) return 0;
	ll rv = F[a];
	rv = (rv * mul_inv(F[b])) % MOD;
	rv = (rv * mul_inv(F[a - b])) % MOD;
	return rv;
}
int main() {
	int N, K, i;
	F[0] = 1;
	for (i = 1; i <= 500000; i++) F[i] = (F[i - 1] * i) % MOD;
	
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &in[i].first, &in[i].second);
		Mx[in[i].first] = 0;
		Mx[in[i].second + 1] = 0;
	}

	i = 0;
	for (auto &it : Mx) {
		it.second = ++i;
		Mv[i] = it.first;
	}
	for (i = 1; i <= N; i++) {
		del[Mx[in[i].first]]++;
		del[Mx[in[i].second + 1]]--;
	}
	for (i = 1; i <= Mx.size(); i++) del[i] += del[i - 1];

	ll ans = 0;
	for (i = 1; i < Mx.size(); i++) ans = (ans + (Mv[i + 1] - Mv[i]) * C(del[i], K)) % MOD;
	return !printf("%lld\n", ans);
}
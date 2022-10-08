//*
#include <algorithm>
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


#define pow10 pasiodfiopsdjviozjxciovjxcviozj
#define pow2 qpowdskopjkcoizxnzoicn

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <char, int> pci;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef pair <ldb, int> pdi;
typedef pair <ldb, ll> pdl;

int IT_MAX;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;

int main() {
	int P, K, i;
	scanf("%d %d", &P, &K);

	if (K == 0) {
		ll ans = 1;
		for (i = 1; i <= P - 1; i++) ans = (ans*P) % MOD;
		return !printf("%lld\n", ans);
	}

	if (K == 1) {
		ll ans = 1;
		for (i = 1; i <= P; i++) ans = (ans*P) % MOD;
		return !printf("%lld\n", ans);
	}

	ll v;
	for (i = 1, v = K; v != 1; i++, v = (v*K) % P);

	int t = (P - 1) / i;
	ll ans = 1;
	for (i = 1; i <= t; i++) ans = (ans*P) % MOD;
	return !printf("%lld\n", ans);
}
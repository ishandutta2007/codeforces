//*
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

int IT_MAX = 4096;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int cnt0(int x) {
	int rv = 6;
	for (int i = 0; i < 6; i++) if (x & (1 << i)) rv--;
	return rv;
}
int ch(char c) {
	if (c >= '0' && c <= '9') return c - '0';
	if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
	if (c >= 'a' && c <= 'z') return c - 'a' + 36;
	if (c == '-') return 62;
	if (c == '_') return 63;
	return 64;
}
char in[100050];
int main() {
	scanf("%s", in);
	int i, cnt = 0;

	for (i = 0; in[i] != 0; i++) cnt += cnt0(ch(in[i]));

	ll ans = 1;
	while (cnt--) ans = (ans * 3) % MOD;
	return !printf("%lld\n", ans);
}
//*/
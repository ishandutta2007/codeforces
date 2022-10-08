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

int in[100050];
int main() {
	int N, K, H, i, j;
	scanf("%d %d %d", &N, &H, &K);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	int p = in[1];

	ll ans = 0;
	for (i = 1; i < N; i++) {
		ans += p / K;
		p %= K;
		if (p + in[i + 1] <= H) p += in[i + 1];
		else {
			ans++;
			p = in[i + 1];
		}
	}
	ans += (p + K - 1) / K;
	return !printf("%lld\n", ans);
}
//*/
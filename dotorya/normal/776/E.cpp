#include <algorithm>
#include <assert.h>
#include <bitset>
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
#include <string>
#include <time.h>
#include <cmath>
#include <vector>
#include <deque>
//#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
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

int IT_MAX = 1 << 20;
const ll MOD = 98765431;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-6;

bool pchk[1000050];
vector <ll> plist;
ll pi[1000050];
ll dp[1000050];
ll tdp[1000050];
ll nxt[1000050];

ll getans(ll N, ll K) {
	if (K == 0) return N;

	ll rv = N;
	for (auto it : plist) {
		if (it*it > N) break;
		if (N % it) continue;
		rv /= it;
		rv *= it - 1;
		while (N%it == 0) N /= it;
	}
	if (N != 1) {
		rv /= N;
		rv *= N - 1;
	}
	return getans(rv, K-1);
}
int main() {
	ll N, K, i, j;
	scanf("%lld %lld", &N, &K);
	for (i = 1; i <= 1000000; i++) pi[i] = i;
	for (i = 2; i <= 1000000; i++) {
		if (pchk[i]) continue;
		plist.push_back(i);
		for (j = 2 * i; j <= 1000000; j += i) pchk[j] = true;
	}
	K = (K + 1) / 2;

	if (K > 80) return !printf("1\n");
	return !printf("%lld\n", getans(N, K)%1000000007);
}
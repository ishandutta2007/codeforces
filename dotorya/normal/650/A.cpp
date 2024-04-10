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
const ll MOD = 1000000009;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

map <pii, ll> Mp;
map <int, ll> Mx;
map <int, ll> My;

int main() {
	int N, i, j;
	int t1, t2;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &t1, &t2);
		Mp[pii(t1, t2)]++;
		Mx[t1]++;
		My[t2]++;
	}

	ll ans = 0;
	for (auto it : Mx) ans += it.second * (it.second - 1) / 2;
	for (auto it : My) ans += it.second * (it.second - 1) / 2;
	for (auto it : Mp) ans -= it.second * (it.second - 1) / 2;
	return !printf("%lld\n", ans);
}
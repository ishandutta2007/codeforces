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

int IT_MAX = 1024;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-12;

int N;
int in[305][2];
int gcd(int a, int b) {
	return (a == 0) ? b : gcd(b%a, a);
}
map <int, int> Mx;
int aa(int x) {
	if (x == 1) return 0;
	if (Mx.count(x)) return Mx[x];

	int rv = INF;
	for (int i = 1; i <= N; i++) {
		int g = gcd(in[i][0], x);
		if (g == x) continue;
		rv = min(rv, aa(g) + in[i][1]);
	}
	Mx[x] = rv;
	return rv;
}
int main() {
	int i;
	int tg = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i][0]);
		tg = gcd(tg, in[i][0]);
	}
	if (tg != 1) return !printf("-1\n");

	for (i = 1; i <= N; i++) scanf("%d", &in[i][1]);

	int ans = INF;
	for (i = 1; i <= N; i++) ans = min(ans, aa(in[i][0]) + in[i][1]);
	return !printf("%d\n", ans);
}
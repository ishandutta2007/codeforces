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
#include <string>
#include <time.h>
#include <cmath>
#include <vector>
#include <deque>
//#include <unordered_set>
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
const ll MOD = 10007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-10;

int in[105];
int r[105];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}
int c[105];

ll gcd(ll a, ll b) {
	return (a == 0) ? b : gcd(b%a, a);
}
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g*b;
}
int main() {
	int N, i, t;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) r[i] = i;

	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		in[t]++;
		r[root(i)] = root(t);
	}
	for (i = 1; i <= N; i++) if (!in[i]) return !printf("-1\n");

	for (i = 1; i <= N; i++) c[root(i)]++;

	ll ans = 1;
	for (i = 1; i <= N; i++) {
		if (c[i] == 0) continue;

		t = c[i];
		if (c[i] % 2 == 0) t /= 2;
		ans = lcm(ans, t);
	}
	return !printf("%lld\n", ans);
}
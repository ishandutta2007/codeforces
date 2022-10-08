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

int IT_MAX = 1 << 17;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll oin[14];

ll in[14];
int main() {
	ll ans = -1;
	int i, j;
	for (i = 0; i < 14; i++) scanf("%lld", &oin[i]);

	for (i = 0; i < 14; i++) {
		if (!oin[i]) continue;
		for (j = 0; j < 14; j++) in[j] = oin[j];
		in[i] = 0;

		ll t = oin[i];
		for (j = 1; j <= t % 14; j++) in[(i + j) % 14] += t / 14 + 1;
		for (; j <= 14; j++) in[(i + j) % 14] += t / 14;

		ll s = 0;
		for (j = 0; j < 14; j++) if (in[j] % 2 == 0) s += in[j];
		ans = max(ans, s);
	}
	return !printf("%lld\n", ans);
}
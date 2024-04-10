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

int IT_MAX = 1 << 18;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int main() {
	ll K, D, T;
	cin >> K >> D >> T;
	ll OD = D;
	D = (K / D)*D;
	if (D < K) D += OD;
	K = max(D - K, 0ll);
	db st = 0, en = 3e18, mi;
	for (int q = 1; q <= 500; q++) {
		mi = (st + en) / 2;

		db c = mi / D;
		ll x = (ll)c;
		c -= x;
		db ans = (D - K / 2.0)*x;
		if (c < (db)(D - K) / D) ans += c * D;
		else ans += (D - K) + (c - (db)(D - K) / D) * 0.5 * D;
		if (ans >= T) en = mi;
		else st = mi;
	}
	return !printf("%.20lf\n", mi);
}
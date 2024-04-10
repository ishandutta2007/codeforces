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
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll mul_inv(ll a, ll b) {
	ll t1 = a, t2 = b, t3;
	ll v1 = 1, v2 = 0, v3;
	while (t2 != 1) {
		ll x = t1 / t2;
		t3 = t1 - x*t2;
		v3 = v1 - x*v2;
		t1 = t2, t2 = t3;
		v1 = v2, v2 = v3;
	}
	return (v2 + b) % b;
}
ll mypow(ll a, ll b, ll p) {
	ll rv = 1;
	while (b) {
		if (b % 2) rv = (rv*a) % p;
		a = a*a%p;
		b /= 2;
	}
	return rv;
}
int main() {
	ll A, B, P, X;
	scanf("%lld %lld %lld %lld", &A, &B, &P, &X);

	ll ans = 0;
	for (ll i = 0; i < P - 1; i++) {
		if (X < i) continue;
		ll mx = (X - i) / (P - 1);

		ll x = B * mul_inv(mypow(A, i, P), P) % P;
		x = (i - x + P) % P;

		if (mx >= x) ans += (mx - x) / P + 1;
	}
	return !printf("%lld\n", ans);
}
//*/
#include <stdio.h>
#include <algorithm>
#include <assert.h>
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
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1034567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

ll mul_inv(ll a, ll b = MOD) {
	ll t1 = a, t2 = b, t3;
	ll v1 = 1, v2 = 0, v3;
	while (t2 != 1) {
		ll x = t1 / t2;
		t3 = t1 - x * t2;
		v3 = v1 - x * v2;
		t1 = t2, t2 = t3;
		v1 = v2, v2 = v3;
	}
	return v2;
}
ll gcd(ll a, ll b) {
	return (a == 0) ? b : gcd(b%a, a);
}
int main() {
	ll A, B, C, i;
	scanf("%lld %lld %lld", &A, &B, &C);
	C *= -1;

	bool c1 = false, c2 = false;
	if (A < 0) {
		c1 = true;
		A *= -1;
	}
	if (B < 0) {
		c2 = true;
		B *= -1;
	}

	if (C % gcd(A, B)) return !printf("-1\n");
	if (B == 0) {
		ll x = C / A, y = 0;
		if (c1) x *= -1;
		return !printf("%lld %lld\n", x, y);
	}

	ll g = gcd(A, B);
	A /= g, B /= g, C /= g;

	ll x = mul_inv(A, B) * C % B;
	ll y = (C - A*x) / B;
	if (c1) x *= -1;
	if (c2) y *= -1;
	return !printf("%lld %lld\n", x, y);
}
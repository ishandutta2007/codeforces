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
#pragma comment(linker, "/STACK:1048576")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db EPS = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

ll gcd(ll a, ll b) {
	return (a == 0) ? b : gcd(b%a, a);
}
ll aa(ll a, ll b) {
	if (b == 0) return 0;

	ll g = gcd(a, b);
	a = a / g, b = b / g;

	ll oa = a;
	ll mn = b;
	for (ll i = 2; i * i <= a; i++) {
		if (a % i) continue;
		mn = min(mn, b%i);
		while (a % i == 0) a /= i;
	}
	if (a != 1) mn = min(mn, b%a);
	return aa(oa, b - mn) + mn;
}

int main() {
	ll X, Y;
	scanf("%lld %lld", &X, &Y);
	return !printf("%lld\n", aa(X, Y));
}
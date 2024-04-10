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

int IT_MAX = 1 << 20;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-9;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll mypow(ll a, ll b) {
	ll rv = 1;
	while (b) {
		if (b % 2) rv = (rv*a) % MOD;
		a = a*a%MOD;
		b /= 2;
	}
	return rv;
}
int main() {
	ll N, M, K, i, j;
	scanf("%lld %lld %lld", &N, &M, &K);
	if (N > M) swap(N, M);
	if (K == 1) {
		ll n = (N-1) % (MOD - 1);
		ll m = (M-1) % (MOD - 1);
		printf("%lld\n", mypow(2, n*m));
	}
	else {
		if ((N + M) % 2) printf("0\n");
		else {
			ll n = (N-1) % (MOD - 1);
			ll m = (M-1) % (MOD - 1);
			printf("%lld\n", mypow(2, n*m));
		}
	}
	return 0;
}
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
//#include <unordered_map>
//#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18; // segment tree size
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f; // memset(dp, 0x3f, sizeof(dp)), 2*INF < INT_MAX
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10; // double EPS

ll gcd(ll a, ll b) {
	return (a == 0) ? b : gcd(b%a, a);
}
int main2() {
	ll P, Q, B;
	scanf("%lld %lld %lld", &P, &Q, &B);

	if (P == 0) return !printf("Finite\n");

	Q /= gcd(P, Q);
	if (Q == 1) return !printf("Finite\n");

	while(1) {
		B = gcd(B, Q);
		if (B == 1) return !printf("Infinite\n");
		Q /= B;
		if (Q == 1) return !printf("Finite\n");
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) main2();
	return 0;
}
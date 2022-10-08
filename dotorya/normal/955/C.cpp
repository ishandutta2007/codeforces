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

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;
ll MOD = 1000000007ll;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first
#define rep(i, n) for(int i=0;i<n;i++)
#define pb(x) push_back(x)

ll mymul(ll a, ll b) {
	if (b > LL_INF / a) return LL_INF;
	return min(LL_INF, a*b);
}
ll mypow(ll a, ll b) {
	ll rv = 1;
	while (b) {
		if (b % 2) rv = mymul(rv, a);
		a = mymul(a, a);
		b /= 2;
	}
	return rv;
}
ll mysqrt(ll a, ll b) {
	if (a == 0) return 0;

	db x = pow(a, 1.0 / b);
	ll v = (ll)x;
	if (v - x >= 1e-5 && v - x <= 1 - (1e-5)) return v;
	if (mypow(v, b) > a) v--;
	if (mypow(v + 1, b) <= a) v++;
	return v;
}

int pchk[70];
vector <int> Vp;

int DEBUG = 0;
int main() {
	int T, i, j;

	for (i = 2; i <= 62; i++) {
		int t = i;
		int v = -1;
		for (j = 2; t != 1; j++) {
			if (t % j) continue;

			if (t % (j*j) == 0) {
				v = 0;
				break;
			}
			t /= j;
			v *= -1;
		}
		pchk[i] = v;
	}

	if (!DEBUG) scanf("%d", &T);
	else T = 100000;
	while (T--) {
		ll L, R;
		if (!DEBUG) scanf("%lld %lld", &L, &R);
		else L = 50, R = 1000000000000000000ll;
		ll ans = 0;
		if (L == 1) {
			ans++;
			L++;
		}

		for (i = 2; i <= 15; i++) {
			if (!pchk[i]) continue;

			ll v1 = mysqrt(R, i);
			ll v2 = mysqrt(L - 1, i);
			v2 = max(v2, 20ll);
			if (v1 >= 21) ans += (v1 - v2) * pchk[i];
		}

		for (i = 2; i <= 20; i++) {
			ll v = i;
			for (j = 2; j <= 62; j++) {
				v = mymul(v, i);
				if (v > R) break;
				if (v >= L) ans += pchk[j];
			}
		}
		if (!DEBUG) printf("%lld\n", ans);
	}
	if (DEBUG) printf("%d\n", clock());
	return 0;
}
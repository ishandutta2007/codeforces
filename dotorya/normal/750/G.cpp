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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()

ll cnt1[65536];
ll popcount(ll x) {
	int rv = 0;
	while (x) {
		rv += cnt1[x & 65535];
		x /= 65536;
	}
	return rv;
}

map <pair<pll, pll>, ll> Mx;
ll getc(ll i, ll j, ll c, ll b) {
	if (i < j) swap(i, j);
	if (j == 0) {
		if (c >= (1ll << i)) return 0;
		if (popcount(c) == b) return 1;
		return 0;
	}

	auto u = mp(pll(i, j), pll(c, b));
	if (Mx.count(u)) return Mx[u];
	
	ll rv = 0;
	for (int x = 0; x <= 2; x++) {
		ll nc = c - x;
		if (b < x || nc < 0 || nc % 2 == 1) continue;

		ll v = getc(i - 1, j - 1, nc / 2, b - x);
		if (x == 1) rv += 2 * v;
		else rv += v;
	}
	return Mx[u] = rv;
}


int main() {
	ll S, i, j, k;
	for (i = 0; i < 65536; i++) {
		for (j = 0; j < 16; j++) if (i & (1ll << j)) cnt1[i]++;
	}

	scanf("%lld", &S);

	ll ans = 1; // Case 0
	
	// Case 1
	for (i = 1; i <= 50; i++) {
		ll x = (1ll << (i + 1)) - 1;
		ll a = S / x, b = S % x;
		if (a == 0) break;

		for (j = 0; j <= i; j++) {
			ll t = b + j;
			if (t % 2) continue;
			ans += getc(i, 0, t / 2, j);
		}
	}
	
	// Case 2
	for (i = 1; i <= 50; i++) {
		for (j = 1; j <= 50; j++) {
			ll x = (1ll << (i + 1)) + (1ll << (j + 1)) - 3;
			ll a = S / x, b = S % x;
			if (a == 0) break;
		
			ll tb = b - (1ll << j) + 1;
			if (tb < 0) continue;
			for (k = 0; k <= i + j - 2; k++) {
				ll nb = tb + k;
				if (nb % 2 == 0) ans += getc(i - 1, j - 1, nb / 2, k);
			}
		}
	}
	return !printf("%lld\n", ans);
}
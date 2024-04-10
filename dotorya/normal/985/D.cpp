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

ll mymul(ll a, ll b) {
	if (a > LL_INF / b) return LL_INF;
	return min(a*b, LL_INF);
}
int main() {
	ll N, H;
	scanf("%lld %lld", &N, &H);

	ll st = 1, en = 2.1e9, mi, rv = 0;
	while (st <= en) {
		mi = (st + en) / 2;
	
		ll v;
		if (mi <= H) v = mi * (mi + 1) / 2;
		else {
			if (mi % 2 != H % 2) { //H -> H+1 -> ... -> H+x -> H+x -> ... 1 : H+2x+1
				ll x = (mi - H - 1) / 2;
				v = min(N, H * (x + 1)) + min(N, x * (x + 1) / 2) + min(N, (H + x) * (H + x + 1) / 2);
			}
			else { //H -> ... -> H+x -> H+x-1 -> ... 1 : H+2x
				ll x = (mi - H) / 2;
				v = min(N, H * x) + min(N, x * (x - 1) / 2) + min(N, (H + x) * (H + x + 1) / 2);
			}
		}
		if (v >= N) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
	}
	return !printf("%lld\n", rv);
}
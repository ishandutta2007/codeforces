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
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first

int main() {
	ll N, Q;
	scanf("%lld %lld", &N, &Q);
	while (Q--) {
		ll t;
		scanf("%lld", &t);

		ll ans = 0;
		ll x = N, y = t;
		while (x >= 2) {
			if (x % 2 == 0) {
				if (y % 2 == 1) {
					ans += (y + 1) / 2;
					break;
				}
				ans += x / 2;
				x /= 2, y /= 2;
			}
			else {
				if (y % 2 == 1) {
					ans += (y + 1) / 2;
					break;
				}
				ans += (x + 1) / 2;
				x /= 2, y /= 2;
				y--;
				if (y == 0) y = x;
			}
		}
		if (x == 1) ans++;
		printf("%lld\n", ans);
	}
}
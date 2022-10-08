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
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
//#define Se second
#define Fi first

ll val[64];

int main() {
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		ll t1, t2, t3;
		scanf("%lld %lld", &t1, &t2);

		ll d = 1;
		while (1) {
			if ((1ll << d) > t2) break;
			d++;
		}

		if (t1 == 1) {
			scanf("%lld", &t3);
			val[d] = (val[d] + t3) % (1ll << (d-1));
		}
		else if (t1 == 2) {
			scanf("%lld", &t3);
			t3 %= (1ll << (d - 1));
			for (ll i = d; i <= 62; i++) {
				val[i] = (val[i] + t3) % (1ll << (i - 1));
				t3 *= 2;
			}
		}
		else {
			ll x = t2 - (1ll << (d - 1));
			x = x + val[d] + (1ll << (d - 1));
			x %= 1ll << (d - 1);

			printf("%lld ", t2);
			for (ll i = d - 1; i >= 1; i--) {
				x /= 2;

				ll tx = x - val[i] + (1ll << (i - 1));
				tx %= 1ll << (i - 1);
				printf("%lld ", tx + (1ll << (i - 1)));
			}
			printf("\n");
		}
	}
	return 0;
}
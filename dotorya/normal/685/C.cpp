//*
#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1024;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

ll in[100050][3];

inline ll div2(ll x) {
	if (x < 0) return (x - 1) / 2;
	else return x / 2;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, i;
		
		ll t1, t2, t3;
		
		scanf("%d", &N);
		for (i = 1; i <= N; i++) scanf("%lld %lld %lld", &in[i][0], &in[i][1], &in[i][2]);

		ll st = 0, en = LL_INF, mi, rv = LL_INF;
		ll ans1 = 0, ans2 = 0, ans3 = 0;
		while (st <= en) {
			mi = (st + en) / 2;

			ll a1 = -LL_INF, a2 = LL_INF, b1 = -LL_INF, b2 = LL_INF, c1 = -LL_INF, c2 = LL_INF, d1 = -LL_INF, d2 = LL_INF;
			for (i = 1; i <= N; i++) {
				a1 = max(a1, -mi + in[i][0] + in[i][1] + in[i][2]);
				a2 = min(a2, mi + in[i][0] + in[i][1] + in[i][2]);
				b1 = max(b1, -mi + in[i][0] + in[i][1] - in[i][2]);
				b2 = min(b2, mi + in[i][0] + in[i][1] - in[i][2]);
				c1 = max(c1, -mi + in[i][0] - in[i][1] + in[i][2]);
				c2 = min(c2, mi + in[i][0] - in[i][1] + in[i][2]);
				d1 = max(d1, -mi + in[i][0] - in[i][1] - in[i][2]);
				d2 = min(d2, mi + in[i][0] - in[i][1] - in[i][2]);
			}
			if (a1 > a2 || b1 > b2 || c1 > c2 || d1 > d2) {
				st = mi + 1;
				continue;
			}

			ll xmn = max(div2(b1 + c1 + 1), div2(a1 + d1 + 1));
			ll xmx = min(div2(b2 + c2), div2(a2 + d2));

			ll x, y, z;
			for (x = xmn; x <= xmx; x++) {
				for (y = max(a1 - x, x - d2); y <= min(a2 - x, x - d1); y++) {
					for (z = max(b1 - x, x - c2); z <= min(b2 - x, x - c1); z++) {
						if ((y - z) % 2 == 0) break;
					}
					if (z <= min(b2 - x, x - c1)) break;
				}
				if (y <= min(a2 - x, x - d1)) break;
			}
			if (x <= xmx) {
				ans1 = x;
				ans2 = div2(y) + div2(z);
				if (y % 2) ans2++;
				ans3 = div2(y) - div2(z);
				en = mi - 1;
			}
			else st = mi + 1;
		}
		printf("%lld %lld %lld\n", ans1, ans2, ans3);
	}
	return 0;
}
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
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll in[500050];
ll sum[500050];
int main() {
	int Q;
	scanf("%d", &Q);

	db ans = 0;

	int c = 0;
	while (Q--) {
		int t1, t2;
		scanf("%d", &t1);
		if (t1 == 2) {
			printf("%.20lf\n", ans);
			continue;
		}
		if (t1 == 1) {
			scanf("%d", &t2);
			c++;
			in[c] = t2;
			sum[c] = sum[c - 1] + in[c];

			if (c == 1) continue;

			int st = 1, en = c - 2, mi, rv = 0;
			while (st <= en) {
				mi = (st + en) / 2;

				ll t1 = sum[mi] + in[c];
				ll t2 = mi + 1;
				ll t3 = sum[mi + 1] + in[c];
				ll t4 = mi + 2;

				int v = 0;
				if (t1 / t2 != t3 / t4) {
					if (t1 / t2 > t3 / t4) v = 1;
					else v = -1;
				}
				else {
					t1 %= t2, t3 %= t4;
					if (t1*t4 > t2 * t3) v = 1;
					else v = -1;
				}
				if (v == 1) {
					rv = mi;
					st = mi + 1;
				}
				else en = mi - 1;
			}

			rv++;
			ans = max(ans, in[c] - (db)(in[c] + sum[rv]) / (rv + 1));
		}
	}
	return 0;
}
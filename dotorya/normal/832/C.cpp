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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

ll in[100050][3];
ll del[2][1000050];
int main() {
	int N, S, i, j;
	scanf("%d %d", &N, &S);
	for (i = 1; i <= N; i++) {
		scanf("%lld %lld %lld", &in[i][0], &in[i][1], &in[i][2]);
		in[i][2]--;
	}

	db st = 0, en = INF, mi;
	for (int q = 1; q <= 80; q++) {
		mi = (st + en) / 2;
		
		memset(del, 0, sizeof(del));
		for (i = 1; i <= N; i++) {
			ll x = in[i][0], v = in[i][1], n = in[i][2];
			if (n == 1) x = 1000000 - x;

			ll tsp, tep;
				
			if ((db)x / v <= mi) {
				del[n][0]++;
				continue;
			}	
			if ((db)x / (v + S) > mi) continue;

			db a = (mi * (S - v)*(S + v) + (db)x * v) / S;
			tsp = x, tep = (ll)a;
			if (n == 1) {
				ll tsp2 = 1000000 - tep;
				ll tep2 = 1000000 - tsp;
				tsp = tsp2, tep = tep2;
			}
			tsp = max(0ll, tsp);
			tep = min(1000000ll, tep);
			if (tsp <= tep) {
				del[n][tsp]++;
				del[n][tep + 1]--;
			}
		}
		for (j = 0; j <= 1000000; j++) {
			if (j) {
				del[0][j] += del[0][j - 1];
				del[1][j] += del[1][j - 1];
			}
			if (del[0][j] && del[1][j]) break;
		}
		if (j <= 1000000) en = mi;
		else st = mi;
	}
	return !printf("%.20lf\n", mi);
}
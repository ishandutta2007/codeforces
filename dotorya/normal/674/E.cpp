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
//#include <unordered_set>
//#include <unordered_map>

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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-13;

ldb dp[500050][51];
int par[500050];
int main() {
	int Q, n = 1, i;
	scanf("%d", &Q);
	while (Q--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		if (t1 == 1) {
			int x = ++n;
			par[x] = t2;

			ldb v1 = 0, v2 = 1;
			ldb tv1, tv2;
			dp[x][0] = 1;
			for (i = 1; x != 1 && i <= 50; i++) {
				x = par[x];
				ldb u = 1 - dp[x][i];

				tv1 = dp[x][i];
				u *= (1 - v2 / 2) / (1 - v1 / 2);
				dp[x][i] = 1 - u;
				tv2 = dp[x][i];

				v1 = tv1, v2 = tv2;
			}
		}
		else {
			ldb ans = 0;
			for (i = 1; i <= 50; i++) ans += dp[t2][i];
			printf("%.20lf\n", (db)ans);
		}
	}
	return 0;
}
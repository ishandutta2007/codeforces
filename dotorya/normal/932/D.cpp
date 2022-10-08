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

int IT_MAX = 1 << 19;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int par[400050][20];
ll sum[400050][20];
ll val[400050];
int main() {
	int Q, i, j;
	scanf("%d", &Q);
	
	val[0] = LL_INF;
	for (i = 0; i < 20; i++) par[1][i] = 0;
	for (i = 0; i < 20; i++) sum[0][i] = LL_INF;
	for (i = 1; i < 20; i++) sum[1][i] = LL_INF;
	ll lst = 0;
	int nc = 1;
	while (Q--) {
		ll t1, t2, t3;
		scanf("%lld %lld %lld", &t1, &t2, &t3);
		t2 ^= lst, t3 ^= lst;

		if (t1 == 1) {
			nc++;
			val[nc] = t3;

			if (val[t2] >= val[nc]) par[nc][0] = t2;
			else {
				for (i = 19; i >= 0; i--) {
					int nt = par[t2][i];
					if (val[nt] < val[nc]) t2 = nt;
				}
				par[nc][0] = par[t2][0];
			}
			for (i = 1; i <= 19; i++) par[nc][i] = par[par[nc][i - 1]][i - 1];
			sum[nc][0] = val[nc];
			for (i = 1; i <= 19; i++) sum[nc][i] = min(LL_INF, sum[nc][i - 1] + sum[par[nc][i - 1]][i - 1]);
		}
		else {
			int ans = 0;
			for (i = 19; i >= 0; i--) {
				if (sum[t2][i] <= t3) {
					t3 -= sum[t2][i];
					ans += 1 << i;
					t2 = par[t2][i];
				}
			}
			printf("%d\n", ans);
			lst = ans;
		}
	}
	return 0;
}
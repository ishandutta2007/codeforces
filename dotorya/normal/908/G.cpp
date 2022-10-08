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
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll dp1[11][705][705];
ll sum1[11][705][705];

char u[705];
int in[705];
ll po10[705];
int main() {
	ll ans = 0, i, j, k, l;
	scanf("%s", u);
	if (strlen(u) == 701) {
		ans++;
		for (i = 699; i >= 0; i--) in[i] = 9;
	}
	else {
		int L = strlen(u);
		for (i = L - 1; i >= 0; i--) in[i] = u[L-1-i] - '0';
	}

	for (i = 1; i <= 9; i++) {
		dp1[i][0][0] = 1;
		for (j = 1; j <= 700; j++) {
			for (k = 0; k <= 700; k++) {
				dp1[i][j][k] = dp1[i][j - 1][k] * i % MOD;
				if (k) dp1[i][j][k] += dp1[i][j - 1][k - 1] * (10 - i) % MOD;
				dp1[i][j][k] %= MOD;
			}
		}
		for (j = 0; j <= 700; j++) {
			sum1[i][j][700] = dp1[i][j][700];
			for (k = 699; k >= 0; k--) sum1[i][j][k] = (sum1[i][j][k + 1] + dp1[i][j][k]) % MOD;
		}
	}

	po10[0] = 1;
	for (i = 1; i <= 700; i++) po10[i] = po10[i - 1] * 10 % MOD;
	for (i = 0; i <= 699; i++) {
		for (j = 1; j <= 9; j++) {
			int c = 0;
			for (k = 699; k >= 0; k--) {
				for (l = 0; l <= in[k]; l++) {
					if (k != 0 && l == in[k]) break;
					int tc = c;
					if (l >= j) tc++;
					ll x = max(0ll, i + 1 - tc);
					ans = (ans + sum1[j][k][x] * po10[i]) % MOD;
				}
				if (in[k] >= j) c++;
			}
		}
	}
	return !printf("%lld\n", ans);
}
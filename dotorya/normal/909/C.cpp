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

ll dp[5050][2];
ll tdp[5050][2];
int sum[5050];
int main() {
	int N, i, j;
	scanf("%d", &N);

	dp[0][1] = 1;
	for (i = 1; i <= N; i++) {
		sum[0] = dp[0][1];
		for (j = 1; j <= 5000; j++) sum[j] = (sum[j - 1] + dp[j][1]) % MOD;

		char c[2];
		scanf("%s", c);
		memset(tdp, 0, sizeof(tdp));
		if (c[0] == 's') {
			for (j = 0; j <= 5000; j++) {
				tdp[j][1] = dp[j][0] + sum[5000];
				if (j) tdp[j][1] -= sum[j - 1];
			}
		}
		else {
			for (j = 1; j <= 5000; j++) {
				tdp[j][0] = dp[j - 1][0] + sum[5000];
				if (j != 1) tdp[j][0] -= sum[j - 2];
			}
		}
		for (j = 0; j <= 5000; j++) dp[j][0] = (tdp[j][0] + 3 * MOD) % MOD, dp[j][1] = (tdp[j][1] + 3 * MOD) % MOD;
	}

	ll ans = 0;
	for (i = 0; i <= 5000; i++) ans += dp[i][1];
	return !printf("%lld\n", ans % MOD);
}
#include <algorithm>
#include <assert.h>
#include <bitset>
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
#include <string>
#include <time.h>
#include <cmath>
#include <vector>
#include <deque>
//#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
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

int IT_MAX = 1 << 20;
const ll MOD = 1234567891;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-6;

bitset<505> dp[62][2][505];

bitset<505> u[505];
bitset<505> u2;
bool chk[505];
bool tchk[505];
int main() {
	int N, M, i, j, k, l, t1, t2, t3;
	scanf("%d %d", &N, &M);
	//N = 500, M = 0;
	while (M--) {
		scanf("%d %d %d", &t1, &t2, &t3);
		t1--, t2--;
		dp[0][t3][t1][t2] = 1;
	}
	//int st = clock();
	for (i = 1; i <= 61; i++) {
		for (j = 0; j < N; j++) for (k = 0; k < N; k++) u[j][k] = dp[i - 1][1][k][j];
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				u2 = dp[i - 1][0][j] & u[k];
				dp[i][0][j][k] = u2.any();
			}
		}
		
		for (j = 0; j < N; j++) for (k = 0; k < N; k++) u[j][k] = dp[i - 1][0][k][j];
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				u2 = dp[i - 1][1][j] & u[k];
				dp[i][1][j][k] = u2.any();
			}
		}
		//printf("%d\n", clock() - st);
	}

	chk[0] = 1;
	ll ans = 0;
	int r = 0;
	for (i = 61; i >= 0; i--) {
		for (j = 0; j < N; j++) tchk[j] = false;
		for (j = 0; j < N; j++) {
			if (!chk[j]) continue;
			for (k = 0; k < N; k++) if (dp[i][r][j][k]) tchk[k] = true;
		}
		for (j = 0; j < N; j++) if (tchk[j]) break;
		if (j >= N) continue;
		ans += 1ll << (ll)i;
		r ^= 1;
		for (j = 0; j < N; j++) chk[j] = tchk[j];
	}
	if (ans > 1000000000000000000ll) ans = -1;
	return !printf("%lld\n", ans);
}
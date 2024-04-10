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
#include <string>
#include <time.h>
#include <cmath>
#include <vector>
#include <deque>
//#include <unordered_set>
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

int IT_MAX = 1 << 17;
const ll MOD = 10007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-10;



int r[1050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}

int inw[1050];
int inb[1050];
ll dp[1050][1050];
int main() {
	int N, M, W, i, j, k, t1, t2;
	scanf("%d %d %d", &N, &M, &W);
	for (i = 1; i <= N; i++) scanf("%d", inw + i);
	for (i = 1; i <= N; i++) scanf("%d", inb + i);
	
	for (i = 1; i <= N; i++) r[i] = i;
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &t1, &t2);
		r[root(t1)] = root(t2);
	}

	int c = 0;
	for (i = 0; i <= N; i++) for (j = 0; j <= W; j++) dp[i][j] = -INF;
	dp[0][0] = 0;

	for (i = 1; i <= N; i++) {
		if (r[i] != i) continue;
		ll ws = 0, bs = 0;
		
		c++;
		for (j = 0; j <= W; j++) dp[c][j] = dp[c - 1][j];
		for (j = 1; j <= N; j++) {
			if (root(j) != i) continue;
			for (k = W; k >= inw[j]; k--) dp[c][k] = max(dp[c][k], dp[c - 1][k - inw[j]] + inb[j]);
			ws += inw[j], bs += inb[j];
		}
		for (j = W; j >= ws; j--) dp[c][j] = max(dp[c][j], dp[c - 1][j - ws] + bs);
	}

	ll ans = -INF;
	for (i = 0; i <= W; i++) ans = max(ans, dp[c][i]);
	return !printf("%lld\n", ans);
}
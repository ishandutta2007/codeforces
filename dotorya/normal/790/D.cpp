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

int IT_MAX = 1 << 17;
const ll MOD = 999983;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-12;

ll in[3][300050];
ll prv[3][300050];

map <pii, int> Mx;
int dp[300050];
int getc(int a, int b) {
	if (a < 0 || b < 0) return -INF;
	if (a == b) return dp[a];
	if (Mx.count(pii(a, b))) return Mx[pii(a, b)];

	int rv = dp[min(a, b)];
	if (a > b) rv = max(rv, getc(prv[0][a], b) + 1);
	if (a < b) rv = max(rv, getc(a, prv[1][b]) + 1);
	return Mx[pii(a,b)] = rv;
}
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 0; i < 2; i++) for (j = 1; j <= N; j++) scanf("%lld", &in[i][j]);
	for (i = 1; i <= N; i++) in[2][i] = in[0][i] + in[1][i];
	for (i = 0; i < 3; i++) {
		map <ll, int> Mu;
		Mu[0] = 0;
		ll s = 0;
		for (j = 1; j <= N; j++) {
			if (!Mu.count(s + in[i][j])) prv[i][j] = -1;
			else prv[i][j] = Mu[s + in[i][j]];
			s += in[i][j];
			Mu[s] = j;
		}
		prv[i][0] = -1;
		for (j = 1; j <= N; j++) prv[i][j] = max(prv[i][j], prv[i][j - 1]);
		Mu.clear();
	}
	for (i = 1; i <= N; i++) {
		dp[i] = dp[i - 1];
		if (prv[2][i] != -1) dp[i] = max(dp[i], dp[prv[2][i]] + 1);
		dp[i] = max(dp[i], getc(prv[0][i], i) + 1);
		dp[i] = max(dp[i], getc(i, prv[1][i]) + 1);
	}
	return !printf("%d\n", dp[N]);
}
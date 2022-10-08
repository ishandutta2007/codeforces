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

int IT_MAX = 262144;
const int MOD = 1000003;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-11;

string in[100050];
string rin[100050];
ll C[100050];
ll dp[100050][2];
char u[100050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld", &C[i]);
	for (i = 1; i <= N; i++) {
		scanf("%s", u);
		int L = strlen(u);
		in[i] = string(u);
		for (j = 0; j < L / 2; j++) swap(u[j], u[L - 1 - j]);
		rin[i] = string(u);
	}
	in[0] = rin[0] = string("");

	for (i = 0; i <= N; i++) for (j = 0; j < 2; j++) dp[i][j] = LL_INF;
	dp[0][0] = 0;
	for (i = 1; i <= N; i++) {
		if (in[i - 1] <= in[i]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
		if (rin[i - 1] <= in[i]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		if (in[i - 1] <= rin[i]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + C[i]);
		if (rin[i - 1] <= rin[i]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + C[i]);
	}
	
	ll ans = min(dp[N][0], dp[N][1]);
	if (ans == LL_INF) ans = -1;
	return !printf("%lld\n", ans);
}
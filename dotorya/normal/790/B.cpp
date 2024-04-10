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

pll operator + (pll a, pll b) {
	return pll(a.first + b.first, a.second + b.second);
}
pll operator - (pll a, pll b) {
	return pll(a.first - b.first, a.second - b.second);
}
int K;
vector <int> conn[200050];
vector <int> son[200050];

bool dchk[200050];
pll dp[200050][5];
ll ans = 0;
void DFS1(int n) {
	dchk[n] = true;
	dp[n][K-1] = pll(0, 1);
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		son[n].push_back(it);
		DFS1(it);
		int i;
		for (i = 0; i + 1 < K; i++) dp[n][i + 1] = dp[n][i+1] + dp[it][i];
		dp[n][0] = dp[n][0] + dp[it][K - 1] + pll(dp[it][K - 1].second, 0);
	}
}

pll ucur[200050][5];
pll cur[5];

pll t1[5];
pll t2[5];
pll t3[5];
void DFS2(int n) {
	int i;
	for (i = 0; i < K; i++) ans += cur[i].first;
	for (i = 0; i < K; i++) ucur[n][i] = cur[i];
	for (auto it : son[n]) {
		for (i = 1; i < K; i++) t1[i] = dp[it][i-1];
		t1[0] = pll(dp[it][K - 1].first + dp[it][K - 1].second, dp[it][K - 1].second);

		for (i = 0; i < K; i++) t2[i] = cur[i] - t1[i];
		
		for (i = 0; i < K; i++) cur[i] = dp[it][i];
		for (i = 0; i < K - 1; i++) cur[i + 1] = cur[i + 1] + t2[i];
		cur[0] = cur[0] + pll(t2[K - 1].first + t2[K - 1].second, t2[K - 1].second);
		DFS2(it);
		for (i = 0; i < K; i++) cur[i] = ucur[n][i];
	}
}
int main() {
	int N, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	DFS1(1);
	for (i = 1; i <= N; i++) dchk[i] = false;

	for (i = 0; i < K; i++) cur[i] = dp[1][i];
	DFS2(1);
	return !printf("%lld\n", ans / 2);
}
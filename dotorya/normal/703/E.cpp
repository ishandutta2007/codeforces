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

int IT_MAX = 1 << 21;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-12;

ll K;
ll gcd(ll a, ll b) {
	return (a == 0) ? b : gcd(b%a, a);
}
map <ll, int> Mx;
ll Mv[100050];

ll in[100050];
ll in2[100050];
pll dp[1002][10050];
int rev[1002][10050];

int Mx1[2000050];
int Mx2[2000050];
inline int ch(ll x) {
	if (x <= 1000000) return Mx1[x];
	else return Mx2[K / x];
}
int main() {
	int N, i, j;
	scanf("%d %lld", &N, &K);
	if (K == 1) {
		int mn = 1;
		for (i = 1; i <= N; i++) {
			scanf("%lld", &in[i]);
			if (in[mn] > in[i]) mn = i;
		}
		return !printf("%d\n%d\n", 1, mn);
	}
	for (i = 1; i <= N; i++) {
		scanf("%lld", &in[i]);
		in2[i] = gcd(in[i], K);
	}

	for (i = 1; (ll)i*i <= K; i++) {
		if (K%i) continue;
		Mx[i] = 0;
		Mx[K / i] = 0;
	}
	assert(Mx.size() <= 10000);
	
	i = 0;
	for (auto &it : Mx) {
		it.second = ++i;
		Mv[i] = it.first;
		if (it.first <= 1000000) Mx1[it.first] = i;
		else Mx2[K / it.first] = i;
	}

	int M = Mx.size();
	for (i = 0; i <= N; i++) for (j = 0; j <= M; j++) dp[i][j] = pll(LL_INF, LL_INF);
	dp[0][1] = pll(0,0);
	for (i = 0; i < N; i++) {
		for (j = 1; j <= M; j++) {
			if (dp[i + 1][j] > dp[i][j]) {
				dp[i + 1][j] = dp[i][j];
				rev[i + 1][j] = 0;
			}
			ll v = Mv[j] * gcd(Mv[M+1-j], in2[i + 1]);
			v = ch(v);
			if (dp[i + 1][v] > pll(dp[i][j].first + 1, dp[i][j].second + in[i+1])) {
				dp[i + 1][v] = pll(dp[i][j].first + 1, dp[i][j].second + in[i+1]);
				rev[i + 1][v] = j;
			}
		}
	}

	if (dp[N][M] == pll(LL_INF, LL_INF)) return !printf("-1\n");

	printf("%lld\n", dp[N][M].first);
	for (i = N; i >= 1; i--) {
		if (rev[i][M] == 0) continue;
		printf("%d ", i);
		M = rev[i][M];
	}
	return !printf("\n");
}
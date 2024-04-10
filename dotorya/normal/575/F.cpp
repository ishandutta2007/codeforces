//*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <functional>
#define MOD 1000000007
#define MAX ((1<<30)-1)
#define MAX2 ((1ll<<62)-1)
#define mp make_pair
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const ll LL_INF = MAX2;

map <int, int> M;
ll dp[2][10050];

pii in[5050];
int pos[10050];

int main() {
	int N, X, i, j;
	scanf("%d %d", &N, &X);
	M[X] = 0;
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &in[i].first, &in[i].second);
		M[in[i].first] = 0;
		M[in[i].second] = 0;
	}

	int c = 0;
	for (map <int, int>::iterator it = M.begin(); it != M.end(); it++) {
		it->second = ++c;
		pos[c] = it->first;
	}

	X = M[X];
	for (i = 1; i <= N; i++) {
		in[i].first = M[in[i].first];
		in[i].second = M[in[i].second];
	}

	for (i = 1; i <= c; i++) dp[0][i] = abs(pos[i] - pos[X]);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= c; j++) dp[i & 1][j] = LL_INF;
		ll mn = LL_INF;
		for (j = 1; j <= c; j++) {
			mn = min(dp[1 - (i & 1)][j] - pos[j], mn);
			dp[i & 1][j] = min(dp[i & 1][j], mn + pos[j]);
		}

		mn = LL_INF;
		for (j = c; j >= 1; j--) {
			mn = min(dp[1 - (i & 1)][j] + pos[j], mn);
			dp[i & 1][j] = min(dp[i & 1][j], mn - pos[j]);
		}

		for (j = 1; j <= c; j++) {
			if (pos[j] < pos[in[i].first]) dp[i & 1][j] += pos[in[i].first] - pos[j];
			if (pos[in[i].second] < pos[j]) dp[i & 1][j] += pos[j] - pos[in[i].second];
		}

	}

	ll ans = LL_INF;
	for (i = 1; i <= c; i++) ans = min(ans, dp[N & 1][i]);
	printf("%I64d", ans);
	return 0;
}

//*/
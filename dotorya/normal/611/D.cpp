//*
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
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>


#define pow10 pasiodfiopsdjviozjxciovjxcviozj
#define pow2 qpowdskopjkcoizxnzoicn

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <char, int> pci;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef pair <ldb, int> pdi;
typedef pair <ldb, ll> pdl;

int IT_MAX;
const ll MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

int sa[5050][5050];
int dp[5050][5050];
int sum[5050][5050];
int v[5050];
char in[5050];

void getSA(int L) {
	int i, j, k;
	for (i = 0; i < L; i++) v[i] = i;

	for (i = 1; i <= L; i++) {
		sort(v, v + L, [&i](const int &a, const int &b) { return (sa[i - 1][a] != sa[i - 1][b]) ? sa[i - 1][a] < sa[i - 1][b] : in[a+i-1] < in[b+i-1]; });

		for (j = 0, k = -1; j < L; j++) {
			if (j == 0 || sa[i - 1][v[j]] != sa[i - 1][v[j - 1]] || in[v[j]+i-1] != in[v[j - 1]+i-1]) sa[i][v[j]] = ++k;
			else sa[i][v[j]] = k;
		}
	}
}

int mod(int x) {
	x %= MOD;
	x += MOD;
	x %= MOD;
	return x;
}

int main() {
	int L, i, j;
	int st = clock();
	scanf("%d %s", &L, in);
	getSA(L);

	dp[0][0] = 1;
	for (i = 1; i < L; i++) {
		sum[i - 1][0] = dp[i - 1][0];
		for (j = 1; j <= L; j++) sum[i - 1][j] = (sum[i - 1][j - 1] + dp[i-1][j]) % MOD;

		dp[i][0] = 1;
		for (j = 1; j <= i; j++) {
			if (in[j] == '0') continue;
			int d = i - j + 1;
			int p = max(0, j - d + 1);
			dp[i][j] = mod(sum[j - 1][j - 1] - ((p == 0)? 0 : sum[j - 1][p-1]));
			if (p != 0 && sa[d][j] > sa[d][p-1]) dp[i][j] = (dp[i][j] + dp[j - 1][p-1]) % MOD;
		}
	}

	int ans = 0;
	for (i = 0; i < L; i++) ans = (ans + dp[L - 1][i]) % MOD;
	printf("%d\n", ans);
//	printf("%d\n", clock() - st);
	return 0;
}
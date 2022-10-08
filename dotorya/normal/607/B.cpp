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

int dp[505][505];
int rdp[505][505];
int in[505];
int main() {
	int i, j, k, N;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	
	for (i = 1; i <= N; i++) dp[i][i] = rdp[i][i] = 1;
	for (i = N - 1; i >= 1; i--) {
		for (j = i + 1; j <= N; j++) {
			if (in[i] == in[j]) {
				if (j - i == 1) dp[i][j] = 1;
				else dp[i][j] = dp[i + 1][j - 1];
			}
			else dp[i][j] = INF;
			for (k = i; k < j; k++) if (dp[i][j] > dp[i][k] + rdp[j][k + 1]) dp[i][j] = dp[i][k] + rdp[j][k + 1];
			rdp[j][i] = dp[i][j];
		}
	}
	printf("%d\n", dp[1][N]);
	return 0;
}
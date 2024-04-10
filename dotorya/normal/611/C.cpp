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

char in[505][505];
int u1[505][505];
int u2[505][505];
int sum1[505][505];
int sum2[505][505];

int main() {
	int H, W, i, j, k;

	scanf("%d %d", &H, &W);
	for (i = 1; i <= H; i++) scanf("%s", &in[i][1]);

	for (i = 1; i <= H; i++) for (j = 1; j < W; j++) if (in[i][j] == '.' && in[i][j + 1] == '.') u1[i][j] = 1;
	for (i = 1; i <= H; i++) for (j = 1; j <= W; j++) sum1[i][j] = sum1[i - 1][j] + sum1[i][j - 1] - sum1[i - 1][j - 1] + u1[i][j];
	for (i = 1; i < H; i++) for (j = 1; j <= W; j++) if (in[i][j] == '.' && in[i + 1][j] == '.') u2[i][j] = 1;
	for (i = 1; i <= H; i++) for (j = 1; j <= W; j++) sum2[i][j] = sum2[i - 1][j] + sum2[i][j - 1] - sum2[i - 1][j - 1] + u2[i][j];

	scanf("%d", &k);
	while (k--) {
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		
		int ans = 0;
		ans += sum1[r2][c2 - 1] - sum1[r1 - 1][c2 - 1] - sum1[r2][c1 - 1] + sum1[r1 - 1][c1 - 1];
		ans += sum2[r2 - 1][c2] - sum2[r1 - 1][c2] - sum2[r2 - 1][c1 - 1] + sum2[r1 - 1][c1 - 1];
		printf("%d\n", ans);
	}
	return 0;
}
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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

ldb dp[1100000];
ldb Pu[21];
ldb P[21];
int ch[21];

ldb ans[21];
int main() {
	int tN, N, K, i, j;
	scanf("%d %d", &tN, &K);
	for (i = 0, j = 0; i < tN; i++) {
		cin >> Pu[i];
		if (Pu[i] > ERR) {
			P[j] = Pu[i];
			ch[i] = j++;
		}
		else ch[i] = -1;
	}

	N = j;
	K = min(N, K);

	dp[0] = 1;
	for (i = 0; i < (1 << N) - 1; i++) {
		ldb s = 0;
		for (j = 0; j < N; j++) if (!(i & (1 << j))) s += P[j];
		for (j = 0; j < N; j++) if (!(i & (1 << j))) dp[i | (1 << j)] += dp[i] * P[j] / s;
	}

	for (i = 0; i < (1 << N); i++) {
		int c = 0;
		for (j = 0; j < N; j++) if (i&(1 << j)) c++;
		if (c == K) {
			for (j = 0; j < N; j++) if (i&(1 << j)) ans[j] += dp[i];
		}
	}
	for (i = 0; i < tN; i++) {
		if (ch[i] == -1) printf("0.00 ");
		else printf("%.20lf ", (db)ans[ch[i]]);
	}
	return !printf("\n");
}
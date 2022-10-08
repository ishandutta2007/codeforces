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
const ll MOD = 987654321;
const int INF = 1034567891;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-12;

int ch[6][6];
int dp[10][6];
int main() {
	int N, Q, i, j, k;
	char c1[5], c2[5];
	scanf("%d %d", &N, &Q);
	for (i = 0; i < 6; i++) for (j = 0; j < 6; j++) ch[i][j] = -1;
	while (Q--) {
		scanf("%s %s", c1, c2);
		ch[c1[0] - 'a'][c1[1] - 'a'] = c2[0] - 'a';
	}

	for (i = 0; i < 6; i++) dp[1][i] = 1;
	for (i = 1; i < N; i++) {
		for (j = 0; j < 6; j++) {
			for (k = 0; k < 6; k++) {
				if (ch[j][k] == -1) continue;
				dp[i + 1][ch[j][k]] += dp[i][j];
			}
		}
	}

	printf("%d\n", dp[N][0]);
	return 0;
}
//*/
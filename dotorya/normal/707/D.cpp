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
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-11;

int cnt[101200];
bool val[101200][1050];
int pos[101200][1050];
int main() {
	int N, M, Q, i, j, t1, t2, t3;
	scanf("%d %d %d", &N, &M, &Q);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) val[i][j] = 0;
		pos[0][i] = i;
		
	}

	int c = N;
	for (i = 1; i <= Q; i++) {
		for (j = 1; j <= N; j++) pos[i][j] = pos[i - 1][j];
		scanf("%d", &t1);
		if (t1 == 1) {
			scanf("%d %d", &t2, &t3);
			c++;
			for (j = 1; j <= M; j++) val[c][j] = val[pos[i - 1][t2]][j];
			val[c][t3] = 1;

			pos[i][t2] = c;

			for (j = 1; j <= M; j++) if (val[c][j]) cnt[c]++;
		}
		else if (t1 == 2) {
			scanf("%d %d", &t2, &t3);
			c++;
			for (j = 1; j <= M; j++) val[c][j] = val[pos[i - 1][t2]][j];
			val[c][t3] = 0;

			pos[i][t2] = c;

			for (j = 1; j <= M; j++) if (val[c][j]) cnt[c]++;
		}
		else if (t1 == 3) {
			scanf("%d", &t2);
			c++;
			for (j = 1; j <= M; j++) val[c][j] = !val[pos[i - 1][t2]][j];

			pos[i][t2] = c;

			for (j = 1; j <= M; j++) if (val[c][j]) cnt[c]++;
		}
		else if (t1 == 4) {
			scanf("%d", &t2);
			for (j = 1; j <= N; j++) pos[i][j] = pos[t2][j];
		}

		int ans = 0;
		for (j = 1; j <= N; j++) ans += cnt[pos[i][j]];
		printf("%d\n", ans);
	}
	return 0;
}
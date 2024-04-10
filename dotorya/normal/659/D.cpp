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
const int INF = 1034567890;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int dir(int sx, int sy, int ex, int ey) {
	if (sx == ex) {
		if (sy < ey) return 0;
		else return 2;
	}
	else {
		if (sx < ex) return 1;
		else return 3;
	}
}

int in[100050][2];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d %d", &in[i][0], &in[i][1]);
	in[N + 1][0] = in[1][0], in[N + 1][1] = in[1][1];

	int t = 1;
	if (dir(in[1][0], in[1][1], in[2][0], in[2][1])) t = 3;

	int ans = 0;
	for (i = 1; i < N; i++) {
		int d1 = dir(in[i][0], in[i][1], in[i + 1][0], in[i + 1][1]);
		int d2 = dir(in[i + 1][0], in[i + 1][1], in[i + 2][0], in[i + 2][1]);

		int d = (d2 - d1 + 4) % 4;
		if (d != t) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
//*/
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

int IT_MAX = 1<<21;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-10;

int N, M;
char in1[1000050];
char in2[1000050];

int sum[1000050][9];

int nxt(int p, char c) {
	while (p < M) {
		if (in2[p] == c) break;
		p++;
	}
	return p;
}
int ch(char c) {
	if (c == 'R') return 0;
	if (c == 'G') return 1;
	return 2;
}
int main() {
	scanf("%s %s", in1 + 1, in2 + 1);
	N = strlen(in1 + 1), M = strlen(in2 + 1);

	int i, j, st = 1, en = 1;
	for (i = 1; i <= M; i++) {
		for (j = 0; j < 9; j++) sum[i][j] = sum[i - 1][j];
		if (i != 1) sum[i][ch(in2[i - 1]) * 3 + ch(in2[i])]++;
	}
	ll ans = 0;
	for (i = 1; i <= N; i++) {
		int t = nxt(en, in1[i]);
		ans += t - st + 1;
		if (i >= 2 && in1[i-1] != in1[i]) ans -= sum[t][ch(in1[i]) * 3 + ch(in1[i - 1])] - sum[st - 1][ch(in1[i]) * 3 + ch(in1[i - 1])];

		if (in2[st] == in1[i]) st++;
		en = nxt(en, in1[i]);
		if (en != M && in2[en] == in1[i]) en++;
	}
	return !printf("%lld\n", ans);
}
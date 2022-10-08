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

int IT_MAX = 4096;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

char in[1050][1050];

int cnt1[4][1050][1050];
int cnt2[4][1050][1050];
int cnt3[4][1050][1050];
int cnt4[4][1050][1050];
ldb lg1[1050][1050];
ldb lg2[1050][1050];
ldb lg3[1050][1050];
ldb lg4[1050][1050];

ll po2[10050];
ll po3[10050];
int main() {
	int N, i, j, k;
	po2[0] = po3[0] = 1;
	for (i = 1; i <= 10000; i++) {
		po2[i] = (po2[i - 1] * 2) % MOD;
		po3[i] = (po3[i - 1] * 3) % MOD;
	}
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%s", in[i] + 1);

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			for (k = 0; k < 4; k++) cnt1[k][i][j] = cnt1[k][i][j-1] + (in[i][j] == '0' + k);
			lg1[i][j] = lg1[i][j - 1];
			if (in[i][j] >= '2') lg1[i][j] += log10(in[i][j] - '0');
		}
	}
	for (j = 1; j <= N; j++) {
		for (i = 1; i <= N; i++) {
			for (k = 0; k < 4; k++) cnt2[k][i][j] = cnt2[k][i - 1][j] + (in[i][j] == '0' + k);
			lg2[i][j] = lg2[i - 1][j];
			if (in[i][j] >= '2') lg2[i][j] += log10(in[i][j] - '0');
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			for (k = 0; k < 4; k++) cnt3[k][i][j] = cnt3[k][i - 1][j - 1] + (in[i][j] == '0' + k);
			lg3[i][j] = lg3[i - 1][j - 1];
			if (in[i][j] >= '2') lg3[i][j] += log10(in[i][j] - '0');
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			for (k = 0; k < 4; k++) cnt4[k][i][j] = cnt4[k][i - 1][j + 1] + (in[i][j] == '0' + k);
			lg4[i][j] = lg4[i - 1][j + 1];
			if (in[i][j] >= '2') lg4[i][j] += log10(in[i][j] - '0');
		}
	}

	ldb mx = -1;
	ll ans = 0;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (in[i][j] == '0') continue;
			int st = 1, en = min(min(i - 1, j - 1), min(N - i, N - j)), mi, rv = 0;
			while (st <= en) {
				mi = (st + en) / 2;
				int c0 = 0;
				c0 += cnt1[0][i][j + mi] - cnt1[0][i][j - mi - 1];
				c0 += cnt2[0][i + mi][j] - cnt2[0][i - mi - 1][j];
				if (c0 == 0) {
					rv = mi;
					st = mi + 1;
				}
				else en = mi - 1;
			}

			int c2 = 0, c3 = 0;
			ldb s = 0;

			c2 += cnt1[2][i][j + rv] - cnt1[2][i][j - rv - 1];
			c2 += cnt2[2][i + rv][j] - cnt2[2][i - rv - 1][j];
			if (in[i][j] == '2') c2--;
			c3 += cnt1[3][i][j + rv] - cnt1[3][i][j - rv - 1];
			c3 += cnt2[3][i + rv][j] - cnt2[3][i - rv - 1][j];
			if (in[i][j] == '3') c3--;

			s += lg1[i][j + rv] - lg1[i][j - rv - 1];
			s += lg2[i + rv][j] - lg2[i - rv - 1][j];
			s -= log10(in[i][j] - '0');

			if (s > mx) {
				mx = s;
				ans = (po2[c2] * po3[c3]) % MOD;
			}
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (in[i][j] == '0') continue;
			if (i == j && j == 3) {
				i = j;
			}
			int st = 1, en = min(min(i - 1, j - 1), min(N - i, N - j)), mi, rv = 0;
			while (st <= en) {
				mi = (st + en) / 2;
				int c0 = 0;
				c0 += cnt3[0][i+mi][j + mi] - cnt3[0][i-mi-1][j - mi - 1];
				c0 += cnt4[0][i + mi][j - mi] - cnt4[0][i - mi - 1][j + mi + 1];
				if (c0 == 0) {
					rv = mi;
					st = mi + 1;
				}
				else en = mi - 1;
			}

			int c2 = 0, c3 = 0;
			ldb s = 0;

			c2 += cnt3[2][i+rv][j + rv] - cnt3[2][i-rv-1][j - rv - 1];
			c2 += cnt4[2][i + rv][j-rv] - cnt4[2][i - rv - 1][j+rv+1];
			if (in[i][j] == '2') c2--;
			c3 += cnt3[3][i+rv][j + rv] - cnt3[3][i-rv-1][j - rv - 1];
			c3 += cnt4[3][i + rv][j-rv] - cnt4[3][i - rv - 1][j+rv+1];
			if (in[i][j] == '3') c3--;

			s += lg3[i+rv][j + rv] - lg3[i-rv-1][j - rv - 1];
			s += lg4[i + rv][j-rv] - lg4[i - rv - 1][j+rv+1];
			s -= log10(in[i][j] - '0');

			if (s > mx) {
				mx = s;
				ans = (po2[c2] * po3[c3]) % MOD;
			}
		}
	}

	printf("%lld\n", ans);
	return 0;
}
//*/
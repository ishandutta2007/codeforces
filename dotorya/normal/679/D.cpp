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

int dis[505][505];
vector <int> rdis[505][505];
vector <int> V;

ldb prob[505];
ldb mxp[505];
int chk[505];

inline bool isEqual(ldb a, ldb b) {
	return abs(a - b) <= ERR;
}
int main() {
	int N, M, i, j, k, l;
	
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) if (i != j) dis[i][j] = INF;
	while (M--) {
		scanf("%d %d", &i, &j);
		dis[i][j] = dis[j][i] = 1;
	}
	for (k = 1; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
			}
		}
	}
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) rdis[i][dis[i][j]].push_back(j);

	ldb ans = 0;
	for (i = 1; i <= N; i++) {
		ldb totp = 0;
		for (j = 0; !rdis[i][j].empty(); j++) {
			ldb tp = 0;
			fill(prob + 1, prob + N + 1, 0);
			for (auto it : rdis[i][j]) {
				int c = 0;
				for (k = 1; k <= N; k++) if (dis[it][k] == 1) c++;
				for (k = 1; k <= N; k++) if (dis[it][k] == 1) prob[k] += 1.0 / (c*N);
			}
			for (k = 1; k <= N; k++) if (!isEqual(prob[k], 0)) V.push_back(k);

			fill(chk + 1, chk + N + 1, 0);
			for (k = 1; k <= N; k++) {
				ldb tp2 = 0;
				for (auto it : V) {
					int d = dis[k][it];
					if (chk[d] != k) {
						chk[d] = k;
						tp2 += prob[it];
						mxp[d] = prob[it];
					}
					else {
						tp2 += max((ldb)0, prob[it] - mxp[d]);
						mxp[d] = max(mxp[d], prob[it]);
					}
				}
				tp = max(tp, tp2);
			}
			totp += max(tp, (ldb)1.0 / N);
			V.clear();
		}
		ans = max(ans, totp);
	}
	return !printf("%.20lf\n", (db)ans);
}
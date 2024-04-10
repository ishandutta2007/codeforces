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

char in[505][505];
int G[505][505];
int del[505][505];
int sum[505][505];
int chk[500000];
int gsz[500000];
vector <pii> V;

void update_del(int sx, int ex, int sy, int ey, int v) {
	sx = max(sx, 1);
	sy = max(sy, 1);
	if (sx > ex || sy > ey) return;

	del[sx][sy] += v;
	del[sx][ey + 1] -= v;
	del[ex + 1][sy] -= v;
	del[ex + 1][ey + 1] += v;
}
int main() {
	int N, K, i, j, k, l;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%s", in[i] + 1);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			if (in[i][j] == '.') sum[i][j]++;
		}
	}

	int gcnt = 0;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (in[i][j] == 'X' || G[i][j] != 0) continue;
			gcnt++;
			int xmx = i, xmn = i, ymx = j, ymn = j;
			V.emplace_back(i, j);
			G[i][j] = gcnt;
			for (k = 0; k < V.size(); k++) {
				for (l = 0; l < 4; l++) {
					int tx = "1102"[l] + V[k].first - '1';
					int ty = "0211"[l] + V[k].second - '1';
					if (in[tx][ty] != '.' || G[tx][ty] != 0) continue;
					G[tx][ty] = gcnt;
					V.emplace_back(tx, ty);
					xmx = max(xmx, tx);
					xmn = min(xmn, tx);
					ymx = max(ymx, ty);
					ymn = min(ymn, ty);
				}
			}
			update_del(xmx - K + 1, xmn, ymx - K + 1, ymn, V.size());
			gsz[gcnt] = V.size();
			V.clear();
		}
	}
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) del[i][j] += del[i - 1][j] + del[i][j - 1] - del[i - 1][j - 1];

	int ans = 0;
	for (i = 1; i <= N-K+1; i++) {
		for (j = 1; j <= N-K+1; j++) {
			int c = (i - 1)*N + j;

			int t = K*K + del[i][j] - (sum[i + K - 1][j + K - 1] - sum[i - 1][j + K - 1] - sum[i + K - 1][j - 1] + sum[i - 1][j - 1]);
			for (k = j; k <= j + K - 1; k++) {
				int t2 = G[i - 1][k];
				if (chk[t2] != c) t += gsz[t2];
				chk[t2] = c;
			}
			for (k = j; k <= j + K - 1; k++) {
				int t2 = G[i+K][k];
				if (chk[t2] != c) t += gsz[t2];
				chk[t2] = c;
			}
			for (k = i; k <= i + K - 1; k++) {
				int t2 = G[k][j - 1];
				if (chk[t2] != c) t += gsz[t2];
				chk[t2] = c;
			}
			for (k = i; k <= i + K - 1; k++) {
				int t2 = G[k][j + K];
				if (chk[t2] != c) t += gsz[t2];
				chk[t2] = c;
			}
			ans = max(ans, t);
		}
	}
	return !printf("%d\n", ans);
}
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
const int MOD = 1000003;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-11;

int lr1[1100050][2];
int lr2[1100050][2];

int r1[1100050];
int r2[1100050];

vector <pii> V1;
vector <pii> V2;

int u1[1050];
int u2[1050];

int N, M;
void load1(int x, int* u) {
	int v = r1[x];
	for (int i = 0; i < M; i++) {
		v = lr1[v][1];
		u[i] = v;
	}
}
void load2(int y, int* u) {
	int v = r2[y];
	for (int i = 0; i < N; i++) {
		v = lr2[v][1];
		u[i] = v;
	}
}
int in[1050][1050];
int main() {
	int Q, i, j;
	scanf("%d %d %d", &N, &M, &Q);
	for (i = 0; i < N; i++) for (j = 0; j < M; j++) scanf("%d", &in[i][j]);

	int c = N*M;
	for (i = 0; i < N; i++) r1[i] = c++;
	for (i = 0; i < M; i++) r2[i] = c++;
	for (i = 0; i < N; i++) {
		int v = r1[i];
		for (j = 0; j < M; j++) {
			lr1[v][1] = i*M + j;
			lr1[i*M + j][0] = v;
			v = i*M + j;
		}
		lr1[v][1] = 1100000;
	}
	for (j = 0; j < M; j++) {
		int v = r2[j];
		for (i = 0; i < N; i++) {
			lr2[v][1] = i*M + j;
			lr2[i*M + j][0] = v;
			v = i*M + j;
		}
		lr2[v][1] = 1100000;
	}

	while (Q--) {
		int a, b, c, d, h, w, v;
		scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &h, &w);
		a--, b--, c--, d--;

		load2(b, u1);
		load2(d, u2);
		for (i = 0; i < h; i++) V1.emplace_back(u1[i + a], u2[i + c]);

		load2(b + w - 1, u1);
		load2(d + w - 1, u2);
		for (i = 0; i < h; i++) V1.emplace_back(u1[i + a], u2[i + c]);

		load1(a, u1);
		load1(c, u2);
		for (i = 0; i < w; i++) V2.emplace_back(u1[i + b], u2[i + d]);

		load1(a + h - 1, u1);
		load1(c + h - 1, u2);
		for (i = 0; i < w; i++) V2.emplace_back(u1[i + b], u2[i + d]);

		for (i = 0; i < 2*h; i++) {
			int v = i/h;
			int t1 = V1[i].first, t2 = V1[i].second;
			int t3 = lr1[t1][v], t4 = lr1[t2][v];
			lr1[t3][1 - v] = t2;
			lr1[t4][1 - v] = t1;
			lr1[t1][v] = t4;
			lr1[t2][v] = t3;
		}
		for (i = 0; i < 2 * w; i++) {
			int v = i / w;
			int t1 = V2[i].first, t2 = V2[i].second;
			int t3 = lr2[t1][v], t4 = lr2[t2][v];
			lr2[t3][1 - v] = t2;
			lr2[t4][1 - v] = t1;
			lr2[t1][v] = t4;
			lr2[t2][v] = t3;
		}
		V1.clear();
		V2.clear();
	}
	for (i = 0; i < N; i++) {
		load1(i, u1);
		for (j = 0; j < M; j++) {
			int x = u1[j] / M, y = u1[j] % M;
			printf("%d ", in[x][y]);
		}
		printf("\n");
	}
	return 0;
}
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
const int MOD = 10007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

char in[1050][1050];
int dis[1050][1050][4];

int P[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
vector <pair<pii, int>> V;

int N, M;
bool isValidt(int x, int y, int dir, int d) {
	char c = in[x][y];
	if (c == '+') return true;
	if (c == '*') return false;

	if (c == '-') {
		if (dir % 2 == 1) return d == 0 || d == 2;
		else return d == 1 || d == 3;
	}
	if (c == '|') {
		if (dir % 2 == 0) return d == 0 || d == 2;
		else return d == 1 || d == 3;
	}
	if (c == '^') return dir == d;
	if (c == '>') return dir == (d + 3) % 4;
	if (c == 'v') return dir == (d + 2) % 4;
	if (c == '<') return dir == (d + 1) % 4;
	if (c == 'U') return dir != d;
	if (c == 'R') return dir != (d + 3) % 4;
	if (c == 'D') return dir != (d + 2) % 4;
	if (c == 'L') return dir != (d + 1) % 4;
	return false;
}
bool isValid(int x, int y, int dir, int d) {
	if (x == 0 && y == 0 && dir == 3 && d == 2) {
		x = x;
	}
	if (x + P[d][0] < 0 || x + P[d][0] >= N) return false;
	if (y + P[d][1] < 0 || y + P[d][1] >= M) return false;

	return isValidt(x, y, dir, d) && isValidt(x + P[d][0], y + P[d][1], dir, (d + 2) % 4);
}
int main() {
	int i, j, k, t1, t2;
	int sx, sy, ex, ey;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) scanf("%s", in[i]);
	scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
	sx--, sy--, ex--, ey--;

	for (i = 0; i < N; i++) for (j = 0; j < M; j++) for (k = 0; k < 4; k++) dis[i][j][k] = INF;
	V.push_back(mp(pii(sx, sy), 0));
	dis[sx][sy][0] = 0;
	for (i = 0; i < V.size(); i++) {
		int x = V[i].first.first;
		int y = V[i].first.second;
		int dir = V[i].second;
		if (x == ex && y == ey) return !printf("%d\n", dis[x][y][dir]);
		for (j = 0; j < 4; j++) {
			if (!isValid(x, y, dir, j)) continue;
			int tx = x + P[j][0], ty = y + P[j][1], tdir = dir;
			if (dis[tx][ty][tdir] == INF) {
				dis[tx][ty][tdir] = dis[x][y][dir] + 1;
				V.push_back(mp(pii(tx, ty), tdir));
			}
		}
		
		int tdir = (dir + 1) % 4;
		if (dis[x][y][tdir] == INF) {
			dis[x][y][tdir] = dis[x][y][dir] + 1;
			V.push_back(mp(pii(x, y), tdir));
		}
	}
	return !printf("-1\n");
}
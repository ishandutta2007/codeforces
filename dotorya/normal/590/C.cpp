//*
#include <algorithm>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

#define pow10 pasiodfiopsdjviozjxciovjxcviozj
#define pow2 qpowdskopjkcoizxnzoicn

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <char, int> pci;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef pair <db, int> pdi;

int IT_MAX;
const int MOD = 1000000;
const int INF = 534567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;

char in[1050][1050];
int dis[3][1050][1050];
bool chk[3][1050][1050];

priority_queue <pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> H;
int P[4][2] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
int main() {
	int N, M, i, j, k;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) for (j = 0; j < M; j++) dis[0][i][j] = dis[1][i][j] = dis[2][i][j] = INF;
	for (i = 0; i < N; i++) {
		scanf("%s", in[i]);
		for (j = 0; j < M; j++) if (in[i][j] >= '1' && in[i][j] <= '3') dis[in[i][j] - '1'][i][j] = 0;
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < N; j++) for (k = 0; k < M; k++) if (in[j][k] == i + '1') H.push(make_pair(0,pii(j, k)));

		while (!H.empty()) {
			pair<int, pii> u = H.top();
			H.pop();
			if (chk[i][u.second.first][u.second.second]) continue;
			chk[i][u.second.first][u.second.second] = true;
			for (j = 0; j < 4; j++) {
				pii u2 = pii(u.second.first + P[j][0], u.second.second + P[j][1]);
				if (u2.first < 0 || u2.first >= N || u2.second < 0 || u2.second >= M || in[u2.first][u2.second] == '#') continue;
				int d = u.first+1;
				if (in[u.second.first][u.second.second] >= '1' && in[u.second.first][u.second.second] <= '3') d--;
				if (dis[i][u2.first][u2.second] > d) {
					dis[i][u2.first][u2.second] = d;
					H.push(make_pair(d, u2));
				}
			}
		}
	}

	int ans = INF * 3;
	for (i = 0; i < N; i++) for (j = 0; j < M; j++) ans = min(ans, dis[0][i][j] + dis[1][i][j] + dis[2][i][j]+((in[i][j] == '.')?1:0));
	if (ans >= INF/2) printf("-1");
	else printf("%d", ans);
	return 0;
}
//*/
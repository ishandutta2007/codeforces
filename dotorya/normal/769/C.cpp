#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()

char str[6] = "DLRU";
int P[4][2] = { {1,0},{0,-1},{0,1},{-1,0} };

int dis[1050][1050];
char in[1050][1050];
vector <pii> Vu;
int main() {
	int N, M, K, i, j, k, l;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 0; i < N; i++) scanf("%s", in[i]);

	int sx = 0, sy = 0;
	for (i = 0; i < N; i++) for (j = 0; j < M; j++) if (in[i][j] == 'X') sx = i, sy = j;

	memset(dis, 0x3f, sizeof(dis));
	dis[sx][sy] = 0;
	Vu.emplace_back(sx, sy);
	for (i = 0; i < Vu.size(); i++) {
		int ox = Vu[i].first, oy = Vu[i].second;
		for (j = 0; j < 4; j++) {
			int x = ox + P[j][0];
			int y = oy + P[j][1];
			if (x < 0 || x >= N || y < 0 || y >= M || in[x][y] == '*') continue;
			if (dis[x][y] == INF) {
				dis[x][y] = dis[ox][oy] + 1;
				Vu.emplace_back(x, y);
			}
		}
	}
	if (K % 2) return !printf("IMPOSSIBLE\n");

	int x = sx, y = sy;
	for (i = 1; i <= K; i++) {
		for (j = 0; j < 4; j++) {
			int tx = x + P[j][0], ty = y + P[j][1];
			if (tx < 0 || tx >= N || ty < 0 || ty >= M || dis[tx][ty] > K-i) continue;
			printf("%c", str[j]);
			x = tx, y = ty;
			break;
		}
		if (j >= 4) return !printf("IMPOSSIBLE\n");
	}
	return !printf("\n");
}
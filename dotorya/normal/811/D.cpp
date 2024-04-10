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
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

char di[5] = "UDLR";
int P[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

char in[105][105];

void update(int &x, int &y, int ex, int ey, int c) {
	printf("%c\n", di[c]);
	fflush(stdout);

	int tx, ty;
	scanf("%d %d", &tx, &ty);
	if (tx == ex && ty == ey) exit(0);
	x = tx, y = ty;
}

int rev[105][105];
bool dchk[105][105];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%s", in[i] + 1);

	int ex, ey;
	for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) if (in[i][j] == 'F') ex = i, ey = j;
	if (ex == 1 && ey == 1) return 0;

	int x = 1, y = 1;
	if (N == 1) {
		update(x, y, ex, ey, 3);
		if (y == 1) swap(di[2], di[3]);
		while (1) update(x, y, ex, ey, 3);
		return 0;
	}
	if (M == 1) {
		update(x, y, ex, ey, 1);
		if (x == 1) swap(di[0], di[1]);
		while (1) update(x, y, ex, ey, 1);
		return 0;
	}

	if (in[1][2] != '*') {
		update(x, y, ex, ey, 3);
		if (y == 1) swap(di[2], di[3]);
		else update(x, y, ex, ey, 2);

		while (in[x + 1][y] == '*') update(x, y, ex, ey, 3);
		update(x, y, ex, ey, 1);
		if (x == 1) swap(di[0], di[1]);
		else update(x, y, ex, ey, 0);
	}
	else {
		update(x, y, ex, ey, 1);
		if (x == 1) swap(di[0], di[1]);
		else update(x, y, ex, ey, 0);

		while (in[x][y + 1] == '*') update(x, y, ex, ey, 1);
		update(x, y, ex, ey, 3);
		if (y == 1) swap(di[2], di[3]);
		else update(x, y, ex, ey, 2);
	}

	vector <pii> Vu;
	dchk[x][y] = true;
	Vu.emplace_back(x, y);
	for (i = 0; i < Vu.size(); i++) {
		for (j = 0; j < 4; j++) {
			int tx = Vu[i].first + P[j][0];
			int ty = Vu[i].second + P[j][1];
			if (tx < 1 || tx > N || ty < 1 || ty > M) continue;
			if (in[tx][ty] == '*' || dchk[tx][ty]) continue;
			dchk[tx][ty] = true;
			rev[tx][ty] = j;
			Vu.emplace_back(tx, ty);
		}
	}

	vector <int> Va;
	while (ex != x || ey != y) {
		Va.push_back(rev[ex][ey]);
		ex += P[Va.back() ^ 1][0];
		ey += P[Va.back() ^ 1][1];
	}
	reverse(all(Va));
	for (auto it : Va) {
		printf("%c\n", di[it]);
		fflush(stdout);
		int t1, t2;
		scanf("%d %d", &t1, &t2);
	}
	return 0;
}
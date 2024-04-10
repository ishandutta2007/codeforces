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

int IT_MAX = 1 << 10;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

class bit {
public:
	int indt[1050];
	void update(int p, int v) {
		for (; p <= IT_MAX; p += p & (-p)) indt[p] += v;
	}
	int getsum(int p) {
		int rv = 0;
		for (; p; p -= p & (-p)) rv += indt[p];
		return rv;
	}
	int getpos(int s) {
		if (s == 0) return -1;
		if (indt[IT_MAX] < s) return INF;
		int rv = 0;
		for (int i = 9; i >= 0; i--) {
			if (indt[rv | (1 << i)] < s) rv |= (1 << i), s -= indt[rv];
		}
		return rv + 1;
	}

	int getupper(int x) { // > x
		int t = getsum(x);
		return getpos(t + 1);
	}
	int getlower(int x) { // < x
		int t = getsum(x - 1);
		return getpos(t);
	}
};

vector <pii> Vu;
int dis[1050][1050];
bit tr[2][1050];
void vpush(int x, int y, int d) {
	if (dis[x][y] == INF) {
		dis[x][y] = d;
		tr[0][x].update(y, -1);
		tr[1][y].update(x, -1);
		Vu.emplace_back(x, y);
	}
}

char in[1050][1050];
int sum[1050][1050];
bool isValid(int sx, int sy, int ex, int ey) {
	if (sx > ex) swap(sx, ex);
	if (sy > ey) swap(sy, ey);
	
	int s = sum[ex][ey] - sum[sx - 1][ey] - sum[ex][sy - 1] + sum[sx - 1][sy - 1];
	if (s) return false;
	return true;
}
int main() {
	int N, M, K, i, j, k, l;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= N; i++) scanf("%s", in[i]+1);

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if (in[i][j] == '#') continue;
			tr[0][i].update(j, 1);
			tr[1][j].update(i, 1);
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (int)(in[i][j] == '#');
		}
	}
	int sx, sy, ex, ey;
	scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
	memset(dis, 0x3f, sizeof(dis));
	vpush(sx, sy, 0);

	for (i = 0; i < Vu.size(); i++) {
		int x = Vu[i].first, y = Vu[i].second, d = dis[x][y] + 1;
		
		int t = y;
		while (1) {
			t = tr[0][x].getlower(t);
			if (t < 1 || t > M) break;
			if (abs(y - t) > K) break;
			if (!isValid(x, y, x, t)) break;
			vpush(x, t, d);
		}
		t = y;
		while (1) {
			t = tr[0][x].getupper(t);
			if (t < 1 || t > M) break;
			if (abs(y - t) > K) break;
			if (!isValid(x, y, x, t)) break;
			vpush(x, t, d);
		}
		t = x;
		while (1) {
			t = tr[1][y].getlower(t);
			if (t < 1 || t > N) break;
			if (abs(x - t) > K) break;
			if (!isValid(x, y, t, y)) break;
			vpush(t, y, d);
		}
		t = x;
		while (1) {
			t = tr[1][y].getupper(t);
			if (t < 1 || t > N) break;
			if (abs(x - t) > K) break;
			if (!isValid(x, y, t, y)) break;
			vpush(t, y, d);
		}
	}
	if (dis[ex][ey] == INF) printf("-1\n");
	else printf("%d\n", dis[ex][ey]);
	return 0;
}
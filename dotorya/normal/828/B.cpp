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

char in[105][105];

int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) scanf("%s", in[i]);

	int sx = INF, sy = INF, ex = -1, ey = -1, cnt = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (in[i][j] == 'W') continue;
			sx = min(sx, i);
			sy = min(sy, j);
			ex = max(ex, i);
			ey = max(ey, j);
			cnt++;
		}
	}
	if (sx == INF) return !printf("1\n");

	int sz = max(ex - sx + 1, ey - sy + 1);
	if (sz > N || sz > M) return !printf("-1\n");
	return !printf("%d\n", sz*sz - cnt);
}
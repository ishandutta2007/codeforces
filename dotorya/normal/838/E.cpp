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
#pragma comment(linker, "/STACK:33554432")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

int in[2550][2];
inline db sq(db a) {
	return a*a;
}
db getdis(int a, int b) {
	return sqrt(sq(in[a][0] - in[b][0]) + sq(in[a][1] - in[b][1]));
}

db dp[2550][2550][2];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d %d", &in[i][0], &in[i][1]);

	if (N == 2) return !printf("%.20lf\n", getdis(0, 1));

	for (i = 0; i < N; i++) {
		int p = (i + N - 1) % N;
		dp[i][i][0] = getdis(p, i);

		p = (i + 1) % N;
		dp[i][i][1] = getdis(p, i);
	}
	for (i = 1; i < N; i++) {
		for (j = 0; j < N; j++) {
			int x = j, y = (i + j) % N;

			int p = (x + N - 1) % N;
			dp[x][y][0] = 0;
			dp[x][y][0] = max(dp[x][y][0], dp[(x + 1) % N][y][0] + getdis(p, x));
			dp[x][y][0] = max(dp[x][y][0], dp[x][(y + N - 1) % N][1] + getdis(p, y));

			p = (y + 1) % N;
			dp[x][y][1] = 0;
			dp[x][y][1] = max(dp[x][y][1], dp[(x + 1) % N][y][0] + getdis(p, x));
			dp[x][y][1] = max(dp[x][y][1], dp[x][(y + N - 1) % N][1] + getdis(p, y));
		}
	}

	db ans = 0;
	for (i = 0; i < N; i++) ans = max(ans, dp[(i + 2) % N][i][0]);
	return !printf("%.20lf\n", ans);
}
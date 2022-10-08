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

int IT_MAX = 1 << 17;
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

char in[2050][2050];
int sum[2050][2050];
int getsum(int sx, int ex, int sy, int ey) {
	return sum[ex][ey] - sum[sx - 1][ey] - sum[ex][sy - 1] + sum[sx - 1][sy - 1];
}
int main() {
	int N, M, K, i, j;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= N; i++) {
		scanf("%s", in[i] + 1);
		for (j = 1; j <= M; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			if (in[i][j] == '*') sum[i][j]++;
		}
	}

	int ans = 0;
	for (i = 1; i <= N; i++) {
		for (j = K; j <= M; j++) if (!getsum(i, i, j - K + 1, j)) ans++;
	}
	if (K != 1) {
		for (j = 1; j <= M; j++) {
			for (i = K; i <= N; i++) if (!getsum(i - K + 1, i, j, j)) ans++;
		}
	}
	return !printf("%d\n", ans);
}
//*/
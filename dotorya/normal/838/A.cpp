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
#pragma comment(linker, "/STACK:1048576")
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

int IT_MAX = 1 << 12;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

char in[2550][2550];
int cnt[2550][2550];
int sum[2550][2550];
int main() {
	int N, M, i, j, k, l;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%s", in[i] + 1);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			if (in[i][j] == '1') sum[i][j]++;
		}
	}

	int ans = INF;
	for (int x = 2; x <= max(N, M); x++) {
		int s = 0;
		for (i = 0;; i++) {
			int sx = i*x + 1;
			if (sx > N) break;
			for (j = 0;; j++) {
				int sy = j*x + 1;
				if (sy > M) break;
				int ex = min(N, sx + x - 1);
				int ey = min(M, sy + x - 1);
				int c = sum[ex][ey] - sum[sx - 1][ey] - sum[ex][sy - 1] + sum[sx - 1][sy - 1];
				s += min(c, x*x - c);
			}
		}
		ans = min(ans, s);
	}
	return !printf("%d\n", ans);
}
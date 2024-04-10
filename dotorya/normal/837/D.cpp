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

int IT_MAX = 1 << 18;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db EPS = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

int dp[205][8010];
int tdp[205][8010];
int in[205][2];
int main() {
	int N, K, i, j, k;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		ll t;
		scanf("%lld", &t);
		while (t % 2 == 0) {
			in[i][0]++;
			t /= 2;
		}
		while (t % 5 == 0) {
			in[i][1]++;
			t /= 5;
		}
	}

	for (i = 0; i <= K; i++) for (j = 0; j <= 8000; j++) dp[i][j] = -INF;
	dp[0][0] = 0;
	for (i = 1; i <= N; i++) {
		for (j = 0; j <= K; j++) for (k = 0; k <= 8000; k++) tdp[j][k] = dp[j][k];
		for (j = 0; j < K; j++) {
			for (k = 0; k <= 8000; k++) {
				int j2 = j + 1, k2 = k + in[i][1];
				if (k2 <= 8000) tdp[j2][k2] = max(tdp[j2][k2], dp[j][k] + in[i][0]);
			}
		}
		for (j = 0; j <= K; j++) for (k = 0; k <= 8000; k++) dp[j][k] = tdp[j][k];
	}

	int ans = 0;
	for (i = 0; i <= K; i++) for (j = 0; j <= 8000; j++) ans = max(ans, min(j, dp[i][j]));
	return !printf("%d\n", ans);
}
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
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll dp[1050][10050];
ll C[10050];
ll cost[10050];
int main() {
	int N, W, B, X, i, j, k;
	scanf("%d %d %d %d", &N, &W, &B, &X);
	for (i = 1; i <= N; i++) scanf("%lld", &C[i]);
	for (i = 1; i <= N; i++) scanf("%lld", &cost[i]);

	for (i = 0; i <= N; i++) for (j = 0; j <= 10000; j++) dp[i][j] = -LL_INF;
	dp[0][0] = W;
	for (i = 1; i <= N; i++) {
		for (j = 0; j <= 10000; j++) {
			ll v = dp[i-1][j];
			if (v < 0) continue;
			
			ll mx = C[i];
			if (cost[i]) mx = min(mx, v / cost[i]);
			for (k = 0; k <= mx; k++) dp[i][j + k] = max(dp[i][j + k], dp[i - 1][j] - cost[i] * k);
		}
		for (j = 0; j <= 10000; j++) if (dp[i][j] >= 0) dp[i][j] = min(dp[i][j] + X, (ll)B*j + W);
	}

	int ans = 0;
	for (i = 1; i <= 10000; i++) if (dp[N][i] >= 0) ans = max(ans, i);
	return !printf("%d\n", ans);
}
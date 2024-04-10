#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <cmath>
#include <vector>
#include <deque>
//#include <unordered_set>
//#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1<<21;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-10;

ll V[100050];
ll C[100050];

ll dp[100050];
ll mx[100050];
ll mxt[2][2];
int main() {
	int N, Q, i, j;
	scanf("%d %d", &N, &Q);
	for (i = 1; i <= N; i++) scanf("%lld", V + i);
	for (i = 1; i <= N; i++) scanf("%lld", C + i);
	while (Q--) {
		ll A, B;
		scanf("%lld %lld", &A, &B);

		for (i = 1; i <= N; i++) mx[i] = -LL_INF;
		mxt[0][0] = mxt[0][1] = mxt[1][0] = 0;
		mxt[1][1] = -1;
		for (i = 1; i <= N; i++) {
			dp[i] = A * V[i] + mx[C[i]];
			if (mxt[0][1] != C[i]) dp[i] = max(dp[i], B*V[i] + mxt[0][0]);
			if (mxt[1][1] != C[i]) dp[i] = max(dp[i], B*V[i] + mxt[1][0]);

			mx[C[i]] = max(mx[C[i]], dp[i]);
			
			if (mxt[0][1] == C[i]) {
				if (dp[i] > mxt[0][0]) mxt[0][0] = dp[i];
			}
			else {
				if (dp[i] > mxt[1][0]) {
					mxt[1][0] = dp[i];
					mxt[1][1] = C[i];
				}
				if (mxt[0][0] < mxt[1][0]) {
					swap(mxt[0][0], mxt[1][0]);
					swap(mxt[0][1], mxt[1][1]);
				}
			}
		}

		ll ans = 0;
		for (i = 1; i <= N; i++) ans = max(ans, dp[i]);
		printf("%lld\n", ans);
	}
	return 0;
}
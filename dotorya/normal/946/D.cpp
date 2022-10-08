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
#define Se second
#define Fi first

int dp[505];
int tdp[505];

int mn[505];
int sum[505];

char u[505];
int main() {
	int N, M, K, i, j;
	scanf("%d %d %d", &N, &M, &K);

	while(N--) {
		memset(tdp, 0x3f, sizeof(tdp));
		scanf("%s", u + 1);
		for (i = 1; i <= M; i++) sum[i] = sum[i - 1] + u[i] - '0';

		for (i = 0; i <= K; i++) mn[i] = INF;
		if (sum[M] <= K) mn[sum[M]] = 0;
		for (i = 1; i <= M; i++) {
			for (j = i; j <= M; j++) {
				int s = sum[M] - sum[j] + sum[i - 1];
				if(s <= K) mn[s] = min(mn[s], j - i + 1);
			}
		}
		
		for (i = 0; i <= K; i++) for (j = 0; i + j <= K; j++) tdp[i + j] = min(tdp[i + j], dp[i] + mn[j]);
		for (i = 0; i <= K; i++) dp[i] = tdp[i];
	}

	int ans = INF;
	for (i = 0; i <= K; i++) ans = min(ans, dp[i]);
	return !printf("%d\n", ans);
}
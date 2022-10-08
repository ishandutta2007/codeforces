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
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int dp[2][200050];
int tdp[2][200050];
int mn[2][200050];
vector <pii> Vu;
int main() {
	int N, K, i, j, k;
	scanf("%d %d", &N, &K);

	int prv = 0;
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (i = 1; i <= K + 1; i++) {
		int S, E;
		if (i <= K) scanf("%d %d", &S, &E);
		else S = E = 2 * N;
		memset(tdp, 0x3f, sizeof(tdp));
		for (j = 0; j <= 2 * N; j++) {
			tdp[0][j] = dp[0][j];
			if (j >= S - prv) tdp[1][j] = dp[1][j - (S - prv)];
		}
		for (j = 0; j <= 2 * N; j++) {
			dp[0][j] = tdp[0][j];
			dp[1][j] = tdp[1][j];
		}

		int T = E - S;
		for (j = 0; j < 2; j++) {
			int st = 0;
			Vu.clear();
			for (k = 0; k <= N; k++) {
				if (k >= T + 1) {
					int x = k - T - 1;
					if (Vu[st].second == x) st++;
				}
				while (Vu.size() > st) {
					if (Vu.back().first >= dp[j][k]) Vu.pop_back();
					else break;
				}
				Vu.emplace_back(dp[j][k], k);
				mn[j][k] = Vu[st].first;
			}
		}

		prv = E;
		memset(tdp, 0x3f, sizeof(tdp));
		for (j = 0; j <= 2 * N; j++) {
			tdp[0][j] = min(tdp[0][j], dp[0][j]);
			if (j >= T) tdp[1][j] = min(tdp[1][j], dp[1][j - T]);
		}

		for (j = 0; j <= 2 * N; j++) {
			tdp[0][j] = min(tdp[0][j], mn[1][j] + 1);
			tdp[0][j] = min(tdp[0][j], mn[0][j] + 2);
			tdp[1][j] = min(tdp[1][j], mn[0][j] + 1);
			tdp[1][j] = min(tdp[1][j], mn[1][j] + 2);
		}
		for (j = 0; j <= 2 * N; j++) dp[0][j] = tdp[0][j], dp[1][j] = tdp[1][j];
	}

	int ans = min(dp[0][N], dp[1][N]);
	if (ans > INF / 2) printf("Hungry\n");
	else printf("Full\n%d\n", ans);
	return 0;
}
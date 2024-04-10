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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int conn[22];
int dp[4200000][3];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		t1--, t2--;
		conn[t1] |= 1 << t2;
		conn[t2] |= 1 << t1;
	}
	for (i = 0; i < N; i++) conn[i] |= 1 << i;

	memset(dp, 0x3f, sizeof(dp));
	for (i = 1; i < (1 << N); i++) {
		for (j = 0; j < N; j++) {
			if (!(i & (1 << j))) continue;
			if ((conn[j] & i) != i) break;
		}
		if (j >= N) dp[i][0] = 0;
		for (j = 0; j < N; j++) {
			if (!(i & (1 << j))) continue;
			int x = i | conn[j];
			if (dp[x][0] > dp[i][0] + 1) {
				dp[x][0] = dp[i][0] + 1;
				dp[x][1] = i;
				dp[x][2] = j;
			}
		}
	}

	int x = (1 << N) - 1;
	printf("%d\n", dp[x][0]);
	vector <int> Va;
	while (dp[x][0]) {
		Va.push_back(dp[x][2]);
		x = dp[x][1];
	}
	reverse(all(Va));
	for (auto it : Va) printf("%d ", it + 1);
	return !printf("\n");
}
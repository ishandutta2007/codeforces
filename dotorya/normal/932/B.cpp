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

int IT_MAX = 1 << 19;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first


int dp[1000050];
ll sum[11][1000050];
int main() {
	int i, j;
	for (i = 1; i <= 9; i++) dp[i] = i;
	for (i = 10; i <= 1000000; i++) {
		int t = 1, t2 = i;
		while (t2) {
			if (t2 % 10 == 0) {
				t2 /= 10;
				continue;
			}
			t *= t2 % 10;
			t2 /= 10;
		}
		dp[i] = dp[t];
	}
	for (i = 1; i <= 1000000; i++) {
		for (j = 0; j < 10; j++) sum[j][i] = sum[j][i - 1];
		sum[dp[i]][i]++;
	}

	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		printf("%d\n", sum[t3][t2] - sum[t3][t1 - 1]);
	}
	return 0;
}
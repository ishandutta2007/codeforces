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

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18; // segment tree size
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f; // memset(dp, 0x3f, sizeof(dp)), 2*INF < INT_MAX
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10; // double EPS

char in[105][105];
int cnt[105][105];
int main() {
	int N, K, i, j, k;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%s", in[i] + 1);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N - K + 1; j++) {
			for (k = 0; k < K; k++) if (in[i][j + k] == '#') break;
			if (k < K) continue;
			for (k = 0; k < K; k++) cnt[i][j + k]++;
		}
	}
	for (i = 1; i <= N - K + 1; i++) {
		for (j = 1; j <= N; j++) {
			for (k = 0; k < K; k++) if (in[i + k][j] == '#') break;
			if (k < K) continue;
			for (k = 0; k < K; k++) cnt[i + k][j]++;
		}
	}

	int mx = 0;
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) mx = max(mx, cnt[i][j]);

	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) if (mx == cnt[i][j]) return !printf("%d %d\n", i, j);
	return 0;
}
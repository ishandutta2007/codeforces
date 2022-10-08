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
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

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

int IT_MAX = 131072;
const ll MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

int in[105][105];
int cnt[105];

int pos[105];
int ans[105];
int main() {
	int N, i, j, k, l;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) scanf("%d", &in[i][j]);

	cnt[0] = -1;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			for (k = j + 1; k <= N; k++) {
				if (in[j][k] < i) continue;
				if(in[j][k] == i) cnt[j]++, cnt[k]++;
			}
		}
		int mx = 0;
		for (j = 1; j <= N; j++) if (ans[j] == 0 && cnt[mx] < cnt[j]) mx = j;

		ans[mx] = i;
		pos[i] = mx;

		fill(cnt + 1, cnt + N + 1, 0);
	}

	for (i = 1; i <= N; i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
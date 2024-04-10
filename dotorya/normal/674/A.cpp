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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-13;

int ans[5050];
int cnt[5050];
int in[5050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	int mx = 0;
	for (i = 1; i <= N; i++) {
		fill(cnt + 1, cnt + N + 1, 0);
		mx = 1;
		for (j = i; j <= N; j++) {
			cnt[in[j]]++;
			if (cnt[in[j]] > cnt[mx] || (cnt[in[j]] == cnt[mx] && in[j] < mx)) mx = in[j];
			ans[mx]++;
		}
	}

	for (i = 1; i <= N; i++) printf("%d ", ans[i]);
	return !printf("\n");
}
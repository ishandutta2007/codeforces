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
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 987654321;
const int INF = 1034567890;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int bit[300000];
void update(int p, int v) {
	for (; p <= IT_MAX; p += p & (-p)) bit[p] += v;
}
int getsum(int p) {
	int rv = 0;
	for (; p > 0; p -= p & (-p)) rv += bit[p];
	return rv;
}

pair<pii, int> u[200050];
pii u2[200050];
int tch[200050];
int in[200050];
int ch[200050];
int ans[200050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &u[i].first.first, &u[i].first.second);
		u[i].second = i;
	}
	sort(u + 1, u + N + 1);
	for (i = 1; i <= N; i++) {
		in[i] = u[i].first.second;
		tch[i] = u[i].second;
	}

	for (IT_MAX = 2; IT_MAX < N; IT_MAX *= 2);
	
	for (i = 1; i <= N; i++) u2[i] = pii(in[i], i);
	sort(u2 + 1, u2 + N + 1);
	for (i = 1; i <= N; i++) ch[u2[i].second] = i;

	for (i = N; i >= 1; i--) {
		ans[tch[i]] = getsum(ch[i] - 1);
		update(ch[i], 1);
	}
	for (i = 1; i <= N; i++) printf("%d\n", ans[i]);
	return 0;
}
//*/
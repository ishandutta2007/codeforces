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

int in[100050][2];
int r[100050];
int root(int x) {
	return (r[x] == x) ? x : (r[x] = root(r[x]));
}

int vcnt[100050];
int ecnt[100050];
int main() {
	int N, M, i;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) r[i] = i;

	for (i = 1; i <= M; i++) {
		scanf("%d %d", &in[i][0], &in[i][1]);
		int t1 = root(in[i][0]);
		int t2 = root(in[i][1]);
		if (t1 != t2) r[t1] = t2;
	}

	for (i = 1; i <= N; i++) vcnt[root(i)]++;
	for (i = 1; i <= M; i++) ecnt[root(in[i][0])]++;

	int ans = 0;
	for (i = 1; i <= N; i++) if (vcnt[i] > ecnt[i]) ans++;
	printf("%d\n", ans);
	return 0;
}
//*/
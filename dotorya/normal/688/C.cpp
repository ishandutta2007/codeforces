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
const ldb ERR = 1E-10;

int r[100050][2];
int root(int x) {
	if (r[x][0] == x) return r[x][0];

	int t = r[x][0];
	r[x][0] = root(r[x][0]);
	r[x][1] ^= r[t][1];
	return r[x][0];
}

vector <int> ans[2];
int main() {
	int N, M, i, t1, t2;
	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++) r[i][0] = i;
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &t1, &t2);
		int u1 = root(t1);
		int u2 = root(t2);
		int u3 = r[t1][1] ^ r[t2][1]^1;
		if (u1 == u2 && u3 == 1) return !printf("-1\n");

		if (u1 != u2) {
			r[u1][0] = u2;
			r[u1][1] = u3;
		}
	}
	for (i = 1; i <= N; i++) {
		t1 = root(i);
		ans[r[i][1]].push_back(i);
	}

	printf("%d\n", ans[0].size());
	for (auto it : ans[0]) printf("%d ", it);
	printf("\n");
	printf("%d\n", ans[1].size());
	for (auto it : ans[1]) printf("%d ", it);
	printf("\n");
	return 0;
}
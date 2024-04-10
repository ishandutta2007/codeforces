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
const ll MOD = 1000000009;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-13;

vector <int> son[100050];
int sz[100050];
int lr[100050][2];
ldb del[100050];
int lr_num = 0;
void DFS1(int n) {
	lr[n][0] = ++lr_num;
	sz[n] = 1;
	for (auto it : son[n]) {
		DFS1(it);
		sz[n] += sz[it];
	}
	lr[n][1] = lr_num;
}
inline void update(int p1, int p2, ldb v) {
	del[p1] += v;
	del[p2 + 1] -= v;
}
void DFS2(int n) {
	update(lr[n][0], lr[n][1], 1);
	if (son[n].empty()) return;
	
	int sum = 0;
	for (auto it : son[n]) sum += sz[it];
	for (auto it : son[n]) update(lr[it][0], lr[it][1], (sum - sz[it]) * 1.0 / 2);
	for (auto it : son[n]) DFS2(it);
}
int main() {
	int N, t, i;
	scanf("%d", &N);
	for (i = 2; i <= N; i++) {
		scanf("%d", &t);
		son[t].push_back(i);
	}
	DFS1(1);
	DFS2(1);
	for (i = 1; i <= N; i++) del[i] += del[i - 1];
	for (i = 1; i <= N; i++) printf("%.1lf ", (db)del[lr[i][0]]);
	return !printf("\n");
}
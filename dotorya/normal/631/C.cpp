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

int IT_MAX = 131072;
const ll MOD = 1000000009;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

int in[200050];
int ans[200050];
vector <pii> V;

int main() {
	int N, M, i, j, t1, t2;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &t1, &t2);
		while (!V.empty()) {
			if (V.back().first > t2) break;
			V.pop_back();
		}
		V.push_back(pii(t2, t1));
	}
	V.push_back(pii(0, 0));

	for (i = V[0].first + 1; i <= N; i++) ans[i] = in[i];

	sort(in + 1, in + V[0].first + 1);

	int st = 1, en = V[0].first;
	for (i = 0; i + 1 < V.size(); i++) {
		for (j = V[i].first; j >= V[i + 1].first + 1; j--) {
			if (V[i].second == 1) ans[j] = in[en--];
			else ans[j] = in[st++];
		}
	}

	for (i = 1; i <= N; i++) printf("%d ", ans[i]);
	printf("\n");
}
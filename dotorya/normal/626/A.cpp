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
const ll MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-6;

pii operator + (pii a, pii b) {
	return pii(a.first + b.first, a.second + b.second);
}
pii ch[1050];

char in[205];
int main() {
	ch['U'] = pii(-1, 0);
	ch['D'] = pii(1, 0);
	ch['L'] = pii(0, -1);
	ch['R'] = pii(0, 1);

	int ans = 0, N, i, j, k;
	scanf("%d %s", &N, in);

	for (i = 0; i < N; i++) {
		for (j = i; j < N; j++) {
			pii u = pii(0, 0);
			for (k = i; k <= j; k++) u = u + ch[in[k]];
			if (u == pii(0, 0)) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
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
const ll MOD = 1000;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

typedef pair<ldb, int> pdi;

int P[105];

int cnt[105];
ldb po[105][100050];
priority_queue <pdi> H;
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &P[i]);
		po[i][0] = 1;
		for (j = 1; j <= 100000; j++) po[i][j] = po[i][j - 1] * (1 - 1.0 * P[i] / 100);
	}

	ldb p = 0;
	for (i = 1; i <= N; i++) {
		p += log10(1.0*P[i] / 100);
		H.push(pdi((1-po[i][2])/(1-po[i][1]), i));
		cnt[i] = 1;
	}

	ldb ans = N;
	for (i = 1; i <= 1000000; i++) {
		pdi u = H.top();
		H.pop();
		ldb np = p + log10(u.first);
		ans += 1 - pow(10, p);// pow(10, np) - pow(10, p);
		p = np;
		if (cnt[u.second] >= 99999) break;
		cnt[u.second]++;
		H.push(pdi((1 - po[u.second][cnt[u.second] + 1]) / (1 - po[u.second][cnt[u.second]]), u.second));
	}
	printf("%.20lf\n", (db)ans);
	return 0;
}
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

int P[55];
int T[55];
int main() {
	int c1 = 0, c2 = 0;

	int N, C, i;
	scanf("%d %d", &N, &C);
	for (i = 1; i <= N; i++) scanf("%d", &P[i]);
	for (i = 1; i <= N; i++) scanf("%d", &T[i]);
	int s = 0;
	for (i = 1; i <= N; i++) {
		s += T[i];
		c1 += max(0, P[i] - s*C);
	}

	s = 0;
	for (i = N; i >= 1; i--) {
		s += T[i];
		c2 += max(0, P[i] - s*C);
	}

	if (c1 > c2) printf("Limak\n");
	else if (c1 < c2) printf("Radewoosh\n");
	else printf("Tie\n");
	return 0;
}
//*/
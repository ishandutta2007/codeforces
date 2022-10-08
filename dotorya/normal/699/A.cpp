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
#include <string>
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

char in1[200050];
int in2[200050];
int main() {
	int N, i;
	scanf("%d %s", &N, in1);
	for (i = 0; i < N; i++) scanf("%d", &in2[i]);

	int ans = INF;
	for (i = 0; i < N - 1; i++) if (in1[i] == 'R' && in1[i + 1] == 'L') ans = min(ans, (in2[i + 1] - in2[i]) / 2);
	if (ans == INF) ans = -1;
	return !printf("%d\n", ans);
}
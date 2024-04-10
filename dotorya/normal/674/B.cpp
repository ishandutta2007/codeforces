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

int in[5];

vector <int> V;
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= 4; i++) scanf("%d", &in[i]);

	if (N == 4 || K <= N) return !printf("-1\n");

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= 4; j++) if (i == in[j]) break;
		if (j == 5) V.push_back(i);
	}

	printf("%d %d ", in[1], in[3]);
	for (auto it : V) printf("%d ", it);
	printf("%d %d\n", in[4], in[2]);

	printf("%d %d ", in[3], in[1]);
	for (auto it : V) printf("%d ", it);
	printf("%d %d ", in[2], in[4]);
	return 0;
}
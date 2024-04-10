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
const int MOD = 10007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

char in[100050][50];
int v[100050];
int main() {
	int N, K, i;
	scanf("%d %d", &N, &K);
	for (i = 0; i <= N; i++) scanf("%s", in[i]);

	int cnt = 0;
	for (i = 0; i <= N; i++) if (strcmp(in[i], "?") != 0) cnt++;
	if (K == 0) {
		if (strcmp(in[0], "0") == 0) return !printf("Yes\n");
		if (strcmp(in[0], "?") != 0) return !printf("No\n");

		if (cnt % 2 == 1) return !printf("Yes\n");
		else return !printf("No\n");
	}
	
	if (cnt == N + 1) {
		ll u = 0;
		for (i = N; i >= 0 && u != LL_INF; i--) {
			u = u * K + atoi(in[i]);
			if (abs(u) >= INF) u = LL_INF;
		}
		if (u == 0) return !printf("Yes\n");
		else return !printf("No\n");
	}

	if ((N + 1) % 2 == 0) printf("Yes\n");
	else printf("No\n");
	return 0;
}
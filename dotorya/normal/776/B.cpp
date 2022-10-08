#include <algorithm>
#include <assert.h>
#include <bitset>
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
#include <cmath>
#include <vector>
#include <deque>
//#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
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

int IT_MAX = 1 << 20;
const ll MOD = 98765431;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-6;

bool pchk[200050];
int main() {
	int N, i, j;
	
	for (i = 2; i <= 200000; i++) {
		if (pchk[i]) continue;
		for (j = 2 * i; j <= 200000; j += i) pchk[j] = true;
	}
	scanf("%d", &N);
	if (N <= 2) {
		printf("1\n");
		for (i = 1; i <= N; i++) printf("1 ");
		return !printf("\n");
	}
	printf("2\n");
	for (i = 2; i <= N + 1; i++) {
		if (!pchk[i]) printf("1 ");
		else printf("2 ");
	}
	return !printf("\n");
}
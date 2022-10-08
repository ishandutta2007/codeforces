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
#include <cmath>
#include <vector>
#include <deque>
//#include <unordered_set>
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
const ll MOD = 5000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-11;

int main() {
	int	N, K, A, B, i, j;
	char c1 = 'G', c2 = 'B';
	scanf("%d %d %d %d", &N, &K, &A, &B);
	if (A < B) {
		swap(A, B);
		swap(c1, c2);
	}

	if (A == B) {
		for (i = 1; i <= A; i++) printf("GB");
		return !printf("\n");
	}
	if (A > (B + 1)*K) return !printf("NO\n");
	
	int t = A - (B + 1);
	for (i = 0; i <= B; i++) {
		printf("%c", c1);
		int v = min(K - 1, t);
		t -= v;
		for (j = 1; j <= v; j++) printf("%c", c1);
		if (i != B) printf("%c", c2);
	}
	return !printf("\n");
}
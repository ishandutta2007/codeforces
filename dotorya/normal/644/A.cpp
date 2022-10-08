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
const int INF = 2034567891;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int main() {
	int N, A, B, i, j;
	scanf("%d %d %d", &N, &A, &B);
	if (N > A*B) return !printf("-1\n");

	if (B % 2 == 1) {
		for (i = 0; i < A; i++) {
			for (j = 0; j < B; j++) {
				int t = i*B + j;
				if (t >= N) t = -1;
				t++;
				printf("%d ", t);
			}
			printf("\n");
		}
	}
	else {
		for (i = 0; i < A; i++) {
			for (j = 0; j < B; j++) {
				int t = i*B + j;
				if (i % 2 == 1) t = i*B + (j ^ 1);
				if (t >= N) t = -1;
				t++;
				printf("%d ", t);
			}
			printf("\n");
		}
	}
	return 0;
}
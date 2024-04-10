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
const ldb ERR = 1E-10;

char in1[100050];
char in2[35];
int main() {
	scanf("%s %s", in1, in2);

	int L1 = strlen(in1), L2 = strlen(in2), i, j;
	
	int ans = 0;
	for (i = 0; i <= L1 - L2; i++) {
		for (j = 0; j < L2; j++) if (in1[i + j] != in2[j]) break;
		if (j >= L2) {
			ans++;
			in1[i + L2 - 1] = '#';
		}
	}
	printf("%d\n", ans);
	return 0;
}
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

int IT_MAX = 262144;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-11;

char in[10];
int main() {
	int N, i, j, k;
	scanf("%d %s", &N, in);

	int v1 = in[0] - '0', v2 = in[1] - '0', v3 = in[3] - '0', v4 = in[4] - '0';

	int s = 1, e = 12;
	if (N == 24) {
		s = 0, e = 23;
	}

	int ans = 5;
	int a1, a2, a3, a4;
	for (i = s; i <= e; i++) {
		for (j = 0; j <= 59; j++) {
			int tv1 = i / 10, tv2 = i % 10, tv3 = j / 10, tv4 = j % 10;
			
			int c = 0;
			if (v1 != tv1) c++;
			if (v2 != tv2) c++;
			if (v3 != tv3) c++;
			if (v4 != tv4) c++;
			if (ans > c) {
				a1 = tv1;
				a2 = tv2;
				a3 = tv3;
				a4 = tv4;
				ans = c;
			}
		}
	}
	return !printf("%d%d:%d%d\n", a1, a2, a3, a4);
}
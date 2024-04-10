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

int IT_MAX = 1<<21;
const int MOD = 1234567891;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-10;

char in1[200050];
char in2[200050];

int dp1[200050];
int dp2[200050];

int sum[200050][26];
int main() {
	int N, M, i, j;
	scanf("%s %s", in1 + 1, in2 + 1);
	N = strlen(in1 + 1);
	M = strlen(in2 + 1);
	
	for (i = 1; i <= M; i++) {
		for (j = 0; j < 26; j++) sum[i][j] = sum[i - 1][j];
		sum[i][in2[i] - 'a']++;
	}
	for (i = 1; i <= N; i++) {
		dp1[i] = dp1[i - 1];
		if (dp1[i] != M && in1[i] == in2[dp1[i] + 1]) dp1[i]++;
	}
	dp2[N+1] = M + 1;
	for (i = N; i >= 1; i--) {
		dp2[i] = dp2[i + 1];
		if (dp2[i] != 1 && in1[i] == in2[dp2[i] - 1]) dp2[i]--;
	}

	for (i = 1; i <= N; i++) {
		int v1 = dp1[i - 1] + 1, v2 = dp2[i + 1] - 1;
		if (v2 <= 0) v2 = 1;
		if (v1 > M) v1 = M;
		
		int s = sum[v1][in1[i] - 'a'] - sum[v2 - 1][in1[i] - 'a'];
		if (s <= 0) return !printf("No\n");
	}
	return !printf("Yes\n");
}
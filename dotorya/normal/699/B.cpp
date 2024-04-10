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

char in[1050][1050];
int sumr[1050];
int sumc[1050];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%s", in[i] + 1);
	
	int tot = 0;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if (in[i][j] != '*') continue;
			sumr[i]++;
			sumc[j]++;
			tot++;
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			int c = sumr[i] + sumc[j];
			if (in[i][j] == '*') c--;
			if (c == tot) return !printf("YES\n%d %d\n", i, j);
		}
	}
	return !printf("NO\n");
}
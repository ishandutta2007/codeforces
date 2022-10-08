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

int in[105];

char u[10050];
bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i < N; i++) scanf("%d", &in[i]);
	scanf("%d\n", &in[N]);

	for (i = 1; i <= N; i++) {
		fgets(u, 10050, stdin);
		int c = 0;
		for (j = 0; u[j] != '\n' && u[j] != 0; j++) if (isVowel(u[j])) c++;
		if (c == in[i]) continue;
		return !printf("NO\n");
	}
	return !printf("YES\n");
}
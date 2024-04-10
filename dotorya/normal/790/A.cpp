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

int IT_MAX = 1 << 17;
const ll MOD = 999983;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-12;

char u[26];
string ch(int n) {
	u[0] = 'A';
	if (n >= 26) u[0] = 'B';
	u[1] = 'a' + n % 26;
	return string(u);
}

char in[105][105];

int ans[105];
int main() {
	int N, K, i;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N - K + 1; i++) scanf("%s", in[i]);

	for (i = 1; i < K; i++) ans[i] = i;
	for (i = K; i <= N; i++) {
		if (in[i - K + 1][0] == 'Y') ans[i] = i;
		else ans[i] = ans[i - K + 1];
	}
	for (i = 1; i <= N; i++) printf("%s ", ch(ans[i]).c_str());
	return !printf("\n");
}
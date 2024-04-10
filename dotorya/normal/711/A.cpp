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
const int MOD = 1000003;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-11;

char in[1050][10];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%s", in[i]);
	for (i = 0; i < N; i++) {
		if (in[i][0] == 'O' && in[i][1] == 'O') {
			in[i][0] = in[i][1] = '+';
			break;
		}
		if (in[i][3] == 'O' && in[i][4] == 'O') {
			in[i][3] = in[i][4] = '+';
			break;
		}
	}
	if (i >= N) return !printf("NO\n");

	printf("YES\n");
	for (i = 0; i < N; i++) printf("%s\n", in[i]);
	return 0;
}
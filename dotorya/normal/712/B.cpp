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
const db PI = acos(-1);
const ldb ERR = 1E-11;

char in[100050];
int main() {
	int x = 0, y = 0, i;
	scanf("%s", in);
	for (i = 0; in[i] != 0; i++) {
		if (in[i] == 'L') x--;
		if (in[i] == 'R') x++;
		if (in[i] == 'U') y++;
		if (in[i] == 'D') y--;
	}
	if ((x+y)%2) return !printf("-1\n");
	return !printf("%d\n", (abs(x) + abs(y)) / 2);
}
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
const int INF = 1034567891;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-12;

char in1[5];
char in2[5];
int main() {
	scanf("%s", in1);
	scanf("%s", in1 + 2);
	scanf("%s", in2);
	scanf("%s", in2 + 2);
	swap(in1[2], in1[3]);
	swap(in2[2], in2[3]);

	int i, j;
	for (i = 0; i < 4; i++) if (in1[i] == 'A') break;
	for (i = (i + 1) % 4; in1[i] == 'X'; i = (i + 1) % 4);

	char c = in1[i];
	for (i = 0; i < 4; i++) if (in2[i] == 'A') break;
	for (i = (i + 1) % 4; in2[i] == 'X'; i = (i + 1) % 4);
	if (c == in2[i]) printf("YES\n");
	else printf("NO\n");
	return 0;
}
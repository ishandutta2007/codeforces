#include <algorithm>
#include <assert.h>
#include <bitset>
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

int IT_MAX = 1 << 20;
const ll MOD = 98765431;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-6;

string ans[2];

char u1[105];
char u2[105];
int main() {
	int N, i;
	scanf("%s %s", u1, u2);
	ans[0] = string(u1), ans[1] = string(u2);
	printf("%s %s\n", ans[0].c_str(), ans[1].c_str());

	scanf("%d", &N);
	while (N--) {
		scanf("%s %s", u1, u2);
		if (ans[0] == string(u1)) ans[0] = string(u2);
		else ans[1] = string(u2);
		printf("%s %s\n", ans[0].c_str(), ans[1].c_str());
	}
	return 0;
}
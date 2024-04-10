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

char in1[200050];
char in2[200050];
int in[200050];
bool chk[200050];
int main() {
	int L1, L2, i, j;
	scanf("%s %s", in1, in2);
	L1 = strlen(in1), L2 = strlen(in2);

	for (i = 1; i <= L1; i++) {
		scanf("%d", &in[i]);
		in[i]--;
	}

	int st = 1, en = L1, mi, rv = 0;
	while (st <= en) {
		mi = (st + en) / 2;

		for (i = 0; i < L1; i++) chk[i] = false;
		for (i = 1; i <= mi; i++) chk[in[i]] = true;

		for (i = 0, j = 0; i < L1 && j < L2; i++) {
			if (chk[i]) continue;
			if (in1[i] == in2[j]) j++;
		}
		if (j == L2) {
			rv = mi;
			st = mi + 1;
		}
		else en = mi - 1;
	}
	return !printf("%d\n", rv);
}
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
const ldb ERR = 1E-13;

char in[100050];
int main() {
	scanf("%s", in);

	int v = 0, i, L;
	for (i = 0; in[i] != 'e'; i++);
	L = i;
	for (i = L + 1; in[i] != 0; i++) v = (v * 10 + in[i] - '0');

	if (in[L - 1] == '0' && in[L - 2] == '.') {
		printf("%c", in[0]);
		while (v--) printf("0");
		return !printf("\n");
	}
	if (L - 2 > v) {
		for (i = 1; i <= v; i++) swap(in[i], in[i + 1]);
		for (i = 0; in[i] != '.'; i++) if (in[i] != '0') break;
		if (in[i] == '.') i = i - 1;
		for (; i < L; i++) printf("%c", in[i]);
		return !printf("\n");
	}
	if (L - 2 == v) {
		for (i = 1; i <= v; i++) swap(in[i], in[i + 1]);
		for (i = 0; in[i] != '.'; i++) if (in[i] != '0') break;
		if (in[i] == '.') i = i - 1;
		for (; i < L-1; i++) printf("%c", in[i]);
		return !printf("\n");
	}
	if (L - 2 < v) {
		int t = v - L + 2;
		v = L - 2;

		for (i = 1; i <= v; i++) swap(in[i], in[i + 1]);
		for (i = 0; in[i] != '.'; i++) if (in[i] != '0') break;
		if (in[i] == '.') return !printf("0\n");
		for (; i < L - 1; i++) printf("%c", in[i]);
		while (t--) printf("0");
		return !printf("\n");

	}
}
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

char in[100050];

int main() {
	scanf("%s", in);

	int L = strlen(in), i;
	for (i = 0; i < L; i++) if (in[i] != 'a') break;
	if (i == L) {
		in[L - 1] = 'z';
		printf("%s\n", in);
		return 0;
	}

	int st = i;
	for (i = st; i < L; i++) {
		if (in[i] == 'a') break;
		in[i]--;
	}
	return !printf("%s\n", in);
}
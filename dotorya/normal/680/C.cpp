//*
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

int IT_MAX = 4096;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int p[20] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47 }; // count : 15
int main() {
	int n = 0, i;
	char c[10];
	for (i = 0; i < 15; i++) {
		printf("%d\n", p[i]);
		fflush(stdout);
		scanf("%s", c);

		if (c[0] == 'y') {
			if (n == 0) n = p[i];
			else {
				printf("composite\n");
				fflush(stdout);
				return 0;
			}
		}
	}
	
	if (n > 10 || n == 0) {
		printf("prime\n");
		fflush(stdout);
		return 0;
	}
	printf("%d\n", n*n);
	fflush(stdout);
	scanf("%s", c);
	if (c[0] == 'y') printf("composite\n");
	else printf("prime\n");
	fflush(stdout);
	return 0;
}
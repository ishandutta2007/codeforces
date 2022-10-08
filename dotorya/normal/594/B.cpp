//*
#include <algorithm>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <unordered_set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

#define pow10 pasiodfiopsdjviozjxciovjxcviozj
#define pow2 qpowdskopjkcoizxnzoicn

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <char, int> pci;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef pair <db, int> pdi;

int IT_MAX;
const int MOD = 1000;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;

bool isEqual(ldb a, ldb b) {
	return abs(a - b) <= 1E-10;
}
int main() {
	int N, R, V, i, j;
	ldb s, f;
	scanf("%d %d %d", &N, &R, &V);

	for (i = 1; i <= N; i++) {
		cin >> s >> f;
		ldb x = f - s;
		ldb t = (x / (2 * R*PI));
		ldb rt = (ll)(t + 0.5);
		if (isEqual(t, rt)) {
			db ans = (db)(x / V);
			printf("%.20lf\n", ans);
			continue;
		}

		db ans = 0;
		ans += (2 * R*PI*(ll)t) / V;
		t -= (ll)t;

		ldb v = t * 2 * PI;
		ldb st = 0, en = PI, mi;
		for (j = 1; j <= 60; j++) {
			mi = (st + en) / 2;
			if (2 * sin(mi) + 2 * mi >= v) en = mi;
			else st = mi;
		}
		printf("%.20lf\n", (db)((1.0 * (f - s) - 2 * R * sin(mi)) / V));
	}
	return 0;
}
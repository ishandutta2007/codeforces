//*
#include <algorithm>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
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
const int MOD = 1000000;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;

ldb getdis(ldb a, ldb b, ldb c, ldb d) {
	return sqrt((c - a)*(c - a) + (d - b)*(d - b));
}
int main() {
	ldb x1, y1, x2, y2, v, t, vx, vy, wx, wy;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> v >> t;
	cin >> vx >> vy;
	cin >> wx >> wy;

	ldb st = 0, en = INF, mi, rv;
	for (int i = 1; i <= 500; i++) {
		mi = (st + en) / 2;
		ldb tx, ty;
		if (mi <= t) {
			tx = x2 - x1 - mi*vx;
			ty = y2 - y1 - mi*vy;
		}
		else {
			tx = x2 - x1 - t*vx - (mi - t)*wx;
			ty = y2 - y1 - t*vy - (mi - t)*wy;
		}
		if (sqrt(tx*tx + ty*ty) <= v*mi) {
			rv = mi;
			en = mi;
		}
		else st = mi;
	}
	db ans = (db)rv;
	printf("%.20lf", ans);
	return 0;
}
//*/
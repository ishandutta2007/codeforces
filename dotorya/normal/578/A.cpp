//*
#include <algorithm>
#include <ctype.h>
#include <functional>
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

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
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

int IT_MAX;
const int MOD = 9901;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;

int main() {
	int A, B;
	scanf("%d %d", &A, &B);
	if (A == B) return printf("%.20lf", (db)A), 0;
	if (A < B) return printf("-1"), 0;

	int v = A / B - 1;
	db ans = INF;
	if (v >= 2) {
		if (v % 2 == 1) v--;
		ans = min(ans, 1.0*(A - B) / v);
	}

	v = A / B + 1;
	if (v % 2 == 1) v--;
	ans = min(ans, 1.0*(A + B) / v);
	printf("%.20lf", ans);
	
	return 0;
}
//*/
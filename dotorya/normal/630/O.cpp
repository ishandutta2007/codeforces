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

int IT_MAX = 131072;
const int MOD = 100000;
const int INF = 1034567890;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-6;

vector <pdd> V;
int main() {
	ldb px, py, vx, vy, a, b, c, d;
	cin >> px >> py >> vx >> vy >> a >> b >> c >> d;

	ldb t = sqrt(vx*vx + vy*vy);
	vx /= t;
	vy /= t;

	V.push_back(pdd(px + vx*b, py + vy*b));
	V.push_back(pdd(px - vy*a / 2, py + vx*a / 2));
	V.push_back(pdd(px - vy*c / 2, py + vx*c / 2));
	V.push_back(pdd(px - vy*c / 2 - d*vx, py + vx*c / 2 - d*vy));
	V.push_back(pdd(px + vy*c / 2 - d*vx, py - vx*c / 2 - d*vy));
	V.push_back(pdd(px + vy*c / 2, py - vx*c / 2));
	V.push_back(pdd(px + vy*a / 2, py - vx*a / 2));

	pdd v1 = pdd(V[1].first - V[0].first, V[1].second - V[0].second);
	pdd v2 = pdd(V[2].first - V[1].first, V[2].second - V[1].second);

	if (v1.first*v2.second - v2.first*v1.second < 0) reverse(V.begin(), V.end());
	for (auto it : V) printf("%.20lf %.20lf\n", (db)it.first, (db)it.second);
	return 0;
}
#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

db sq(db a) {
	return a*a;
}
bool isValid(int x, db x1, db y1, db x2, db y2) {
	db a = atan2(x1*y2 - x2*y1, x1*x2 + y1*y2);
	db b = 2 * PI / x;

	db c = a / b;
	if (floor(c - 3e-5) != floor(c)) return true;
	if (floor(c + 3e-5) != floor(c)) return true;
	return false;
}
int main() {
	db x1, y1, x2, y2, x3, y3;
	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
	
	db a1 = x2 - x3, b1 = y2 - y3, c1 = (-a1*(x2 + x3) - b1*(y2 + y3)) / 2;
	db a2 = x1 - x3, b2 = y1 - y3, c2 = (-a2*(x1 + x3) - b2*(y1 + y3)) / 2;
	
	db x0 = (-c1*b2 + c2*b1) / (a1*b2 - a2*b1);
	db y0 = (-c1*a2 + c2*a1) / (b1*a2 - b2*a1);

	x1 -= x0, x2 -= x0, x3 -= x0;
	y1 -= y0, y2 -= y0, y3 -= y0;
	
	int i;
	for (i = 3; i <= 100; i++) {
		if (!isValid(i, x1, y1, x2, y2)) continue;
		if (!isValid(i, x1, y1, x3, y3)) continue;
		if (!isValid(i, x2, y2, x3, y3)) continue;
		
		db ans = i * (x1*x1 + y1*y1) / 2;
		ans *= sin(2 * PI / i);
		return !printf("%.20lf\n", ans);
	}
	return 0;
}
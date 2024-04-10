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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

pdd operator + (pdd a, pdd b) {
	return pdd(a.first + b.first, a.second + b.second);
}
pdd operator - (pdd a, pdd b) {
	return pdd(a.first - b.first, a.second - b.second);
}
pdd operator * (db a, pdd b) {
	return pdd(a * b.first, a * b.second);
}

db sq(db a) {
	return a*a;
}
void getv(pdd &p, db &l, pdd n, pdd m, db a, db b) {
	pdd p1 = (1.0 / (a - b)) * (a*m - b*n);
	pdd p2 = (1.0 / (a + b)) * (a*m + b*n);

	p = 0.5 * (p1 + p2);
	l = sqrt(sq(p1.first - p.first) + sq(p1.second - p.second));
}
pdd normalize(pdd x) {
	db s = sqrt(sq(x.first) + sq(x.second));
	return 1 / s * x;
}
db myacos(db a) {
	if (a > 1 + 1e-08) exit(0);
	if (a < -1 - 1e-08) exit(0);
//	printf("%lf\n", a);
	if (a > 1) a = 1;
	if (a < -1) a = -1;
	return acos(a);
}

pdd myrotate(pdd a, db b) {
	return pdd(a.first * cos(b) + a.second*sin(b), -a.first * sin(b) + a.second * cos(b));
}
int main() {
	int x1, y1, r1;
	int x2, y2, r2;
	int x3, y3, r3;
	scanf("%d %d %d %d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2, &x3, &y3, &r3);
	
	if (r1 == r2 && r2 == r3) {
		db a1 = x1 - x2, b1 = y1 - y2, c1 = -a1*(x1 + x2) / 2 - b1*(y1 + y2) / 2;
		db a2 = x1 - x3, b2 = y1 - y3, c2 = -a2*(x1 + x3) / 2 - b2*(y1 + y3) / 2;
		
		db x = -(c1*b2 - c2*b1) / (a1 * b2 - a2*b1);
		db y = -(c1*a2 - c2*a1) / (b1*a2 - b2*a1);
		return !printf("%.20lf %.20lf\n", x, y);
	}

	if (r2 == r3) {
		swap(x1, x3);
		swap(y1, y3);
		swap(r1, r3);
	}
	if (r1 == r3) {
		swap(x2, x3);
		swap(y2, y3);
		swap(r2, r3);
	}

	pdd p1, p2;
	db l1, l2;

	getv(p1, l1, pdd(x1, y1), pdd(x3, y3), r1, r3);
	getv(p2, l2, pdd(x2, y2), pdd(x3, y3), r2, r3);
//	printf("%lf %lf %lf\n", p1.first, p1.second, l1);
//	printf("%lf %lf %lf\n", p2.first, p2.second, l2);

	pdd u = p2 - p1;
	db d = sqrt(sq(u.first) + sq(u.second));
	u = normalize(u);
	db an = myacos((sq(l1) + sq(d) - sq(l2)) / (2 * d * l1));

	pdd a1 = l1 * myrotate(u, an) + p1;
	pdd a2 = l1 * myrotate(u, -an) + p1;

	if (sq(a1.first - x1) + sq(a1.second - y1) < sq(a2.first - x1) + sq(a2.second - y1)) swap(a1, a2);
	return !printf("%.20lf %.20lf\n", a2.first, a2.second);
}
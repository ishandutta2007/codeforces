#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

double yy1, y2, yw, xb, yb, r;

int f(double xw) {
	double ym = yb;
	double xm = 2 * xw - xb;

	double xc = xw;
	double yc = yw - r;

	// yc -> ym, xc -> xm.
	double dy = yc - ym, dx = xc - xm;
	double yy = yw - r - (dy/dx * xc);
	if (yy >= y2 - r) return -1;
	double area = xc * ym + xm * y2 + 0 * yc - yc * xm - ym * 0 - y2 * xc;
	double d = sqrt(S(ym - yc) + S(xc - xm));
	double h = area / d;
	h = fabs(h);
	if (h <= r) return -1;

	if (yy > yy1 + r) return 0;
	return 1;
}

int main() {
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
#endif
	while (scanf("%lf%lf%lf%lf%lf%lf", &yy1, &y2, &yw, &xb, &yb, &r) != EOF) {
		double lo = 0, hi = xb;
		int done = 0;
		for (int i = 0; i < 100; i++) {
			double mid = (lo + hi) / 2.;
			int resp = f(mid);
			if (resp == -1) lo = mid;
			else if (resp == 1) hi = mid;
			else {
				done = 1;
				printf("%.10lf\n", mid);
				break;
			}
		}
		if (!done) printf("-1\n");
		//printf(">>%lf %lf\n", lo, hi);
	}
	return 0;
}
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
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif
	int a, b, c, d;
	while (scanf("%d %d %d %d", &a, &b, &c, &d) != EOF) {
		double p = 1. * a / b;
		double q = 1. * c / d;
		// S = p + (1-p)(1-q)p + ...
		// r = (1 - p)(1 - q)
		// S = p + rp + r^2p + ...
		// S = p(1 + ...) = p / (1 - r)
		double ans = p / (1 - (1 - p)* (1 - q));
		printf("%.10lf\n", ans);
	}
	return 0;
}
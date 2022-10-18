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
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
//typedef long long int LL;
//typedef __int64 LL;

PDD find(PDD A, PDD D) {
	double a = A.first * D.first;
	double b = A.first * D.second;
	double c = A.second * D.first;
	double d = A.second * D.second;
	return PDD( MIN(a, MIN(b, MIN(c, d))),
		        MAX(a, MAX(b, MAX(c, d)))
			);
}

int main()
{
	int a, b, c, d;

	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);

	double lo = 0.0;
	double hi = 1e9 + 2;
	for (int i = 0; i < 100000; i++) {
		double z = (lo + hi) / 2;
		PDD A(a - z, a + z);
		PDD B(b - z, b + z);
		PDD C(c - z, c + z);
		PDD D(d - z, d + z);

		PDD AD = find(A, D);
		PDD BC = find(B, C);

		if (MAX(AD.first, BC.first) <= MIN(AD.second, BC.second)) hi = z;
		else lo = z;
	}

	printf("%.12lf\n", lo);
	return 0;
}
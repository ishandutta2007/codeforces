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
typedef long long int LL;
//typedef __int64 LL;

LL gcd(LL a, LL b) {
	if (a == 0 && b == 0) return 1;
	if (a == 0) return b;
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		LL x, y, p, q;
		scanf("%lld %lld %lld %lld", &x, &y, &p, &q);
		if (p == 0) {
			if (x > 0) printf("-1\n");
			else {
				printf("0\n");
			}
			continue;
		}
		if (p == q) {
			if (x != y) printf("-1\n");
			else printf("0\n");
			continue;
		}

		LL k = (x + p - 1) / p;
		k = MAX(k, (y + q - 1) / q);
		k = MAX(k, (y - x + q - p - 1) / (q - p));
		LL ans = k*q - y;
		printf("%lld\n", ans);
	}
	return 0;
}
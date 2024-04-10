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

int c[200005], d[200005];
int main()
{
	int n;
	scanf("%d", &n);
	int val = 0;
	int lb, ub;
	lb = -1000000000;
	ub = 1000000000;

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &c[i], &d[i]);
		if (d[i] == 1) {
			lb = MAX(lb, 1900 - val);
		}
		else {
			ub = MIN(ub, 1899 - val);
		}
		val += c[i];
	}

	if (lb > ub) {
		printf("Impossible\n");
		return 0;
	}

	val = ub;
	for (int i = 1; i <= n; i++) {
		val += c[i];
	}
	if (val >= 100000000) printf("Infinity\n");
	else printf("%d\n", val);

	return 0;
}
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

double dp[2005][2005];

int main()
{
	int n, t;
	double p;

	scanf("%d %lf %d", &n, &p, &t);

	int tt, nn;

	dp[0][0] = 1.0;
	for(tt = 1; tt <= t; tt++)
		for(nn = 0; nn <= n; nn++)
		{
			if(nn == 0)
				dp[tt][nn] = dp[tt - 1][nn] * (1 - p);
			else if(nn == n)
			{
				dp[tt][nn] = dp[tt - 1][nn] + dp[tt - 1][nn - 1] * p;
			}
			else
				dp[tt][nn] = dp[tt - 1][nn] * (1 - p) + dp[tt - 1][nn - 1] * p;
		}

	double sum = 0;
	for(int i = 0; i <= n; i++)
		sum += i * dp[t][i];
	printf("%.10lf\n", sum);

	return 0;
}
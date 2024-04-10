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

double dp[1003][1003];
int vis[1003][1003];
int m;

double DP(int total, int n, int k)
{
	if(n == 0) return k;

	double &ret = dp[n][k];
	if(vis[n][k]) return ret;
	vis[n][k] = 1;

	ret = 0;

	// next one is of type
	if(k < m)
		ret += (1. * m - k) / total * DP(total - 1, n - 1, k + 1);

	// next one is not of type
	if(total > m - k)
		ret += (1. * total - (m - k)) / total * DP(total - 1, n - 1, k);

	return ret;

}

int main()
{
	int n;

	scanf("%d %d", &n, &m);

	if(n == 1)
	{
		printf("%.10lf\n", 1.0);
		return 0;
	}

	double ans = (DP(n * m - 1, n - 1, 1)) / n;

	printf("%.10lf\n",ans);

	return 0;
}
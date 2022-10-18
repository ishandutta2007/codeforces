#pragma warning(disable:4786)
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
#include<math.h>
#include<stack>
using namespace std;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(X) ((X)>0?(X):(-(X)))
#define S(X) ((X)*(X))
#define D(x1,y1,x2,y2) (sqrt( S((x1)-(x2)) + S((y1)-(y2)) ))
#define EPS 1e-8
#define IN(a,b,c) if(a>=b && a<=c)
#define CLEAR(a) memset(a,0,sizeof(a))
#define in(a,b,c) (a>=b && a<=c)
#define SORT(A) sort(A.begin(),A.end())
#define SZ(X) (int)(X.size())
#define D2(x1,y1,x2,y2) ( S((x1)-(x2)) + S((y1)-(y2)) )

typedef pair<int,int> PII;
typedef __int64 LL;

int dr[]={0,0,1,-1,-1,-1,1,1};
int dc[]={1,-1,0,0,1,-1,1,-1};

double p[2000],dp[2000][2000];
LL arrayL[30], arrayR[30];

LL COUNT(LL a, LL b, LL A, LL B)
{
	a = MAX(a, A);
	b = MIN(b, B);

	if(a > b) return 0;
	return b-a+1;
}

LL count(LL L, LL R)
{
	LL now = 0;
	int i;
	for(i=0;i<=18;i++)
	{
		now += COUNT(L, R, arrayL[i], arrayR[i]);
	}

	return now;
}

int main()
{
	int N, K, i, j;
	LL L, R, cnt;

	arrayL[0]=1;
	arrayR[0]=1;
	for(i=1;i<=18;i++)
	{
		arrayL[i] = arrayL[i-1]*10;
		arrayR[i] = arrayR[i-1]*10+9;
	}

	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%I64d%I64d",&L,&R);
		cnt = count(L,R);

		p[i] = 1.*cnt/(R-L+1);
	}

	dp[0][0]=1;
	for(i=1;i<=N;i++)
		for(j=0;j<=N;j++)
		{
			if(j==0) dp[i][j] = (1-p[i])*dp[i-1][j];
			else dp[i][j] = p[i]*dp[i-1][j-1] + (1-p[i])*dp[i-1][j];
		}

/*	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			dp[i][j] += dp[i][j-1];
*/
	scanf("%d",&K);
	double ans = 0;
	int k;
	for(k=0;k<=N;k++)
	{
		if(N*K <= k*100) ;
		else continue;

		ans += dp[N][k];
	}

	printf("%.14lf\n",ans+1e-15);

	return 0;
}
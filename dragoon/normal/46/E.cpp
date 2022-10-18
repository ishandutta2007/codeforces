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
#define D2(x1,y1,x2,y2) ( S((x1)-(x2)) + S((y1)-(y2)) )
#define EPS 1e-8
#define IN(a,b,c) if(a>=b && a<=c)
#define CLEAR(a) memset(a,0,sizeof(a))

typedef pair<int,int> PII;
//typedef long long LL;
typedef __int64 LL;

//int dr[]={0,-1,-1,-1,0,1,1,1};
//int dc[]={-1,-1,0,1,1,1,0,-1};

int arr[1600][1600];
LL dp[1600][1600];

int main()
{
	LL sofar, ans;
	int n,m,i,j;

	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&arr[i][j]);

	for(i=0;i<n;i++)
		for(j=1;j<m;j++)
			arr[i][j]+=arr[i][j-1];

	for(i=0;i<m;i++)
		dp[0][i]=arr[0][i];

	for(i=1;i<n;i++)
	{
		if(i%2==0)
		{
			sofar=dp[i-1][0];
			for(j=1;j<m;j++)
			{
				sofar=MAX(sofar,dp[i-1][j-1]);
				dp[i][j]=sofar+arr[i][j];				
			}
		}
		else
		{
			sofar=dp[i-1][m-1];
			for(j=m-2;j>=0;j--)
			{
				sofar=MAX(sofar,dp[i-1][j+1]);
				dp[i][j]=sofar+arr[i][j];				
			}
		}
	}

	if(n%2==1)
	{
		ans = dp[n-1][1];
		for(i=1;i<m;i++) ans = MAX(ans, dp[n-1][i]);
	}
	else
	{
		ans = dp[n-1][0];
		for(i=0;i<m-1;i++) ans = MAX(ans, dp[n-1][i]);
	}

	printf("%I64d\n",ans);

	return 0;
}
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

#define S(X) ((X)*(X))
#define MAX(A,B) ((A)>(B)?(A):(B))

struct Target
{
	int x, y;
	__int64 t;
	double p;
};

bool operator<(Target A, Target B)
{
	return A.t < B.t;
}

Target t[1002];
double ans, dp[1002];

int main()
{
	int n,i,j;

	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%I64d%lf",&t[i].x,&t[i].y,&t[i].t,&t[i].p);
	}

	sort(t+1,t+n+1);

	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		dp[i] = t[i].p;

		for(j=1;j<i;j++)
		{
			if( S(t[j].x-t[i].x) + S(t[j].y - t[i].y) <= S(t[i].t-t[j].t) )
				dp[i] = MAX(dp[i], dp[j] + t[i].p);
		}
	}

	ans = 0;
	for(i=1;i<=n;i++) ans = MAX(ans, dp[i]);
	printf("%.14lf\n",ans);

	return 0;
}
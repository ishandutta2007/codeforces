#include<stdio.h>
#include<algorithm>
using namespace std;

#define X(i,j) ((i-1)*m+j)

int ans[10002];

int main()
{
	int n,m,z,now,i,j,flag;

	while(scanf("%d%d",&n,&m)!=EOF)
	{

		if(n<=m)
		{
			z = 1;
			for(now=2;now<=n*m;now+=2)
			{
				ans[now] = z++;
			}

			for(now=1;now<=n*m;now+=2)
			{
				ans[now] = z++;
			}

			flag =1 ;
			for(i=1;i<n;i++)
				for(j=1;j<=m;j++)
					if( ans[X(i,j)] == ans[X(i+1,j)] + 1 || ans[X(i,j)] == ans[X(i+1,j)] - 1)
						flag = 0;

			for(i=1;i<=n;i++)
				for(j=1;j<m;j++)
					if( ans[X(i,j)] == ans[X(i,j+1)] + 1 || ans[X(i,j)] == ans[X(i,j+1)] - 1)
						flag = 0;

			if(flag)
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
				{
					if(j>1) printf(" ");
					printf("%d",ans[(i-1)*m+j]);
				}

				printf("\n");
			}
			else
				printf("-1\n");
		}
		else
		{
			swap(n,m);
			z = 1;
			for(now=2;now<=n*m;now+=2)
			{
				ans[now] = z++;
			}

			for(now=1;now<=n*m;now+=2)
			{
				ans[now] = z++;
			}

			flag =1 ;
			for(i=1;i<n;i++)
				for(j=1;j<=m;j++)
					if( ans[X(i,j)] == ans[X(i+1,j)] + 1 || ans[X(i,j)] == ans[X(i+1,j)] - 1)
						flag = 0;

			for(i=1;i<=n;i++)
				for(j=1;j<m;j++)
					if( ans[X(i,j)] == ans[X(i,j+1)] + 1 || ans[X(i,j)] == ans[X(i,j+1)] - 1)
						flag = 0;

			if(flag)
			for(i=1;i<=m;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(j>1) printf(" ");
					printf("%d",ans[(j-1)*m+i]);
				}

				printf("\n");
			}
			else
				printf("-1\n");

			swap(n,m);
		}

	}

	return 0;
}
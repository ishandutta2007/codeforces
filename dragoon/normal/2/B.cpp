#include<stdio.h>

#define MIN(A,B) ((A)<(B)?(A):(B))

int num[1002][1002];
int p[3][1002][1002], dp[3][1002][1002], count[3][1003][1003];
int n;

int CNT(int a, int p)
{
	if(a==0) return 1000000000;
	int cnt = 0;
	while(a%p==0) a/=p, cnt++;
	return cnt;
}

void DP()
{
	p[0][n-1][n-1] = p[1][n-1][n-1] = -1;
	dp[0][n-1][n-1] = count[0][n-1][n-1];
	dp[1][n-1][n-1] = count[1][n-1][n-1];

	int i, j, k;

	for(i=n-1;i>=0;i--)
		for(j=n-1;j>=0;j--)
			for(k=0;k<2;k++)
			{
				if(i==n-1 && j==n-1) continue;

				dp[k][i][j] = 1000000000;

				if(i+1<n)
				{
					if(dp[k][i+1][j]+count[k][i][j] < dp[k][i][j])
					{
						dp[k][i][j] = dp[k][i+1][j]+count[k][i][j];
						p[k][i][j] = 0;
					}
				}

				if(j+1<n)
				{
					if(dp[k][i][j+1]+count[k][i][j] < dp[k][i][j])
					{
						dp[k][i][j] = dp[k][i][j+1]+count[k][i][j];
						p[k][i][j] = 1;
					}
				}

				if(dp[k][i][j]>1000000000) dp[k][i][j] = 1000000000;
				if(dp[k][i][j]<0) dp[k][i][j] = -1000000000;
			}
}

void PRINT(int r, int c, int k)
{
	if(r==n-1 && c==n-1) {printf("\n"); return;}
	if(p[k][r][c]==0) 
	{
		printf("D");
		PRINT(r+1,c,k);
	}
	else
	{
		printf("R");
		PRINT(r,c+1,k);
	}
}

int main()
{
	scanf("%d",&n);

	int flag, i, j;

	flag = 0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&num[i][j]);
			
			if(num[i][j]==0)
			{
				flag = 1;
			}

			count[0][i][j] = CNT(num[i][j],2);
			count[1][i][j] = CNT(num[i][j],5);
		}

	DP();

	if( MIN(dp[0][0][0], dp[1][0][0]) == 0 )
	{
		printf("0\n");
		if(dp[0][0][0]==0) PRINT(0,0,0);
		else PRINT(0,0,1);

		return 0;
	}

	if(flag)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(num[i][j]==0)
					count[0][i][j]=count[1][i][j] = -1000000000;

		DP();

		printf("1\n");
		PRINT(0,0,0);
		return 0;
	}

	printf("%d\n",MIN(dp[0][0][0],dp[1][0][0]));

	if(dp[0][0][0]<dp[1][0][0]) PRINT(0,0,0);
	else PRINT(0,0,1);

	return 0;
}
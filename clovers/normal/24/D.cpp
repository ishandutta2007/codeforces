#include <bits/stdc++.h>
using namespace std;
const int N=1020;

int n,m;
double dp[N][N],a[N][N];

void init(int li)
{
	a[1][1]=2.0/3.0; a[1][2]=-1.0/3.0; a[1][m+1]=dp[li+1][1]/3.0+1.0;
	a[m][m-1]=-1.0/3.0; a[m][m]=2.0/3.0; a[m][m+1]=dp[li+1][m]/3.0+1.0;
	for(int i=2;i<m;i++) 
	{
		a[i][i]=3.0/4.0;
		a[i][i-1]=-1.0/4.0; a[i][i+1]=-1.0/4.0;
		a[i][m+1]=dp[li+1][i]/4.0+1.0;
	}
}

void Gauss(int li)
{
	init(li);
	for(int i=1;i<m;i++)
	{
		double r=a[i+1][i]/a[i][i];
		for(int j=i-1;j<=i+1;j++) a[i+1][j]-=a[i][j]*r;
		a[i+1][m+1]-=a[i][m+1]*r;
	}
	for(int i=m;i>1;i--) 
	{
		double r=a[i-1][i]/a[i][i];
		a[i-1][m+1]-=r*a[i][m+1]; a[i-1][i]=0;
	}
	for(int i=1;i<=m;i++) dp[li][i]=a[i][m+1]/a[i][i];
}

int main() 
{
	int x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	if(m==1) 
	{
		printf("%.8lf",(n-x)*2.0);
		return 0;
	}
	for(int i=1;i<=m;i++) dp[n][i]=0.0;
	for(int i=n-1;i>=x;i--) Gauss(i);
	printf("%.8lf",dp[x][y]);
	return 0;
}
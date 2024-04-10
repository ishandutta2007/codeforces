#include<bits/stdc++.h>
using namespace std;
const int N=505;
long long dp[N],f[N],d[N][N],fd[N][N],C[N][N];
int n,i,M,m,j,k;
int main()
{
	scanf("%d %d %d",&n,&m,&M);
	f[0]=1;
	for(i=0;i<=n;++i)
	{
		C[i][0]=C[i][i]=1;
		for(j=1;j<i;++j)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
	}
	for(i=1;i<=n;++i)
		for(j=1;j<=i;++j)
		{
			f[i]=(f[i]+f[j-1]*f[i-j]%M*C[i-1][j-1]%M*(i+1))%M;
			int s=0;
			for(k=1;k<=i;++k)
				s+=abs(k-j);
			dp[i]=(dp[i]+dp[j-1]*f[i-j]%M*C[i-1][j-1]%M*(i+1)+f[j-1]*dp[i-j]%M*C[i-1][j-1]%M*(i+1)+s*f[j-1]%M*f[i-j]%M*C[i-1][j-1])%M;
		}
	//cout<<f[m]<<endl;
	fd[0][0]=1;
	for(i=1;i<=n;++i)
		for(j=0;j<=min(m,i);++j)
		{
			fd[i][j]=fd[i-1][j];
			d[i][j]=d[i-1][j];
			for(k=1;k<=j;++k)
			{
				fd[i][j]=(fd[i][j]+(i-k-1>=0?fd[i-k-1][j-k]:1)*f[k]%M*C[j][k])%M;
				d[i][j]=(d[i][j]+((i-k-1>=0?fd[i-k-1][j-k]:1)*dp[k]+(i-k-1>=0?d[i-k-1][j-k]*f[k]:0))%M*C[j][k])%M;
			}
		}
	cout<<(d[n][m]%M+M)%M;
}
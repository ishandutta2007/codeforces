#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int f[2105][2105],n,m,i,j,a[2105][2105],b[2105][2105],sa[2105],sb[2105],ans,s;
int cal(int n,int m)
{
	memset(f,0,sizeof(f));
	memset(sa,0,sizeof(sa));
	memset(sb,0,sizeof(sb));
	int ans=0,s=0;
	f[0][0]=1;
	for(i=0;i<=n;++i)
		for(j=0;j<=m;++j)
		{
			if(i)
				f[i][j]+=f[i-1][j];
			if(j)
				f[i][j]+=f[i][j-1];
			f[i][j]%=M;
		}
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		{
			a[i][j]=1ll*f[i-1][j]*f[n-i][j-1]%M;
			b[i][j]=1ll*f[n-i][m-j+1]*f[i-1][m-j]%M;
		}
	for(i=1;i<m;++i)
	{
		for(j=1;j<=n;++j)
			sa[j]=(sa[j-1]+a[j][i])%M;
		for(j=n;j>=1;--j)
			sb[j]=(sb[j+1]+b[j][i+1])%M;
		for(j=1;j<n;++j)
		{
			ans=(ans+1ll*sa[j]*b[j+1][i+1])%M;
			s=(s+1ll*a[j][i]*b[j+1][i+1])%M;
		}
	}
	return (2*ans%M-s)%M;
}
int main()
{
	scanf("%d %d",&n,&m);
	cout<<((cal(n,m)+cal(m,n))%M+M)%M;
}
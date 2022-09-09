#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,m,i,j,r[2005][2005],d[2005][2005],f[2005][2005][2],mod=1e9+7,s1[2005][2005],s2[2005][2005];
char c[2005][2005];
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,n)
	{
		scanf(" ");
		rep(j,m)
		{
			scanf("%c",&c[i][j]);
		}
	}
	if(n==1&&m==1)
	{
		puts("1");
		return 0;
	}
	for(i=n;i>=1;i--)for(j=m;j>=1;j--)
	{
		if(j==m) r[i][j]=m; else r[i][j]=r[i][j+1]-(c[i][j+1]=='R');
		if(i==n) d[i][j]=n; else d[i][j]=d[i+1][j]-(c[i+1][j]=='R');
	}
	f[1][1][0]=f[1][1][1]=1;
	rep(i,n)rep(j,m)
	{
		(f[i][j][1]+=((s1[i][j]+=s1[i][j-1])%=mod))%=mod;
		(f[i][j][0]+=((s2[i][j]+=s2[i-1][j])%=mod))%=mod;
		(s1[i][j+1]+=f[i][j][0])%=mod;
		(s1[i][r[i][j]+1]-=f[i][j][0])%=mod;
		(s2[i+1][j]+=f[i][j][1])%=mod;
		(s2[d[i][j]+1][j]-=f[i][j][1])%=mod;
	}
	cout<<((f[n][m][0]+f[n][m][1])%mod+mod)%mod<<endl;
	return 0;
}
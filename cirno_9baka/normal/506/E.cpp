#include<bits/stdc++.h>
using namespace std;
const int M=10007;
int n,m,i,j,f[205][205][205],k,dp[205],g[305][305],dp2[205];
int x;
char c[205];
struct str{
	int n,m,a[305][305];
}s,ans,tmp;
str mult(str a,str b)
{
	int i,j,k;
	tmp.n=a.n,tmp.m=b.m;
	for(i=0;i<a.n;++i)
		for(j=i;j<b.m;++j)
		{
			long long s=0;
			for(k=i;k<=j;++k)
				s+=a.a[i][k]*b.a[k][j];
			tmp.a[i][j]=s%M;
		}
	return tmp;
}
void Pow(int n)
{
	while(n)
	{
		if(n&1)
			ans=mult(ans,s);
		s=mult(s,s);
		n>>=1;
	}	
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%s",c+1);
	scanf("%d",&m);
	n=strlen(c+1);
	f[1][n][0]=1;
	for(int len=n-1;len>=0;--len)
		for(i=1;i<=n-len;++i)
		{
			j=i+len;
			if(c[i]==c[j])
			{
				for(k=1;k<=n;++k)
					f[i+1][j-1][k]=(f[i+1][j-1][k]+f[i][j][k-1])%M;
			}
			else
				for(k=0;k<=n;++k)
				{
					f[i+1][j][k]=(f[i+1][j][k]+f[i][j][k])%M;
					f[i][j-1][k]=(f[i][j-1][k]+f[i][j][k])%M;
				}
		}
	for(i=1;i<=n+1;++i)
		for(j=i-1;j>=0&&j>=i-2;--j)
		{
			if(j==i-1)
				for(k=0;k<=n;++k)
					dp[k]=(dp[k]+f[i][j][k])%M;
			if(j==i-2)
				for(k=0;k<=n;++k)
					dp2[k]=(dp2[k]+f[i][j][k])%M;
		}
	x=n/2+1;
	for(i=0;i<x;++i)
	{
		g[i][i+1]=1;
		g[i][i]=25;
	}
	g[x][x]=25;
	g[0][0]=0;
	for(i=x+1;i<=x+n;++i)
	{
		g[i][i+1]=1;
		g[i][i]=24;
	}
	g[x+n+1][x+n+1]=26;
	for(i=0;i<=n/2+1;++i)
		g[i][n+x+1-(n-2*i)]=dp[i];
	for(i=1;i<=n/2+1;++i)
		g[i][n+x-(n-2*i)]+=dp2[i];
	s.n=s.m=n+x+2;
	for(i=0;i<s.n;++i)
		for(j=0;j<s.m;++j)
			s.a[i][j]=g[i][j]%M;
	ans.m=n+x+1;
	ans.n=1;
	ans.a[0][0]=1;
	Pow((m+n+1)/2+1);
	int su=ans.a[0][ans.m-1];
	memset(ans.a,0,sizeof(ans.a));
	if((m+n)&1)
	{
		ans.a[0][0]=1;
		for(i=1;i<=n/2+1;++i)
			g[i][n+x-(n-2*i)]-=dp2[i];
		g[x+n+1][x+n+1]=0;
		for(i=0;i<s.n;++i)
			for(j=0;j<s.m;++j)
				s.a[i][j]=g[i][j]%M;
		Pow((m+n+1)/2+1);
	}
	cout<<(su-ans.a[0][ans.m-1]+M)%M;
}
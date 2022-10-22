#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,dp[101][101][101],z[101],top,f[101];
char s[101];
int fun(int l,int r,int K)
{
	if(l==r)
		return f[z[l]+K];
	if(dp[l][r][K]!=-1)
		return dp[l][r][K];
	dp[l][r][K]=fun(l,r-1,0)+f[z[r]+K];
	for(int i=r-2;i>=l;i-=2)
		dp[l][r][K]=max(dp[l][r][K],fun(l,i,K+z[r])+fun(i+1,r-1,0));
	return dp[l][r][K];
}
signed main()
{
	n=read();
	scanf("%s",s+1);
	memset(dp,-1,sizeof(dp));
	memset(f,-0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;++i)
	{
		int v=read();
		for(int j=i;j<=n;++j)
			f[j]=max(f[j],f[j-i]+v);
	}
	for(int l=1,r;l<=n;l=r+1)
	{
		r=l;
		while(r+1<=n && s[l]==s[r+1])
			++r;
		z[++top]=r-l+1;
		//cout<<top<<" "<<r-l+1<<endl;
	}
	printf("%lld\n",fun(1,top,0));
	return 0;
}
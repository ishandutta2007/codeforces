#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
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
int n,l[301],c[301],ans=0x3f3f3f3f,num[11],cnt,dp[2][1024];
void solve(int sta)
{
	int fb=l[sta];
	cnt=0;
	for(int i=2;i*i<=fb;++i)
		if(fb%i==0)
		{
			num[++cnt]=i;
			while(fb%i==0) fb/=i;
		}
	if(fb!=1) num[++cnt]=fb;
	memset(dp,0x3f,sizeof(dp));
	int bj=0;
	dp[1][(1<<cnt)-1]=c[sta];
	for(int i=1;i<=n;++i,bj^=1)
	{
		if(i==sta)
		{
			bj^=1;
			continue;
		}
		int cstate=0;
		for(int j=1;j<=cnt;++j)
			if(l[i]%num[j]==0)
				cstate|=(1<<j-1);
		memset(dp[bj],0x3f,sizeof(dp[bj]));
		for(int j=0;j<(1<<cnt);++j)
			dp[bj][j]=dp[bj^1][j];
		for(int j=0;j<(1<<cnt);++j)
			dp[bj][j&cstate]=min(dp[bj][j&cstate],dp[bj^1][j]+c[i]);
	}
	ans=min(ans,dp[bj^1][0]);
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) l[i]=read();
	for(int i=1;i<=n;++i) c[i]=read();
	for(int i=1;i<=n;++i) solve(i);
	printf("%d\n",(ans==0x3f3f3f3f?-1:ans));
	return 0;
}
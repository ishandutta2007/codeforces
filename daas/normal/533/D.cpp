#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,dp[2][MAXN],z[MAXN],top,tmp[MAXN][2],z2[MAXN],top2;
ll x[MAXN],d[MAXN],ans=1e18;
int main()
{
	n=read();
	for(int i=0;i<=n+1;++i) x[i]=read();
	for(int i=1;i<=n;++i) d[i]=read();
	d[0]=d[n+1]=1e9;
	memset(tmp,-1,sizeof(tmp));
	for(int i=0;i<=n+1;++i)
	{
		int l=1,r=top,lim=-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(x[i]<=2*d[z[mid]]+dp[0][z[mid]]) lim=mid,l=mid+1;
			else r=mid-1;
		}
		if(lim!=-1) dp[0][i]=x[z[lim]];
		if(2*d[i]>x[i]-dp[0][i])
		{
			tmp[i][0]=top;
			while(top && 2*d[i]+dp[0][i]>=2*d[z[top]]+dp[0][z[top]]) --top;
			tmp[i][1]=z[top+1];
			z[++top]=i;
		}
	}
	if(dp[0][n+1]!=0) {puts("0");return 0;}
	//ans=x[n+1]-x[0];
	dp[1][n+1]=x[n+1];
	for(int i=n+1;i>=0;--i)
	{
		int l=1,r=top2,lim=-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(-x[i]<=2*d[z2[mid]]-dp[1][z2[mid]]) lim=mid,l=mid+1;
			else r=mid-1;
		}
		if(lim!=-1) dp[1][i]=x[z2[lim]];
		if(2*d[i]>dp[1][i]-x[i])
		{
			while(top2 && 2*d[i]-dp[1][i]>=2*d[z2[top2]]-dp[1][z2[top2]]) --top2;
			z2[++top2]=i;
		}
		//---------------
		if(tmp[i][0]!=-1)
		{
			z[top]=tmp[i][1];
			top=tmp[i][0];
		}
		if(2*d[i]>dp[1][i]-x[i])
		{
			l=1,r=top,lim=-1;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(dp[1][i]-2*d[i]<=2*d[z[mid]]+dp[0][z[mid]]) lim=mid,l=mid+1;
				else r=mid-1;
			}
			if(lim!=-1) ans=min(ans,x[i]-x[z[lim]]);
		}
	}
	printf("%.4lf\n",(double)ans/2);
	return 0;
}
//ore no turn,draw!
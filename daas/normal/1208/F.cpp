#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int LOG=21;
const int MAXV=(1<<LOG);
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,dp[2100000][2][2],bj=1,ans,a[1000010];
void change(int v,int p,int z)
{
	if(z>dp[v][bj][0]) dp[v][bj][1]=dp[v][bj][0],dp[v][bj][0]=z;
	else if(z>dp[v][bj][1]) dp[v][bj][1]=z;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		change(a[i],0,i);
	}
	bj=0;
	for(int i=1;i<=LOG;++i,bj^=1)
	{
		for(int j=0;j<MAXV;++j)
		{
			dp[j][bj][0]=dp[j][bj^1][0];
			dp[j][bj][1]=dp[j][bj^1][1];
		}
		for(int j=0;j<MAXV;++j) if(!(j&(1<<i-1)))
		{
			int k=j+(1<<i-1);
			change(j,i,dp[k][bj^1][0]);
			change(j,i,dp[k][bj^1][1]);
		}
	}
	//cerr<<(double)clock()/CLOCKS_PER_SEC<<endl;
	//for(int i=0;i<=15;++i) cout<<i<<" "<<dp[i][bj^1][0]<<" "<<dp[i][bj^1][1]<<endl;
	for(int i=1;i<=n-2;++i)
	{
		int del=0;
		for(int j=LOG;j>=0;--j) if(!(a[i]&(1<<j)))
		{
			if(dp[del+(1<<j)][bj^1][1]>i) del+=(1<<j);
		}
		//cout<<"??? "<<del<<endl;
		ans=max(ans,a[i]+del);
	}
	printf("%d\n",ans);
	return 0;
}
//ore no turn,draw!
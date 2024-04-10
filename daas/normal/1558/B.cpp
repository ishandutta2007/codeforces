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
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,mod,dp[4000010],P[4000010],sum[4000010],prime[300000],cnt,fa[4000010],vis[4000010],ton[4000010],z[25],top;
bool pd[4000010];
inline int MOD(int x) {return x+((x>>31)&mod);}
void dfs(int v,int k,int x)
{
	if(k==top+1)
	{
		if(v!=1)
		{
			//cout<<v<<endl;
			P[x]=MOD(P[x]-dp[(x-1)/v]);
			P[x]=MOD(P[x]+dp[x/v]-mod);
		}
		return;
	}
	for(int j=0;j<=ton[z[k]];++j,v*=z[k]) dfs(v,k+1,x);
}
void solve(int x)
{
	top=0;
	int tmp=x;
	while(x!=1)
	{
		if(vis[fa[x]]!=tmp) vis[fa[x]]=tmp,ton[fa[x]]=0,z[++top]=fa[x];
		++ton[fa[x]];
		x/=fa[x];
	}
	dfs(1,1,tmp);
}
int main()
{
	n=read(),mod=read();
	for(int i=2;i<=n;++i)
	{
		if(!pd[i]) prime[++cnt]=i,fa[i]=i;
		for(int j=1;j<=cnt && (ll)i*prime[j]<=n;++j)
		{
			pd[i*prime[j]]=1;
			fa[i*prime[j]]=prime[j];
			if(i%prime[j]==0) break;
		}
	}
	dp[1]=sum[1]=1;
	for(int i=2;i<=n;++i)
	{
		P[i]=P[i-1];
		//cout<<i<<" "<<P[i]<<endl;
		solve(i);
		dp[i]=MOD(sum[i-1]+P[i]-mod);
		sum[i]=MOD(sum[i-1]+dp[i]-mod);
		//cout<<"?? "<<P[i]<<" "<<dp[i]<<endl;
	}
	printf("%d\n",dp[n]);
	return 0;
}
//ore no turn,draw!
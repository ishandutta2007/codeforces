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
const int MAXN=5e5+10;
const int mod=998244353;
const int inv2=(mod+1)/2;
inline int MOD(int x) {return x+((x>>31)&mod);}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n;
struct node
{
	int head[MAXN],tot;
	int to[MAXN*2],nextn[MAXN*2];
	void ADD(int u,int v)
	{
		to[++tot]=v,nextn[tot]=head[u];
		head[u]=tot;
	}
}Ed;
int ksm(int x,int y)
{
	int z=1;
	while(y)
	{
		if(y&1) z=(ll)z*x%mod;
		x=(ll)x*x%mod;
		y>>=1;
	}
	return z;
}
int dp[MAXN];
void fun(int u,int fa)
{
	dp[u]=1;
	int cnt=0;
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(v==fa) continue;
		fun(v,u);
		++cnt;
		dp[u]=(ll)dp[u]*(1+dp[v])%mod;
	}
	dp[u]=(ll)dp[u]*ksm(inv2,cnt)%mod;
	dp[u]=MOD(1-dp[u]);
}
int main()
{
	n=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		Ed.ADD(u,v);
		Ed.ADD(v,u);
	}
	fun(1,0);
	int ans=0;
	for(int i=1;i<=n;++i) ans=MOD(ans+dp[i]-mod);
	printf("%lld\n",(ll)ksm(2,n)*ans%mod);
	return 0;
}
//ore no turn,draw!
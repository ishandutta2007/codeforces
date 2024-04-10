#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 500000
#define mod 998244353
#define y e[i].to
const int inv2=(mod+1)>>1;
using namespace std;
int n,head[N+5],cnt,ans,f[N+5]/**/;
struct edge
{
	int to,next;
}e[N*2+5];
inline int quick_pow(int x,int b)
{
	int ret=1;
	while(b)
	{
		if(b&1) ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,b>>=1;
	}
	return ret;
}
inline int inv(int x) {return quick_pow(x,mod-2);}
void dfs(int x,int fa)
{
	f[x]=1;
	for(int i=head[x];i;i=e[i].next)
		if(y!=fa) dfs(y,x),f[x]=1ll*f[x]*(1-1ll*inv2*f[y]%mod+mod)%mod;
	ans=(ans+1-f[x]+mod)%mod;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d %d",&u,&v);
		e[++cnt]=(edge){v,head[u]},head[u]=cnt;
		e[++cnt]=(edge){u,head[v]},head[v]=cnt;
	}
	dfs(1,0),printf("%lld",1ll*ans*quick_pow(2,n)%mod);
	return 0; 
}
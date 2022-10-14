//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=1ll*t*t%p) if(y&1) res=1ll*res*t%p;
	return res;
}
int fac[10003],ifac[10003];
inline int C(int n,int m)
{
	return 1ll*fac[n]*ifac[m]%p*ifac[n-m]%p;
}
vector<int> e[10003];
int *f[8003],*g[8003];
int tf[8003],tg[8003],sz[8003];
int n=read();
void dfs(int x,int fa)
{
	f[x]=new int[2],g[x]=new int[2],
	f[x][0]=g[x][0]=sz[x]=1,f[x][1]=g[x][1]=0;
	for(int y:e[x]) if(y!=fa)
	{
		dfs(y,x);
		for(int j=0; j<=sz[x]; ++j)
			for(int k=0; k<=min(n-j,sz[y]); ++k)
			{
				tf[j+k+1]=(tf[j+k+1]+1ll*f[x][j]*f[y][k]%p)%p,
				tg[j+k+1]=(tg[j+k+1]+1ll*f[x][j]*g[y][k]%p)%p,
				tg[j+k+1]=(tg[j+k+1]+1ll*g[x][j]*f[y][k]%p)%p,
				tf[j+k]=(tf[j+k]+1ll*f[x][j]*g[y][k]%p)%p,
				tg[j+k]=(tg[j+k]+1ll*g[x][j]*g[y][k]%p)%p;
			}
		delete f[y],delete g[y];
		sz[x]+=sz[y];
		delete f[x],delete g[x];
		f[x]=new int[sz[x]+1],g[x]=new int[sz[x]+1];
		for(int j=0; j<=sz[x]; ++j)
			f[x][j]=tf[j],tf[j]=0,
			g[x][j]=tg[j],tg[j]=0; 
	}
	return ;
}
int a[8003];
signed main()
{
	fac[0]=ifac[0]=1;
	for(int i=1; i<=n; ++i) fac[i]=1ll*fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	for(int i=1,u,v; i<n; ++i)
		u=read(),v=read(),e[u].push_back(v),e[v].push_back(u);
	dfs(1,1);
	for(int i=0; i+1<n; ++i) a[i]=1ll*g[1][i]*qp(n,n-i-2)%p;
	a[n-1]=1;
	for(int i=0; i<n; ++i)
	{
		ll ans=0;
		for(int j=i; j<n; ++j) 
			if((j-i)&1) ans=(ans+p-1ll*C(j,i)*a[j]%p)%p;
			else ans=(ans+1ll*C(j,i)*a[j]%p)%p;
		printf("%lld ",ans);
	}
	return 0;
}
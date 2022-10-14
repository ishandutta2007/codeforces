// Problem: CF990G GCD Counting
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF990G
// Memory Limit: 250 MB
// Time Limit: 4500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
#define ll long long
int u[200003],v[200003];
vector<int> e[200003];
#define mp make_pair
#define pb push_back
int prim[1000003];
int mu[1000003],cnt=0;
bool vis[1000003];
void init()
{
    mu[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        if(!vis[i]) prim[++cnt]=i,mu[i]=-1;
        for(int j=1; j<=cnt&&prim[j]*i<=1000000; j++)
        {
            vis[prim[j]*i]=1;
            if(i%prim[j]==0) break; 
            else mu[i*prim[j]]=-mu[i];
        }
    }
}
ll cur;
int a[1000003];
int fa[1000003],sz[1000003];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return ;
	cur-=1ll*sz[x]*(sz[x]-1)/2,
	cur-=1ll*sz[y]*(sz[y]-1)/2,
	sz[x]+=sz[y],fa[y]=x,
	cur+=1ll*sz[x]*(sz[x]-1)/2;
	return ;
}
ll ans[200003];
int C[200003];
signed main()
{
	init();
	int n=read();
	for(int i=1; i<=n; ++i) 
	{
		a[i]=read();
		for(int j=1; j*j<=a[i]; ++j)  if(!(a[i]%j)) 
		++C[j],(j*j!=a[i])&&(++C[a[i]/j]);
	}
	for(int i=1,x; i<n; ++i) 
	{
		u[i]=read(),v[i]=read(),x=__gcd(a[u[i]],a[v[i]]);
		for(int j=1; j*j<=x; ++j) 
		if(!(x%j)) e[j].pb(i),e[x/j].pb(i);
	}
	for(int i=1; i<=n; ++i) fa[i]=i,sz[i]=1;
	for(int i=1; i<=200000; ++i)
	{
		cur=C[i];
		vector<int> r;
		for(int j:e[i]) 
			r.pb(u[j]),r.pb(v[j]),
			merge(u[j],v[j]);
		for(int x:r) fa[x]=x,sz[x]=1;
		//printf("%lld\n",cur);
		ans[i]=cur;
	} 
	for(int i=1; i<=200000; ++i)
	{
		ll sum=0;
		for(int j=1; i*j<=200000; ++j) sum+=ans[i*j]*mu[j];
		if(sum) printf("%d %lld\n",i,sum);
	}
	return 0;
}
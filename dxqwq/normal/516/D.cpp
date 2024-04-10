// Problem: CF516D Drazil and Morning Exercise
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF516D
// Memory Limit: 250 MB
// Time Limit: 3500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
#define fi first
#define se second
#define mp make_pair
#define pb push_back
vector<pair<int,int> > e[100003];
int d[100003],f[100003],a[100003],dep[100003],Fa[100003];
void dfs(int x,int fa)
{
	for(auto i:e[x]) if(i.fi!=fa) 
		d[i.fi]=d[x]+i.se,dfs(i.fi,x);
	return ;
}
void dfs1(int x,int fa)
{
	Fa[x]=fa;
	for(auto i:e[x]) if(i.fi!=fa) 
		assert(f[x]<=f[i.fi]),dep[i.fi]=dep[x]+1,dfs1(i.fi,x);
	return ;
}
bool cmp(int x,int y)
{
	return f[x]>f[y]||(f[x]==f[y]&&dep[x]>dep[y]);
}
int fa[100003],sz[100003];
int find(int x)
{
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
signed main()
{
	int n=read();
	for(int i=1,u,v,w; i<n; ++i)
		u=read(),v=read(),w=read(),
		e[u].pb(mp(v,w)),e[v].pb(mp(u,w));
	dfs(1,1);
	int rt=1;
	for(int i=2; i<=n; ++i) (d[rt]<d[i])&&(rt=i);
	memset(d,0,sizeof(d));
	dfs(rt,rt);
	for(int i=1; i<=n; ++i) f[i]=d[i],(d[rt]<d[i])&&(rt=i);
	memset(d,0,sizeof(d));
	dfs(rt,rt);
	for(int i=1; i<=n; ++i) (f[i]<d[i])&&(f[i]=d[i]);
	for(int i=1; i<=n; ++i) (f[i]<f[rt])&&(rt=i);
	dfs1(rt,rt);
	for(int i=1; i<=n; ++i) a[i]=i;
	sort(a+1,a+n+1,cmp);
	// for(int i=1; i<=n; ++i) printf("%lld ",f[a[i]]);
	// puts("");
	for(int T=read();T--;)
	{
		int q=read(),ans=1;
		for(int i=1; i<=n; ++i) fa[i]=i,sz[i]=1;
		for(int l=1,r=0; l<=n; ++l)
		{
			while(r<n&&f[a[l]]-f[a[r+1]]<=q)
			{
				int g=a[++r];
				for(auto i:e[g]) if(i.fi!=Fa[g]) 
					fa[i.fi]=g,sz[g]+=sz[i.fi];
				ans=max(ans,sz[g]);
			}
			--sz[find(a[l])];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
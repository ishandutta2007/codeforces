// Problem: F. MST Unification
// Contest: Codeforces - Codeforces Round #535 (Div. 3)
// URL: https://codeforces.com/contest/1108/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int fa[1000003];
vector<pair<int,int> > e[1000003];
bool ff[1000003];
#define pb(x,y) push_back(make_pair(x,y))
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
struct node
{
	int u,v,w;
	bool operator<(const node&x)const{return w<x.w;}
}a[500003];
int d[500003],f[500003][23];
int dep[500003];
int g[500003][23];
inline void init(int u,int father)
{
	d[u]=d[father]+1,g[u][0]=dep[u]-dep[father];
    for( int i=1; i<=20; i++) f[u][i]=f[f[u][i-1]][i-1],
    g[u][i]=max(g[u][i-1],g[f[u][i-1]][i-1]);
    for(auto p:e[u])
    {
        int v=p.first;
        if(v==father)continue;
        dep[v]=dep[u]+p.second;
        f[v][0]=u,init(v,u);
    }
}
inline int LCA(int x,int y)
{
	int G=-1;
    if(d[x]<d[y])swap(x,y);
    for(int i=20; i>=0; --i)
    {
        if(d[f[x][i]]>=d[y])G=max(G,g[x][i]),x=f[x][i];
        if(x==y)return G;
    }
    for(int i=20; i>=0; --i) if(f[x][i]!=f[y][i])  G=max(g[x][i],G),
    G=max(g[y][i],G),x=f[x][i],y=f[y][i];
    G=max(g[x][0],G);
    G=max(g[y][0],G);
	return G;
}
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=1; i<=m; i++) 
	{
		a[i].u=read(),a[i].v=read();
		a[i].w=read();
	}
	sort(a+1,a+m+1);
	for(int i=1; i<=m; i++)
	{
		int U=find(a[i].u);
		int V=find(a[i].v);
		if(U!=V)
		{
			fa[U]=V;
			e[a[i].u].pb(a[i].v,a[i].w);
			e[a[i].v].pb(a[i].u,a[i].w);
			ff[i]=1;
		}
	}
	f[0][0]=f[1][0];
	init(1,0);
	int ans=0;
	for(int i=1; i<=m; i++) if(!ff[i])
	{
		int D=LCA(a[i].u,a[i].v);
		//printf("%lld %lld %lld %lld\n",a[i].u,a[i].v,a[i].w,D);
		//assert(D<=a[i].w);
		if(D==a[i].w) ++ans;
	}
	printf("%lld\n",ans);
    return 0;
}
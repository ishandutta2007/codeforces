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
const int MAXN=2e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,a[MAXN];
struct node
{
	int head[MAXN],tot;
	int to[MAXN*2],nextn[MAXN*2];
	void ADD(int u,int v)
	{
		to[++tot]=v,nextn[tot]=head[u];
		head[u]=tot;
	}
}Ed,En;
int deep[MAXN],father[MAXN],from[MAXN],vis[MAXN];
void format(int u,int fa)
{
	vis[u]=1;
	deep[u]=deep[fa]+1;
	father[u]=fa;
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(v==fa) continue;
		from[v]=i/2;
		format(v,u);
	}
}
int LCA(int x,int y)
{
	if(deep[x]<deep[y]) swap(x,y);
	while(deep[x]>deep[y]) x=father[x];
	while(x!=y) x=father[x],y=father[y];
	return x;
}
int z[MAXN],top,in[MAXN],dl[MAXN],h,t;
void solve(int x,int y)
{
	int lca=LCA(x,y);
	top=0;
	while(x!=lca) z[++top]=from[x],x=father[x];
	int mem=top;
	while(y!=lca) z[++top]=from[y],y=father[y];
	reverse(z+mem+1,z+top+1);
	for(int i=2;i<=top;++i) En.ADD(z[i-1],z[i]),++in[z[i]];
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	Ed.tot=1;
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=read();
		Ed.ADD(x,y);
		Ed.ADD(y,x);
	}
	for(int i=1;i<=n;++i) if(a[i]!=i && !vis[i]) format(i,0);
	for(int i=1;i<=n;++i) if(a[i]!=i) solve(i,a[i]);
	for(int i=1;i<=m;++i) if(!in[i]) dl[++t]=i;
	while(h!=t)
	{
		int u=dl[++h];
		for(int i=En.head[u];i!=0;i=En.nextn[i])
		{
			int v=En.to[i];
			--in[v];
			if(!in[v]) dl[++t]=v;
		}
	}
	for(int i=1;i<=m;++i) printf("%d ",dl[i]);
	putchar('\n');
	return 0;
}
//ore no turn,draw!
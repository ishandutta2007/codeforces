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
const int MAXN=3010;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,deg[MAXN],dl[MAXN],h,t,deep[MAXN],col[MAXN],jump[MAXN][25],top;
double ans;
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
void format(int u,int fa)
{
	deep[u]=deep[fa]+1;
	jump[u][0]=fa;
	int LOG=log2(deep[u]);
	for(int i=1;i<=LOG;++i) jump[u][i]=jump[jump[u][i-1]][i-1];
	for(int i=En.head[u];i!=0;i=En.nextn[i])
	{
		int v=En.to[i];
		if(v==fa) continue;
		col[v]=col[u];
		format(v,u);
	}
}
int LCA(int x,int y)
{
	if(deep[x]<deep[y]) swap(x,y);
	int C=deep[x]-deep[y],LOG=log2(C);
	for(int i=0;i<=LOG;++i) if(C&(1<<i)) x=jump[x][i];
	if(x==y) return x;
	LOG=log2(deep[x]);
	for(int i=LOG;i>=0;--i) if(jump[x][i]!=jump[y][i]) x=jump[x][i],y=jump[y][i];
	return jump[x][0];
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int u=read()+1,v=read()+1;
		Ed.ADD(u,v);
		Ed.ADD(v,u);
		++deg[u];
		++deg[v];
	}
	for(int i=1;i<=n;++i) if(deg[i]==1) dl[++t]=i;
	while(h!=t)
	{
		int u=dl[++h];
		for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
		{
			int v=Ed.to[i];
			if(deg[v]!=1) En.ADD(v,u);
			--deg[v];
			if(deg[v]==1) dl[++t]=v;
		}
	}
	int st=1;
	while(deg[st]<=1) ++st;
	while(1)
	{
		col[st]=++top;
		format(st,0);
		int flag=0;
		for(int i=Ed.head[st];i!=0;i=Ed.nextn[i])
		{
			int v=Ed.to[i];
			if(deg[v]>1 && !col[v]) {st=v;flag=1;break;}
		}
		if(!flag) break;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j) if(col[i]==col[j])
		{
			int lca=LCA(i,j);
			ans+=1.0/(deep[i]+deep[j]-2*deep[lca]+1);
		}
		else
		{
			int len=deep[i]+deep[j];
			int l1=abs(col[i]-col[j])-1;
			int l2=top-l1-2;
			ans+=1.0/(len+l1)+1.0/(len+l2)-1.0/(len+l1+l2);
		}
	printf("%.6lf\n",ans);
	return 0;
}
//ore no turn,draw
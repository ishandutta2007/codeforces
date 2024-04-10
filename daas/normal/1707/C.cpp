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
const int MAXN=1e5+10;
const int MAXM=2e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,pd[MAXM],ins[MAXM][2];
int father[MAXN];
int find(int k)
{
	if(father[k]!=k) father[k]=find(father[k]);
	return father[k];
}
struct node
{
	int head[MAXN],tot;
	int to[MAXN*2],nextn[MAXN*2],l[MAXN*2];
	void ADD(int u,int v,int _l)
	{
		to[++tot]=v,nextn[tot]=head[u],l[tot]=_l;
		head[u]=tot;
	}
}Ed;
int deep[MAXN],jump[MAXN][22],fa_id[MAXN];
void format(int u,int fa)
{
	deep[u]=deep[fa]+1;
	int LOG=log2(deep[u]);
	jump[u][0]=fa;
	for(int i=1;i<=LOG;++i) jump[u][i]=jump[jump[u][i-1]][i-1];
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(v==fa) continue;
		fa_id[v]=Ed.l[i];
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
int val[MAXN],need;
void push(int u,int fa)
{
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(v==fa) continue;
		val[v]+=val[u];
		push(v,u);
	}
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i) father[i]=i;
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		ins[i][0]=u,ins[i][1]=v;
		int au=find(u),av=find(v);
		if(au!=av)
		{
			father[au]=av;
			pd[i]=1;
			Ed.ADD(u,v,i);
			Ed.ADD(v,u,i);
		}
	}
	format(1,0);
	for(int i=1;i<=m;++i) if(!pd[i])
	{
		++need;
		int u=ins[i][0],v=ins[i][1],lca=LCA(u,v);
		if(lca!=u && lca!=v)
		{
			if(fa_id[u]<i) ++val[u];
			if(fa_id[v]<i) ++val[v];
		}
		else
		{
			if(deep[u]>deep[v]) swap(u,v);
			int x=v,C=deep[v]-deep[u]-1,LOG=log2(C);
			for(int j=0;j<=LOG;++j) if(C&(1<<j)) x=jump[x][j];
			if(fa_id[x]<i)
			{
				++val[1];
				--val[x];
			}
			if(fa_id[v]<i) ++val[v];
		}
	}
	push(1,0);
	for(int i=1;i<=n;++i)
		if(val[i]==need) putchar('1');
		else putchar('0');
	putchar('\n');
	return 0;
}
//tetu no isi to hagane no tuyosa